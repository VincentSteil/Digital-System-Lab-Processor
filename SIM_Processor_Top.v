`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:34:06 03/22/2014
// Design Name:   Processor_Top
// Module Name:   D:/DSL4/Digital-System-Lab-Processor-PS2/SIM_Processor_Top.v
// Project Name:  DSL_Processor
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Processor_Top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module SIM_Processor_Top;

	// Inputs
	reg CLK;
	reg RESET;

	// Outputs
	wire AN0;
	wire AN1;
	wire AN2;
	wire AN3;
	wire CA;
	wire CB;
	wire CC;
	wire CD;
	wire CE;
	wire CF;
	wire CG;
	wire CDP;
	wire [7:0] LEDs;
	wire IR_LED;
   wire S_TIMER_INTERRUPT_RAISE;
	wire S_TIMER_INTERRUPT_ACK;
	wire S_MOUSE_INTERRUPT_RAISE;
	wire S_MOUSE_INTERRUPT_ACK;
   wire [7:0]B_DATA;
    wire [7:0]B_ADDRESS;
    wire [7:0]R_ADDRESS;
    wire [7:0]R_DATA;
    wire [7:0]Current_State;
    wire [7:0]Next_State;
    wire [7:0]Curr_ProgCounter;
    wire [7:0]Next_ProgCounter;
    wire [1:0]Curr_ProgCounterOffset;
    wire [1:0]Next_ProgCounterOffset;
    wire [7:0]Curr_RegA;
    wire [7:0]Curr_RegB;
    wire [7:0]ALU_O;

	// Bidirs
	wire CLK_MOUSE;
	wire DATA_MOUSE;

	// Instantiate the Unit Under Test (UUT)
	Processor_Top uut (
		.CLK(CLK), 
		.RESET(RESET), 
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
		.CDP(CDP), 
		.LEDs(LEDs), 
		.CLK_MOUSE(CLK_MOUSE), 
		.DATA_MOUSE(DATA_MOUSE), 
		.IR_LED(IR_LED),
      //SIM ONLY
      .S_TIMER_INTERRUPT_RAISE(S_TIMER_INTERRUPT_RAISE),
      .S_TIMER_INTERRUPT_ACK(S_TIMER_INTERRUPT_ACK),
      .S_MOUSE_INTERRUPT_RAISE(S_MOUSE_INTERRUPT_RAISE),
      .S_MOUSE_INTERRUPT_ACK(S_MOUSE_INTERRUPT_ACK),
      .B_ADDRESS(B_ADDRESS),
        .B_DATA(B_DATA),
        .R_ADDRESS(R_ADDRESS),
        .R_DATA(R_DATA),
        .Current_State(Current_State),
        .Next_State(Next_State),
        .Curr_ProgCounter(Curr_ProgCounter),
        .Next_ProgCounter(Next_ProgCounter),
        .Curr_ProgCounterOffset(Curr_ProgCounterOffset),
        .Next_ProgCounterOffset(Next_ProgCounterOffset),
        .Curr_RegA(Curr_RegA),
        .Curr_RegB(Curr_RegB),
        .ALU_O(ALU_O)
	);

	initial begin
		// Initialize Inputs
		CLK = 0;
		RESET = 0;

		// Wait 100 ns for global reset to finish
		#100;
        RESET =1;
        #100
        RESET = 0;
		// Add stimulus here
        #1000000000;

	end
    
    always begin
      #10 CLK = ~CLK;
   end

      
endmodule

