`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:02:00 03/07/2014 
// Design Name: 
// Module Name:    IO_Bus_SevenSeg 
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
module IO_Bus_SevenSeg(
		//standard signals
		input 			CLK,
		//BUS signals
		inout  [7:0]   BUS_DATA,
		input  [7:0] 	BUS_ADDR,
		input  			BUS_WE,			// This signal goes high when the CPU wants to write to the IO device
		// SevenSeg signals
		output			AN0, AN1, AN2, AN3,
		output			CA, CB, CC, CD, CE, CF, CG, CDP
	);


	reg	[15:0]	Seven_Seg;
	
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

	parameter BaseAddr 	= 8'hD0;
	parameter AddrWidth  = 1; 			// 2 x 8-bits memory
	
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
	initial  $readmemh("SevenSeg.txt", Mem);

	// chip select
	wire CS;
	assign CS 	= ((BUS_ADDR >= BaseAddr) & (BUS_ADDR < BaseAddr + 2**AddrWidth)) ? 1'b1 : 1'b0;
	
	//single port ram
	always@(posedge CLK)
		begin
				
			Seven_Seg[7:0] 	<= Mem[0];	
			Seven_Seg[15:8] 	<= Mem[1];
					
				
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