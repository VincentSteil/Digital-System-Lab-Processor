`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:02:00 03/07/2014 
// Design Name: 
// Module Name:    RAM 
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
module RAM(
		//standard signals
		input 			CLK,
		//BUS signals
		inout  [7:0]   BUS_DATA,
		input  [7:0] 	BUS_ADDR,
		input  			BUS_WE 		// This signal goes high when the CPU wants to write to the IO device
	);
	
	parameter RAMBaseAddr 	= 0;
	parameter RAMAddrWidth  = 7; // 128 x 8-bits memory
	
	//Tristate
	wire 	[7:0] 		BufferedBusData;
	reg 	[7:0] 		Out;
	reg  					RAMBusWE;
	
	//Only place data on the bus if the processor is NOT writing, and it is addressing this memory
	assign BUS_DATA  			= (RAMBusWE) ? Out : 8'hZZ;
	assign BufferedBusData 	= BUS_DATA;
	
	//Memory
	reg [7:0] Mem [2**RAMAddrWidth-1:0];
	
	// Initialise the memory for data preloading, initialising variables, and declaring constants
	initial  $readmemh("RAM.txt", Mem);

	
	// chip select to determine which IO device is being targetted on the bus
	wire CS;
	assign CS 	= ((BUS_ADDR >= RAMBaseAddr) & (BUS_ADDR < RAMBaseAddr + 128)) ? 1'b1 : 1'b0;
	
	//single port ram
	always@(posedge CLK)
		begin
		
			/*
			This is legacy code from when I simply mapped the memory to the IO device instead of adding the device itself to the bus
			// write mouse data to corresponding reg each cycle
			// must be done synchronously
			Mem[8'hA0]			<= {4'b0,MouseStatus};			
			Mem[8'hA1]			<= MouseX;		
			Mem[8'hA2]			<= MouseY;
			*/
				
			if (CS)
				begin
					if (BUS_WE)
						begin
							Mem[BUS_ADDR[6:0]] <= BufferedBusData;
							RAMBusWE <= 1'b0;
						end
					else
						begin
							RAMBusWE <= 1'b1;					
						end
				end				
			else
				begin
					RAMBusWE <= 1'b0;					
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
		
			Out <= Mem[BUS_ADDR[6:0]];
		end
endmodule