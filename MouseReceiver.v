`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: The University of Edinburgh
// Engineer: Vincent Steil
// 
// Create Date:    17:00:08 18/02/2014 
// Design Name: 
// Module Name:    MouseReceiver 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 	Large ammounts of code were already provided, however
//									that also greatly restricts my coding options
//
//////////////////////////////////////////////////////////////////////////////////
module MouseReceiver(
	//Standard Inputs
	input 				RESET,
	input 				CLK,
	//Mouse IO - CLK
	input 				CLK_MOUSE_IN,
	//Mouse IO - DATA
	input 				DATA_MOUSE_IN,
	//Control
	input 				READ_ENABLE,
	output [7:0] 		BYTE_READ,
	output [1:0] 		BYTE_ERROR_CODE,
	output 				BYTE_READY
);

	//////////////////////////////////////////////////////////
	// Clk Mouse delayed to detect clock edges
	reg ClkMouseInDly;
	always@(posedge CLK)
		ClkMouseInDly <= CLK_MOUSE_IN;
	
	//////////////////////////////////////////////////////////
	//A simple state machine to handle the incoming 11-bit codewords
	reg [2:0] 			Curr_State, Next_State;
	reg [7:0] 			Curr_MSCodeShiftReg, Next_MSCodeShiftReg;
	reg [3:0] 			Curr_BitCounter, Next_BitCounter;
	reg 					Curr_ByteReceived, Next_ByteReceived;
	reg [1:0] 			Curr_MSCodeStatus, Next_MSCodeStatus;
	reg [15:0] 			Curr_TimeoutCounter, Next_TimeoutCounter;
	
	//Sequential
	always@(posedge CLK) 
		begin
			if(RESET) 
				begin
					Curr_State 				<= 0;
					Curr_MSCodeShiftReg 	<= 8'h00;
					Curr_BitCounter 		<= 0;
					Curr_ByteReceived 	<= 1'b0;
					Curr_MSCodeStatus 	<= 2'b00;
					Curr_TimeoutCounter 	<= 0;
				end 
			else 
				begin
					Curr_State 				<= Next_State;
					Curr_MSCodeShiftReg 	<= Next_MSCodeShiftReg;
					Curr_BitCounter 		<= Next_BitCounter;
					Curr_ByteReceived 	<= Next_ByteReceived;
					Curr_MSCodeStatus 	<= Next_MSCodeStatus;
					Curr_TimeoutCounter 	<= Next_TimeoutCounter;
				end
		end
	
	//Combinatorial
	always@* 
		begin
			//defaults to make the State Machine more readable
			Next_State 				= Curr_State;
			Next_MSCodeShiftReg 	= Curr_MSCodeShiftReg;
			Next_BitCounter 		= Curr_BitCounter;
			Next_ByteReceived 	= 1'b0;
			Next_MSCodeStatus 	= Curr_MSCodeStatus;
			Next_TimeoutCounter 	= Curr_TimeoutCounter + 1'b1;
			
			//The states
			case (Curr_State)
				0: 
					begin
						//Falling edge of Mouse clock and MouseData is low i.e. start bit
						if(READ_ENABLE & ClkMouseInDly & ~CLK_MOUSE_IN & ~DATA_MOUSE_IN) 
							begin
								Next_State 						= 1;
								Next_MSCodeStatus 			= 2'b00;
							end
							
						Next_BitCounter 					= 0;
					end
				
				// Read successive byte bits from the mouse here
				1: 
					begin
						if(Curr_TimeoutCounter == 50000) // 1ms timeout
							Next_State 						= 0;
						else if(Curr_BitCounter == 8)
							begin // if last bit go to parity bit check
								Next_State 						= 2;
								Next_BitCounter 				= 0;
							end 
						else if(ClkMouseInDly & ~CLK_MOUSE_IN)
							begin //Shift Byte bits in
								Next_MSCodeShiftReg[6:0] 	= Curr_MSCodeShiftReg[7:1];
								Next_MSCodeShiftReg[7] 		= DATA_MOUSE_IN;
								Next_BitCounter 				= Curr_BitCounter + 1;
								Next_TimeoutCounter 			= 0;
							end
					end
				
				//Check Parity Bit
				2: 
					begin
						//Falling edge of Mouse clock and MouseData is odd parity
						if(Curr_TimeoutCounter == 50000)
							Next_State 						= 0;
						else if(ClkMouseInDly & ~CLK_MOUSE_IN)
							begin
								if (DATA_MOUSE_IN != ~^Curr_MSCodeShiftReg[7:0]) // Parity bit error returns error status on 1
									Next_MSCodeStatus[0] 	= 1'b1;
									
								Next_BitCounter 			= 0;	// redundant, set this way by previous state
								Next_State 					= 3;
								Next_TimeoutCounter 		= 0;
							end
					end
		/*
		Fill in the code for State 3'b011 to detect the Stop bit and set MSCodeStatus [1] accordingly, the final
		State 3'b100, as well as default State
		*/
		/*
		………………..
		FILL IN THIS AREA
		……………….
		*/
				3: 
					begin
						//Falling edge of Mouse clock and MouseData is stop bit
						if(Curr_TimeoutCounter == 100000)
							Next_State 									= 0;
						else if(ClkMouseInDly & ~CLK_MOUSE_IN) 
							begin
								if (DATA_MOUSE_IN) 
									Next_MSCodeStatus[1] 			= 1'b0;	// stop bit should be high
								else
									Next_MSCodeStatus[1] 			= 1'b1;
									
								Next_State 								= 4;
								Next_TimeoutCounter 					= 0;
							end
					end	
				
				4:
					begin // not sure why this state can't be integrated into state 011
						//Falling edge of Mouse clock and MouseData is high i.e. stop bit
						Next_ByteReceived 					= 1'b1;		// set BYTE_READY flag for the master fsm to read the byte	
						Next_State 								= 0;	// GOTO beginning of the FSM
					end
				
				default:
					begin
						// effectively the same as if RESET was set i.e. restarts FSM from ground state if we somehow escape the real states
						Next_State 								= 0;
						Next_MSCodeShiftReg 					= 8'h00;
						Next_BitCounter 						= 0;
						Next_ByteReceived 					= 1'b0;
						Next_MSCodeStatus 					= 2'b00;
						Next_TimeoutCounter 					= 0;	
					end
		
			endcase
		end

	assign BYTE_READY 		= Curr_ByteReceived;
	assign BYTE_READ 			= Curr_MSCodeShiftReg;
	assign BYTE_ERROR_CODE 	= Curr_MSCodeStatus;
	
endmodule
