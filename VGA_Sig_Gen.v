`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:09:18 02/16/2014 
// Design Name: 	VGA interface
// Module Name:    VGA_Sig_Gen 
// Project Name: 	DSL
// Target Devices: Digilent Basys2
// Tool versions: Xilinx ISE 14.7
// Description: Module to generate VGA driver signal
//
// Dependencies: Generic_Counter
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module VGA_Sig_Gen( 
	 input CLK, 
	 input RESET,
	 //Colour Configuration Interface 
	 input [15:0] CONFIG_COLOURS,
	 
	 // Frame Buffer (Dual Port memory) Interface 
	 output DPR_CLK, 
	 output [14:0] VGA_ADDR, 
	 input VGA_DATA, 
	 //VGA Port Interface 
	 output reg VGA_HS, 
	 output reg VGA_VS, 
	 output [7:0] VGA_COLOUR 
 ); 
 
 
 //Halve the clock to 25MHz to drive the VGA display 
	 reg VGA_CLK; 
	 always@(posedge CLK) begin 
		 if(RESET) 
			VGA_CLK <= 0; 
		 else 
			VGA_CLK <= ~VGA_CLK; 
	 end 
/* 
Define VGA signal parameters e.g. Horizontal and Vertical display time, pulse widths, front and back 
porch widths etc. 
*/  
 // Use the following signal parameters 
	 parameter HTs = 800; // Total Horizontal Sync Pulse Time 
	 parameter HTpw = 96; // Horizontal Pulse Width Time 
	 parameter HTDisp = 640; // Horizontal Display Time 
	 parameter Hbp = 48; // Horizontal Back Porch Time 
	 parameter Hfp = 16; // Horizontal Front Porch Time 
	 
	 parameter VTs = 521; // Total Vertical Sync Pulse Time 
	 parameter VTpw = 2; // Vertical Pulse Width Time 
	 parameter VTDisp = 480; // Vertical Display Time 
	 parameter Vbp = 29; // Vertical Back Porch Time 
	 parameter Vfp = 10; // Vertical Front Porch Time 
	 
// Parameters defining timing values used to calculate address values. Based upon range definition parameters.

	localparam  VertTimeToBackPorchEnd = Vbp + VTpw;
	localparam  VertTimeToDisplayTimeEnd	= VTDisp + VertTimeToBackPorchEnd;
	localparam  VertTimeToFrontPorchEnd = Vfp + VertTimeToDisplayTimeEnd;
	
	localparam  HorzTimeToBackPorchEnd = Hbp + HTpw;
	localparam  HorzTimeToDisplayTimeEnd	= HTDisp + HorzTimeToBackPorchEnd;		
	localparam  HorzTimeToFrontPorchEnd = Hfp + HorzTimeToDisplayTimeEnd; 
 
 // Define Horizontal and Vertical Counters to generate the VGA signals 
 
	reg [9:0] HCounter; 
 
	reg [9:0] VCounter; 
 
/* 
Create a process that assigns the proper horizontal and vertical counter values for raster scan of the 
display. 
*/ 
 
	wire link;
	wire [9:0] countH;
	wire [9:0] countV;
	
	// Instantiate counter to track current horizontal pixel location
	Generic_Counter  #( .COUNTER_MAX(HorzTimeToFrontPorchEnd-1) ) HCounterGen (
	.DIRECTION(1'b0),
   .CLK(CLK), 
   .RESET(RESET), 
   .ENABLE_IN(VGA_CLK), 
   .TRIG_OUT(link), 
   .COUNT(countH)
    );
	 
	// Instantiate counter to track current vertical line location
	Generic_Counter  #( .COUNTER_MAX(VertTimeToFrontPorchEnd-1) ) VCounterGen (
	.DIRECTION(1'b0),	
   .CLK(CLK), 
   .RESET(RESET), 
   .ENABLE_IN(link),  
   .COUNT(countV)
    );
 
 
/* 
Need to create the address of the next pixel. Concatenate and tie the look ahead address to the frame 
buffer address. 
*/ 
 
	 assign DPR_CLK = VGA_CLK; 
	 assign VGA_ADDR = {VCounter[8:2], HCounter[9:2]}; 
 
 
 
/* 
Create a process that generates the horizontal and vertical synchronisation signals, as well as the pixel 
colour information, using HCounter and VCounter. Do not forget to use CONFIG_COLOURS input to 
display the right foreground and background colours. 
*/ 

		// Generate the sync pulses
	always@ (posedge CLK) begin
		if ( countH < HTpw )
			 VGA_HS <= 0;
		else
			 VGA_HS <= 1;
	end
		
  	always@ (posedge CLK) begin		
		if ( countV < VTpw )
			 VGA_VS <= 0;
		else
			 VGA_VS <= 1;	
	end		
	
	 // Set the colour and address values to 0 if out of range
	 reg [15:0] cval;
	 
 	 always@ (posedge CLK) begin
		if ( (countV > VertTimeToBackPorchEnd) && (countV < VertTimeToDisplayTimeEnd) && (countH > HorzTimeToBackPorchEnd) && (countH < HorzTimeToDisplayTimeEnd) ) begin
			 cval <= CONFIG_COLOURS;
			 HCounter <= ( countH - HorzTimeToBackPorchEnd );
			 VCounter <= ( countV - VertTimeToBackPorchEnd );
		end	 
		else begin
			 cval <= 16'h00;
			 HCounter <= 0;
			 VCounter <= 0;			 
		end	 
	 end
	 
 
/* 
Finally, tie the output of the frame buffer to the colour output VGA_COLOUR. 
*/ 

	reg [7:0] colour;
	
  	always@ (posedge CLK) begin		
		if ( VGA_DATA )
			 colour <= cval[7:0];
		else
			 colour <= cval[15:8];	
	end
	
	assign VGA_COLOUR = colour;
 
endmodule