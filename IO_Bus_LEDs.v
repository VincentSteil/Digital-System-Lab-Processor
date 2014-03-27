`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:54:31 03/17/2014 
// Design Name: 
// Module Name:    IO_Bus_LEDs 
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
module IO_Bus_LEDs(
    //standard signals
		input 			CLK,
		//BUS signals
		inout  [7:0]   BUS_DATA,
		input  [7:0] 	BUS_ADDR,
		input  			BUS_WE,		// This signal goes high when the CPU wants to write to the IO device
		// SevenSeg signals
		output reg [7:0]	LEDs
	);


	parameter BaseAddr 	= 8'hC0;
	
	//Tristate
	wire 	[7:0] 		BufferedBusData;
	reg 	[7:0] 		Out;
	reg  					IOBusWE;
	
	//Only place data on the bus if the processor is NOT writing, and it is addressing this memory
	assign BUS_DATA  			= (IOBusWE) ? Out : 8'hZZ;
	assign BufferedBusData 	= BUS_DATA;
	
	//Memory
	// Only a single byte for this one 2^-1 is may cause issues -> removed
	reg [7:0] Mem;
	
	initial
		Mem = 8'hA0;

	
	wire CS;
	assign CS 	= (BUS_ADDR == BaseAddr) ? 1'b1 : 1'b0; // single byte -> ADDR MUST match
	
	//single port ram
	always@(posedge CLK)
		begin
			
			// Pass through LED values
			LEDs <= Mem;
				
			if (CS)
				begin
					if (BUS_WE)
						begin
							Mem <= BufferedBusData;		
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
		
			Out <= Mem;
		end
endmodule
