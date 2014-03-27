`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: The University of Edinburgh
// Engineer: Vincent Steil
// 
// Create Date:    11:43:21 03/17/2014 
// Design Name: 
// Module Name:    Processor_Top 
// Project Name: 	 DSD Processor 
// Target Devices: BASYS2 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Processor_Top(
	//Standard Signals
	input  					CLK,
	input  					RESET,
	// Seven Seg Display
	output wire				AN0, AN1, AN2, AN3,
	output wire				CA, CB, CC, CD, CE, CF, CG, CDP,
	// LEDs
	output wire	[7:0]		LEDs,
	// Mouse Serial Connections
	inout		 				CLK_MOUSE,
	inout						DATA_MOUSE,
   //IR LED
   output               IR_LED, 
	/*,
   //SIM ONLY
   output S_TIMER_INTERRUPT_RAISE,
	output S_TIMER_INTERRUPT_ACK,
	output S_MOUSE_INTERRUPT_RAISE,
	output S_MOUSE_INTERRUPT_ACK,
    output [7:0] R_DATA,
    output [7:0]R_ADDRESS,
    output [7:0]B_DATA,
    output [7:0]B_ADDRESS,
    output [7:0]Next_State,
    output [7:0]Current_State,
    output [7:0]Curr_ProgCounter,
    output [7:0]Next_ProgCounter,
    output [1:0]Curr_ProgCounterOffset,
    output [1:0]Next_ProgCounterOffset,
    output [7:0]Curr_RegA,
    output [7:0]Curr_RegB,
    output [7:0]ALU_O*/
	 
	 //VGA signals
	output [7:0] VGA_COLOUR,
	output VGA_HS,
	output VGA_VS

);

	// IO bus initialisations
	wire	[7:0]	BUS_DATA;
	wire	[7:0]	BUS_ADDR;
	wire			BUS_WE;

	// Instruction bus initialisations
	wire	[7:0]	ROM_ADDRESS;
	wire	[7:0]	ROM_DATA;

	// Interrupt line initialisations
//	wire  [1:0] BUS_INTERRUPTS_RAISE;
//	wire 	[1:0] BUS_INTERRUPTS_ACK;
	
	// The following wires and assign statements are needed to stave off the error 108 part-select of scalar wire is illegal
	// This is functionally the same as accessing individual parts of the wire...

	wire 			TIMER_INTERRUPT_RAISE;
	wire			TIMER_INTERRUPT_ACK;
	wire			MOUSE_INTERRUPT_RAISE;
	wire			MOUSE_INTERRUPT_ACK;
	

	/*
	
	SevenSegmentDisplay SevenSegDisplay(
		.CLK(CLK),
		// Anode values
		.AN0(AN0),
		.AN1(AN1),
		.AN2(AN2),
		.AN3(AN3),
		// Cathode Values
		.CA(CA),
		.CB(CB),
		.CC(CC),
		.CD(CD),
		.CE(CE),
		.CF(CF),
		.CG(CG),
		.CDP(CDP),
		// Actual display values
		.DIGIT1(Seven_Seg[15:12]),		
		.DIGIT2(Seven_Seg[11:8]),		
		.DIGIT3(Seven_Seg[7:4]),		
		.DIGIT4(Seven_Seg[3:0])			
	);

	*/
	
	Processor cpu(
		//Standard Signals
		.CLK(CLK),
		.RESET(RESET),
		//BUS Signals
		.BUS_DATA(BUS_DATA),
		.BUS_ADDR(BUS_ADDR),
		.BUS_WE(BUS_WE),
		// ROM signals
		.ROM_ADDRESS(ROM_ADDRESS),
		.ROM_DATA(ROM_DATA),
		// INTERRUPT signals
		.TIMER_INTERRUPT_RAISE(TIMER_INTERRUPT_RAISE),
		.TIMER_INTERRUPT_ACK(TIMER_INTERRUPT_ACK),
		.MOUSE_INTERRUPT_RAISE(MOUSE_INTERRUPT_RAISE),
		.MOUSE_INTERRUPT_ACK(MOUSE_INTERRUPT_ACK)/*,
      //Sim Only Outputs
		.C_state(Current_State),
      .N_state(Next_State),
      .Curr_ProgCounter(Curr_ProgCounter),
      .Next_ProgCounter(Next_ProgCounter),
      .Curr_ProgCounterOffset(Curr_ProgCounterOffset),
      .Next_ProgCounterOffset(Next_ProgCounterOffset),
      .Curr_RegA(Curr_RegA),
      .Curr_RegB(Curr_RegB),
      .ALU_O(ALU_O)*/
	);

	
	// RAM WE only gets enabled when 0 <= ADDR < 128
	RAM mem(
		//standard signals
		.CLK(CLK),
		//BUS signals
		.BUS_DATA(BUS_DATA),
		.BUS_ADDR(BUS_ADDR),
		.BUS_WE(BUS_WE)
	);
	
	
	// Has it's own bus -> modified Harvard architechture
	ROM rom( 
		//standard signals
		.CLK(CLK),
		//BUS signals
		.DATA(ROM_DATA),
		.ADDR(ROM_ADDRESS)
	);
	
	
	
	
	// SevenSeg IO Bus module
	// ADDR space: 0xD0-0xD1
	IO_Bus_SevenSeg SevenSegBus(
		//standard signals
		.CLK(CLK),
		//BUS signals
		.BUS_DATA(BUS_DATA),
		.BUS_ADDR(BUS_ADDR),
		.BUS_WE(BUS_WE),			// This signal goes high when the CPU wants to write to the IO device
		// SevenSeg signals
		.AN0(AN0),
		.AN1(AN1),
		.AN2(AN2),
		.AN3(AN3),
		.CA(CA),
		.CB(CB),
		.CC(CC),
		.CD(CD),
		.CE(CE),
		.CF(CF),
		.CG(CG),
		.CDP(CDP)
	);
	
	
	
	
	// LED IO Bus module
	// ADDR space: 0xC0
	IO_Bus_LEDs LEDsBus(
    //standard signals
		.CLK(CLK),
		//BUS signals
		.BUS_DATA(BUS_DATA),
		.BUS_ADDR(BUS_ADDR),
		.BUS_WE(BUS_WE),		// This signal goes high when the CPU wants to write to the IO device
		// LED signals
		.LEDs(LEDs)
	);
	
	
	
	// Timer IO Bus module
	// ADDR space: 0xF0-0xF3
	// Timer ISR ROM locations stored in ROM{0xFE]
	Timer timer1(
		//standard signals
		.CLK(CLK),
		.RESET(RESET),
		//BUS signals
		.BUS_DATA(BUS_DATA),
		.BUS_ADDR(BUS_ADDR),
		.BUS_WE(BUS_WE),
		.BUS_INTERRUPT_RAISE(TIMER_INTERRUPT_RAISE),
		.BUS_INTERRUPT_ACK(TIMER_INTERRUPT_ACK)
	);

	// Mouse IO Bus module
	// ADDR space: 0xA0-0xA2
	// Mouse ISR ROM location stored in ROM[0xFF] 
	IO_Bus_Mouse MouseBus(
		//standard signals
		.CLK(CLK),
		.RESET(RESET),
		//BUS signals
		.BUS_DATA(BUS_DATA),
		.BUS_ADDR(BUS_ADDR),
		.BUS_WE(BUS_WE),			// This signal goes high when the CPU wants to write to the IO device
		// PS2 serial connections
		.CLK_MOUSE(CLK_MOUSE),
		.DATA_MOUSE(DATA_MOUSE),
		// interrupt signals
		.BUS_INTERRUPT_RAISE(MOUSE_INTERRUPT_RAISE),
		.BUS_INTERRUPT_ACK(MOUSE_INTERRUPT_ACK)
	);
   
   // IR Transmitter IO Bus module
   // ADDR space 0x90 - 0x90
   // 
CarSelect_MainFSM
        CarSelect_MainFSM_0(
//standard signals
        .CLK(CLK),
        .RST(RESET),
//BUS signals
        .BUS_DATA(BUS_DATA),
        .BUS_ADDR(BUS_ADDR),
//output
        .IR_LED(IR_LED)
    );
/*
//SIM assignments
assign S_TIMER_INTERRUPT_RAISE = TIMER_INTERRUPT_RAISE;
assign S_TIMER_INTERRUPT_ACK = TIMER_INTERRUPT_ACK;
assign S_MOUSE_INTERRUPT_RAISE = MOUSE_INTERRUPT_RAISE;
assign S_MOUSE_INTERRUPT_ACK = MOUSE_INTERRUPT_ACK;

   
assign R_DATA = ROM_DATA;
assign R_ADDRESS = ROM_ADDRESS;
assign B_DATA = BUS_DATA;
assign B_ADDRESS = BUS_ADDR;
*/ 

//VGA on bus adress B0 - B2
	VGABus VGAIOBus (
    .CLK(CLK), 
    .RESET(RESET), 
    .ADDR(BUS_ADDR), 
    .DATA(BUS_DATA),
	 .BUS_WE(BUS_WE),	 
    .VGA_COLOUR(VGA_COLOUR), 
    .VGA_HS(VGA_HS), 
    .VGA_VS(VGA_VS)
    );
	 
endmodule
