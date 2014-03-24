`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: The University of Edinburgh
// Engineer: Vincent Steil
// 
// Create Date:    20:22:07 03/17/2014 
// Design Name: 
// Module Name:    IO_Bus_Mouse 
// Project Name: 
// Target Devices: 
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
module IO_Bus_Mouse(
    	//standard signals
		input 			CLK,
		input				RESET,
		//BUS signals
		inout  [7:0]   BUS_DATA,
		input  [7:0] 	BUS_ADDR,
		input  			BUS_WE,			// This signal goes high when the CPU wants to write to the IO device
		// PS2 serial connections
		inout				CLK_MOUSE,
		inout				DATA_MOUSE,
		// interrupt signals
		output 			BUS_INTERRUPT_RAISE,
		input 			BUS_INTERRUPT_ACK
	);

	wire	[3:0]		MouseStatus;
	wire	[7:0]		MouseX;
	wire	[7:0]		MouseY;


	wire SendInterrupt;

	MouseTransceiver mouse(
		//Standard Inputs
		.RESET(RESET),
		.CLK(CLK),
		//IO - Mouse side
		.CLK_MOUSE(CLK_MOUSE),
		.DATA_MOUSE(DATA_MOUSE),
		// Mouse data information
		.MouseStatus(MouseStatus),	
		.MouseX(MouseX),
		.MouseY(MouseY),
		.SendInterrupt(SendInterrupt)
	);


	//Broadcast the Interrupt
	reg Interrupt;
	
	always@(posedge CLK)
		begin
			if(RESET)
				Interrupt <= 1'b0;
			else if(SendInterrupt)
				Interrupt <= 1'b1;
			else if(BUS_INTERRUPT_ACK)	// clear the interrupt flag on acknowledge by the cpu
				Interrupt <= 1'b0;
		end
		
	assign BUS_INTERRUPT_RAISE = Interrupt; 


	parameter BaseAddr 	= 8'hA0;
	parameter AddrWidth  = 2; 		// 4 x 8-bits memory
	
	//Tristate
	wire 	[7:0] 		BufferedBusData;
	reg 	[7:0] 		Out;
	reg  					IOBusWE;
	
	//Only place data on the bus if the processor is NOT writing, and it is addressing this memory
	assign BUS_DATA  			= (IOBusWE) ? Out : 8'hZZ;
	assign BufferedBusData 	= BUS_DATA;
	
	//Memory
	reg [7:0] Mem [(2**AddrWidth)-1:0];
	
	// Initialise the memory for data preloading, initialising variables, and declaring constants
	initial  $readmemh("Mouse.txt", Mem);

	// chip select
	wire CS;
	assign CS 	= ((BUS_ADDR >= BaseAddr) & (BUS_ADDR < BaseAddr + 2**AddrWidth)) ? 1'b1 : 1'b0;
	

	always@(posedge CLK)
		begin
			
			// Write the mouse signals into the memory locations each cycle
			// Mouse status is only 4 bits long -> concat with 4 0 bits to get the full byte
			Mem[0]	<= {4'b0,MouseStatus};
			Mem[1]	<= MouseX;
			Mem[2]	<=	MouseY;
			
			if (CS)
				begin
					if (BUS_WE)
						begin
							Mem[BUS_ADDR[3:0]] <= BufferedBusData;		// second nibble of the byte gives the IO device and the first gives the subaddress in that device
							IOBusWE <= 1'b0;
						end
					else
						begin
							IOBusWE <= 1'b1;					
						end
				end				
			else
				begin
					IOBusWE <= 1'b0;					
				end

/*			
			// Brute-force RAM address decoding. Think of a simpler way...
			// We could simply use a chip select signal, 
			if((BUS_ADDR >= RAMBaseAddr) & (BUS_ADDR < RAMBaseAddr + 128)) 
				begin
					if(BUS_WE) 
						begin
							Mem[BUS_ADDR[6:0]] <= BufferedBusData;
							RAMBusWE <= 1'b0;
						end
					else
						RAMBusWE <= 1'b1;
				end
			else
				RAMBusWE <= 1'b0;
*/		
		
			Out <= Mem[BUS_ADDR[3:0]];
		end
endmodule