`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: The University of Edinburgh
// Engineer: Vincent Steil
// 
// Create Date:    11:14:34 03/07/2014 
// Design Name: 
// Module Name:    Processor  
// Project Name: 	 DSD Processor 
// Target Devices: BASYS2 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
// TODO: expand ISA and and processor architecture to multiple registers (easier said than done; the whole system was designed for use with only two registers
//////////////////////////////////////////////////////////////////////////////////


module Processor(
	//Standard Signals
	input  			CLK,
	input  			RESET,
	//BUS Signals
	inout  [7:0]  	BUS_DATA,
	output [7:0]  	BUS_ADDR,
	output 			BUS_WE,
	// ROM signals
	output [7:0]  	ROM_ADDRESS,
	input  [7:0]  	ROM_DATA,
	// Interrupt signals	
	input 			TIMER_INTERRUPT_RAISE,
	output			TIMER_INTERRUPT_ACK,
	input				MOUSE_INTERRUPT_RAISE,
	output			MOUSE_INTERRUPT_ACK/*,
   //Simulation only outputs
output [7:0] C_state,
output [7:0] N_state,
output [7:0] Next_ProgCounter,
output [7:0] Curr_ProgCounter,
output [1:0] Curr_ProgCounterOffset,
output [1:0] Next_ProgCounterOffset,
output [7:0] Curr_RegA,
output [7:0] Curr_RegB,
output [7:0] ALU_O*/
);

	//The main data bus is treated as tristate, so we need a mechanism to handle this.
	//Tristate signals that interface with the main state machine
	wire [7:0] BusDataIn;
	reg [7:0] CurrBusDataOut, NextBusDataOut;
	reg CurrBusDataOutWE, NextBusDataOutWE;
	
	//Tristate Mechanism
	assign BusDataIn 		= BUS_DATA;
	assign BUS_DATA 		= CurrBusDataOutWE ? CurrBusDataOut : 8'hZZ;
	assign BUS_WE 			= CurrBusDataOutWE;
	
	//Address of the bus
	reg [7:0] CurrBusAddr, NextBusAddr;
	assign BUS_ADDR 		= CurrBusAddr;
	
	//The processor has two internal registers to hold data between operations, and a third to hold
	//the current program context when using function calls.
	reg [7:0] CurrRegA, NextRegA;
	reg [7:0] CurrRegB, NextRegB;
	reg CurrRegSelect, NextRegSelect;
	reg [7:0] CurrProgContext, NextProgContext;
	
	reg CurrMouseInterruptAck, NextMouseInterruptAck;
	reg CurrTimerInterruptAck, NextTimerInterruptAck;
	
	assign TIMER_INTERRUPT_ACK = CurrTimerInterruptAck;
	assign MOUSE_INTERRUPT_ACK = CurrMouseInterruptAck;
	
	//Instantiate program memory here
	//There is a program counter which points to the current operation. The program counter
	//has an offset that is used to reference information that is part of the current operation
	reg [7:0] CurrProgCounter, NextProgCounter;
	reg [1:0] CurrProgCounterOffset, NextProgCounterOffset;
	wire [7:0] ProgMemoryOut;
	wire [7:0] ActualAddress;
	assign ActualAddress = CurrProgCounter + CurrProgCounterOffset;
	

	// ROM signals
	assign ROM_ADDRESS = ActualAddress;
	assign ProgMemoryOut = ROM_DATA;
	
	//Instantiate the ALU
	//The processor has an integrated ALU that can do several different operations
	wire 	[7:0] AluOut;
	ALU ALU0(
	//standard signals
	.CLK(CLK),
	.RESET(RESET),
	//I/O
	.IN_A(CurrRegA),
	.IN_B(CurrRegB),
	.ALU_Op_Code(ProgMemoryOut[7:4]),
	.OUT_RESULT(AluOut)
	);
	
	//The microprocessor is essentially a state machine, with one sequential pipeline
	//of states for each operation.
	//The current list of operations is:
	// 0: Read from memory to A
	// 1: Read from memory to B
	// 2: Write to memory from A
	// 3: Write to memory from B 
	// 4: Do maths with the ALU, and save result in reg A
	// 5: Do maths with the ALU, and save result in reg B
	// 6: if A (== or < or > B) GoTo ADDR
	// 7: Goto ADDR
	// 8: Go to IDLE
	// 9: End thread, goto idle state and wait for interrupt.
	// 10: Function call
	// 11: Return from function call
	// 12: Dereference A
	//13: Dereference B
	
	parameter [7:0] //Program thread selection
	IDLE  										= 8'hF0, //Waits here until an interrupt wakes up the processor.
	GET_THREAD_START_ADDR_0 				= 8'hF1, //Wait.
	GET_THREAD_START_ADDR_1 				= 8'hF2, //Apply the new address to the program counter.
	GET_THREAD_START_ADDR_2 				= 8'hF3, //Wait. Goto ChooseOp.
	//Operation selection
	//Depending on the value of ProgMemOut, goto one of the instruction start states.
	CHOOSE_OPP 									= 8'h00,
	//Data Flow
	READ_FROM_MEM_TO_A  						= 8'h10, //Wait to find what address to read, save reg select.
	READ_FROM_MEM_TO_B  						= 8'h11, //Wait to find what address to read, save reg select.
	READ_FROM_MEM_0  							= 8'h12, //Set BUS_ADDR to designated address.
	READ_FROM_MEM_1  							= 8'h13, //wait - Increments program counter by 2. Reset offset.
	READ_FROM_MEM_2  							= 8'h14, //Writes memory output to chosen register, end op.
	LOAD_IMMEDIATE_TO_A						= 8'h15,
	LOAD_IMMEDIATE_TO_A_0					= 8'h16,
	LOAD_IMMEDIATE_TO_B						= 8'h17,
	LOAD_IMMEDIATE_TO_B_0					= 8'h18,
	WRITE_TO_MEM_FROM_A  					= 8'h20, //Reads Op+1 to find what address to Write to.
	WRITE_TO_MEM_FROM_B  					= 8'h21, //Reads Op+1 to find what address to Write to.
	WRITE_TO_MEM_0  							= 8'h22, //wait - Increments program counter by 2. Reset offset.
	//Data Manipulation
	DO_MATHS_OPP_SAVE_IN_A  				= 8'h30, //The result of maths op. is available, save it to Reg A.
	DO_MATHS_OPP_SAVE_IN_B  				= 8'h31, //The result of maths op. is available, save it to Reg B.
	DO_MATHS_OPP_0  							= 8'h32, //wait for new op address to settle. end op.
	/* 
	Complete the above parameter list for In/Equality, Goto Address, Goto Idle, function start, Return from
	function, and Dereference operations.
	*/
	/*
	..
	FILL IN THIS AREA
	.
	*/
	
	// Given the way the timer and mouse devices are handled, we aren't dealing with actual interrupts in this case
	// ISR's are only called from IDLE state. There is no way to get out of the IDLE state without going to either ISR
	// That means that we can initialise, but can't run the classic while(1){do stuff} main thread
	// Everything will have to be done in the ISR's
	// TODO (only if it benifits the final use case, otherwise we're just adding unnecessary complexity:
	//			 	add real ISR functionality
	//				expand registers to more than 2 (requires complete ISR revamp and things like mov instructions
	
	
	IF_A_EQUALITY_B_GOTO						= 8'h40,	// Branch on conditional result of ALU (all conditionals)
	IF_A_EQUALITY_B_GOTO_0					= 8'h41,	// Set new PC -> PC + 2 on fail and PC = ADDR on success
	IF_A_EQUALITY_B_GOTO_1					= 8'h42,	// Wait for new op address to settle
	//IF_A_EQUALITY_B_GOTO_2					= 8'h43,
	
	GOTO											= 8'h50,	// Go to function at next PC location
	GOTO_0										= 8'h51,
	GOTO_1										= 8'h52,
	//GOTO_2										= 8'h53,
   GOTO_IDLE                           = 8'h54,

	FUNCTION_CALL								= 8'h60,
	RETURN										= 8'h61,
	//RETURN_0										= 8'h62,
	
	DE_REFERENCE_A								= 8'h70,
	DE_REFERENCE_B								= 8'h71,
   DE_REFERENCE_0                      = 8'h72,
   
	//DO_MATHS_OPP_1  							= 8'h33,

	
	//WRITE_TO_MEM_1								= 8'h23,
	//WRITE_TO_MEM_2								= 8'h24,
	//WRITE_TO_MEM_3								= 8'h25,
	//WRITE_TO_MEM_4								= 8'h26,
	
	//READ_FROM_MEM_3  							= 8'h15,
	//READ_FROM_MEM_4  							= 8'h16,
   //No Operation -moves program counter forwards by one address
   NO_OP                               = 8'h84;          
	
	
	//Sequential part of the State Machine.
	reg [7:0] CurrState, NextState;
		

	always@(posedge CLK) begin
		if(RESET) begin
			CurrState  					= 8'h00;
			CurrProgCounter  			= 8'h00;
			CurrProgCounterOffset 	= 2'h0;
			CurrBusAddr  				= 8'hFF; //Initial instruction after reset.
			CurrBusDataOut 			= 8'h00;
			CurrBusDataOutWE  		= 1'b0;
			CurrRegA  					= 8'h00;
			CurrRegB  					= 8'h00;
			CurrRegSelect 				= 1'b0;
			CurrProgContext  			= 8'h00;
			CurrMouseInterruptAck  	= 0;
			CurrTimerInterruptAck  	= 0;
		
		end else begin
			CurrState  					= NextState;
			CurrProgCounter  			= NextProgCounter;
			CurrProgCounterOffset 	= NextProgCounterOffset;
			CurrBusAddr  				= NextBusAddr;
			CurrBusDataOut 			= NextBusDataOut;
			CurrBusDataOutWE  		= NextBusDataOutWE;
			CurrRegA  					= NextRegA;
			CurrRegB  					= NextRegB; 
			CurrRegSelect 				= NextRegSelect;
			//NextMouseInterruptAck  	= CurrMouseInterruptAck;
			//NextTimerInterruptAck  	= CurrTimerInterruptAck;
         CurrMouseInterruptAck = NextMouseInterruptAck;
         CurrTimerInterruptAck = NextTimerInterruptAck;
         CurrProgContext = NextProgContext;//need to add this for FUNCTION CALL to work. 
		end
	end
	
	//Combinatorial section - large!
	always@* begin
		//Generic assignment to reduce the complexity of the rest of the S/M
		NextState  						= CurrState;
		NextProgCounter  				= CurrProgCounter;
		NextProgCounterOffset 		= 2'h0;
		NextBusAddr  					= 8'hFF;//changed from CurrBusAddr
		NextBusDataOut 				= CurrBusDataOut;
		NextBusDataOutWE  			= 1'b0;
		NextRegA  						= CurrRegA;
		NextRegB  						= CurrRegB;
		NextRegSelect 					= CurrRegSelect;
		NextProgContext  				= CurrProgContext;
		NextMouseInterruptAck  		= 0;
		NextTimerInterruptAck  		= 0;
		
		//Case statement to describe each state
		case (CurrState)
			//Thread states.
			IDLE:  
				begin
					if(MOUSE_INTERRUPT_RAISE) 
						begin // Interrupt Request A.
							NextState 					= GET_THREAD_START_ADDR_0;
							NextProgCounter  			= 8'hFF;
							NextMouseInterruptAck  	= 1;
						end 
					else if(TIMER_INTERRUPT_RAISE) 
						begin //Interrupt Request B.
							NextState  					= GET_THREAD_START_ADDR_0;
							NextProgCounter  			= 8'hFE;
							NextTimerInterruptAck  	= 1;
						end 
					else 
						begin
							NextState  					= IDLE;
							NextProgCounter  			= 8'hFF; //Nothing has happened.
							NextMouseInterruptAck  	= 0;
							NextTimerInterruptAck  	= 0;
						end
				end
			
			//Wait state - for new prog address to arrive.
			GET_THREAD_START_ADDR_0: 
				begin
					NextState  					= GET_THREAD_START_ADDR_1;
				end
			
			//Assign the new program counter value
			GET_THREAD_START_ADDR_1: 
				begin
					NextState 					= GET_THREAD_START_ADDR_2;
					NextProgCounter  			= ProgMemoryOut;
				end
			
			//Wait for the new program counter value to settle
			GET_THREAD_START_ADDR_2:
				NextState  						= CHOOSE_OPP;
				
			///////////////////////////////////////////////////////////////////////////////////////
			//CHOOSE_OPP - Another case statement to choose which operation to perform
			CHOOSE_OPP: 
				begin
					case (ProgMemoryOut[3:0])
						4'h0: NextState = READ_FROM_MEM_TO_A;
						4'h1: NextState = READ_FROM_MEM_TO_B;
						4'h2: NextState = WRITE_TO_MEM_FROM_A;
						4'h3: NextState = WRITE_TO_MEM_FROM_B;
						4'h4: NextState = DO_MATHS_OPP_SAVE_IN_A;
						4'h5: NextState  = DO_MATHS_OPP_SAVE_IN_B;
						4'h6: NextState  = IF_A_EQUALITY_B_GOTO;
						4'h7: NextState = GOTO;
						4'h8: NextState  = IDLE;
						4'h9: NextState  = FUNCTION_CALL;
						4'hA: NextState  = RETURN;
						4'hB: NextState  = DE_REFERENCE_A;
						4'hC: NextState  = DE_REFERENCE_B;
                  4'hD:NextState  = NO_OP;
						4'hE:NextState  = LOAD_IMMEDIATE_TO_A;
						4'hF:NextState  = LOAD_IMMEDIATE_TO_B;
						default:
						NextState 				= CurrState;
					endcase
					NextProgCounterOffset 	= 2'h1;
				end
         ///////////////////////////////////////////////////////////////////////////////////////
    //READ_FROM_MEM_TO_A : here starts the memory read operational pipeline.
    //Wait state - to give time for the mem address to be read. Reg select is set to 0
    READ_FROM_MEM_TO_A:begin
        NextState = READ_FROM_MEM_0;
        NextRegSelect = 1'b0;
    end
    //READ_FROM_MEM_TO_B : here starts the memory read operational pipeline.
    //Wait state - to give time for the mem address to be read. Reg select is set to 1
    READ_FROM_MEM_TO_B:begin
        NextState = READ_FROM_MEM_0;
        NextRegSelect = 1'b1;
    end
    //The address will be valid during this state, so set the BUS_ADDR to this value.
    READ_FROM_MEM_0: begin
        NextState = READ_FROM_MEM_1;
        NextBusAddr = ProgMemoryOut;
    end
    //Wait state - to give time for the mem data to be read
    //Increment the program counter here. This must be done 2 clock cycles ahead
    //so that it presents the right data when required.
    READ_FROM_MEM_1: begin
        NextState = READ_FROM_MEM_2;
        NextProgCounter = CurrProgCounter + 2;
    end
    //The data will now have arrived from memory. Write it to the proper register.
    READ_FROM_MEM_2: begin
        NextState = CHOOSE_OPP;
        if(!CurrRegSelect)
            NextRegA = BusDataIn;
        else
            NextRegB = BusDataIn;
    end
	 
	//Wait for program data
	 LOAD_IMMEDIATE_TO_A:begin
        NextState = LOAD_IMMEDIATE_TO_A_0;
		  NextProgCounter = CurrProgCounter + 2;
    end
	 
	 //set Reg A to program data out
	  LOAD_IMMEDIATE_TO_A_0: begin
        NextState = CHOOSE_OPP;
        NextRegA = ProgMemoryOut;
    end
	 
	 //Wait for program data
	 LOAD_IMMEDIATE_TO_B:begin
        NextState = LOAD_IMMEDIATE_TO_B_0;
		  NextProgCounter = CurrProgCounter + 2;
    end
	 
	 //set Reg B to program data out
	  LOAD_IMMEDIATE_TO_B_0: begin
        NextState = CHOOSE_OPP;
        NextRegB = ProgMemoryOut;
    end
	 
    ///////////////////////////////////////////////////////////////////////////////////////
    //WRITE_TO_MEM_FROM_A : here starts the memory write operational pipeline.
    //Wait state - to find the address of where we are writing
    //Increment the program counter here. This must be done 2 clock cycles ahead
    //so that it presents the right data when required.
    WRITE_TO_MEM_FROM_A:begin
        NextState= WRITE_TO_MEM_0;
        NextRegSelect= 1'b0;
        NextProgCounter = CurrProgCounter + 2;
    end
    //WRITE_TO_MEM_FROM_B : here starts the memory write operational pipeline.
    //Wait state - to find the address of where we are writing
    //Increment the program counter here. This must be done 2 clock cycles ahead
    // so that it presents the right data when required.
    WRITE_TO_MEM_FROM_B:begin
        NextState = WRITE_TO_MEM_0;
        NextRegSelect = 1'b1;
        NextProgCounter = CurrProgCounter + 2;
    end
    //The address will be valid during this state, so set the BUS_ADDR to this value,
    //and write the value to the memory location.
    WRITE_TO_MEM_0:begin
        NextState = CHOOSE_OPP;
        NextBusAddr = ProgMemoryOut;
        if(!NextRegSelect)
            NextBusDataOut = CurrRegA;
        else
            NextBusDataOut = CurrRegB;
            
        NextBusDataOutWE = 1'b1;
    end   
            
			///////////////////////////////////////////////////////////////////////////////////////
			//DO_MATHS_OPP_SAVE_IN_A : here starts the DoMaths operational pipeline.
			//Reg A and Reg B must already be set to the desired values. The MSBs of the
			// Operation type determines the maths operation type. At this stage the result is
			// ready to be collected from the ALU.
			DO_MATHS_OPP_SAVE_IN_A: 
				begin
					NextState 					= DO_MATHS_OPP_0;
					NextRegA  					= AluOut;
					NextProgCounter 			= CurrProgCounter + 1;
				end
			
			//DO_MATHS_OPP_SAVE_IN_B : here starts the DoMaths operational pipeline
			//when the result will go into reg B.
			DO_MATHS_OPP_SAVE_IN_B:  
				begin
					NextState 					= DO_MATHS_OPP_0;
					NextRegB  					= AluOut;
					NextProgCounter 			= CurrProgCounter + 1;
				end
			
			//Wait state for new prog address to settle.
			DO_MATHS_OPP_0: 
				begin
					NextState 					= CHOOSE_OPP;
				end	
	
			//Wait state - to give time for the mem address to be read.
			// ALU out is assigned combinatorially with the ALU op code coming from the rom.
			// Thus we need to store the fact that we branch or not, lest we base our decision on a memory location value not the real instruction
   ///////////////////////////////////////////////////////////////////////////////////////
   //IF_A_EQUALITY_B_GOTO: here starts the conditional jump operation
   IF_A_EQUALITY_B_GOTO: begin   //Conditional Jump
         if(AluOut) 
            NextState = IF_A_EQUALITY_B_GOTO_0;
         else begin
            NextState = IF_A_EQUALITY_B_GOTO_1;
            NextProgCounter = CurrProgCounter + 2;
         end   
   end
   //IF_A_EQUALITY_B_GOTO_0: here starts the conditional jump operation pipeline
   //in this state the address that has to be jumped to is loaded 
   IF_A_EQUALITY_B_GOTO_0:begin
      NextProgCounter = ProgMemoryOut; 
      NextState = IF_A_EQUALITY_B_GOTO_1;
   end
   //IF_A_EQUALITY_B_GOTO_1: continued pipleine for conditional jump
   //wait state - now the next instruction will be fetched with the next state
   IF_A_EQUALITY_B_GOTO_1:begin
      NextState = CHOOSE_OPP;
   end
   
   ///////////////////////////////////////////////////////////////////////////////////////
   //GOTO: here begins the unconditional jump operation
   GOTO: begin   
         NextState = GOTO_0;
         NextProgCounter = CurrProgCounter + 2;         
   end
   //GOTO_0: in this state the address that has to be jumped to is loaded 
   GOTO_0:begin
      NextProgCounter = ProgMemoryOut; 
      NextState = GOTO_1;
   end
   //wait state - now the next instruction will be fetched with the next state
   GOTO_1:begin
      NextState = CHOOSE_OPP;
   end
   
   ///////////////////////////////////////////////////////////////////////////////////////
   //GOTO_IDLE : the goto Idle op is completed just here
   GOTO_IDLE : begin
      NextState = IDLE;
      NextProgCounterOffset = 2'h0;
      NextProgCounter = 8'h00;
   end
   
   ///////////////////////////////////////////////////////////////////////////////////////
   //FUNCTION_START: here starts the function call op
   FUNCTION_CALL: begin
      NextProgContext = CurrProgCounter +2; //save address for return ROM
      NextState = GOTO_0; 
   end
   ///////////////////////////////////////////////////////////////////////////////////////
   //RETURN: simply a return statement ,loading the saved program context at function call
   RETURN: begin
      NextProgCounter = CurrProgContext;
      NextState = CHOOSE_OPP; 
   end
   
		
			// Dereference the pointer to memory stored in A and save the value of mem[A] in A
			DE_REFERENCE_A:
				begin
					NextState  					= DE_REFERENCE_0;
					NextBusAddr					= CurrRegA;
					NextRegSelect 				= 1'b0;
				end
				
			// Dereference the pointer to memory stored in B and save the value of mem[B] in B	
			DE_REFERENCE_B:
				begin
					NextState  					= DE_REFERENCE_0;
					NextBusAddr					= CurrRegB;
					NextRegSelect 				= 1'b1;
				end
				
         //wait state in which the next program counter address is set
         DE_REFERENCE_0: begin
            NextState = READ_FROM_MEM_2;
            NextProgCounter = CurrProgCounter + 1;
         end   
			
         ///////////////////////////////////////////////////////////////////////////////////////
    //NO_OP : Simply move the program counter forward by one address
    NO_OP:begin
        NextState = CHOOSE_OPP;
        NextProgCounter = CurrProgCounter+1;
        //NextProgCounterOffset = 2'h0;
    end
			
			
		endcase 
	end
   /*
   //SIM only
assign C_state = CurrState;
assign N_state = NextState;
assign Next_ProgCounter = NextProgCounter;
assign Curr_ProgCounter = CurrProgCounter;
assign Curr_ProgCounterOffset = CurrProgCounterOffset;
assign Next_ProgCounterOffset = NextProgCounterOffset;
assign Curr_RegA = CurrRegA;
assign Curr_RegB = CurrRegB;
assign ALU_O = AluOut;*/
endmodule
