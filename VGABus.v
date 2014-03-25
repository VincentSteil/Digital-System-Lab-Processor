`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:29:44 03/24/2014 
// Design Name: 
// Module Name:    VGABus 
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
module VGABus(
	 input CLK,
	 input RESET,
	 input [7:0] ADDR,
	 input [7:0] DATA,
	 input  BUS_WE,
	 output [7:0] VGA_COLOUR,
	 output VGA_HS,
	 output VGA_VS
	 
    );

wire [14:0] B_ADDR;
wire B_DATA;
wire DPR_CLK;
reg BUFFER_WE;
reg BUFFER_DATA;
reg [14:0] BUFFER_ADDR;
reg [15:0] CONFIG_COLOURS;

initial BUFFER_ADDR = 15'b0;
initial BUFFER_DATA = 1'b0;
initial BUFFER_WE = 1'b0;

wire [7:0] test;
assign test = 8'hB2;

wire X_ADDR;
wire Y_ADDR;
wire DATA_IN;

assign X_ADDR = (test == 8'hB0) ? 1'b1 : 1'b0;
assign Y_ADDR = (test == 8'hB1) ? 1'b1 : 1'b0;
assign DATA_IN = (test == 8'hB2) ? 1'b1 : 1'b0;

Frame_Buffer FrameBuffer (
    .A_CLK(CLK), 
    .A_ADDR(BUFFER_ADDR), 
    .A_DATA_IN(BUFFER_DATA), 
    .A_WE(BUFFER_WE), 
    .B_CLK(DPR_CLK), 
    .B_ADDR(B_ADDR), 
    .B_DATA(B_DATA)
    );
	 
	 VGA_Sig_Gen SignalGenerator (
    .CLK(CLK), 
    .RESET(RESET), 
    .CONFIG_COLOURS(CONFIG_COLOURS), 
    .DPR_CLK(DPR_CLK), 
    .VGA_ADDR(B_ADDR), 
    .VGA_DATA(B_DATA), 
    .VGA_HS(VGA_HS), 
    .VGA_VS(VGA_VS), 
    .VGA_COLOUR(VGA_COLOUR)
    );
	 
	 always@ (posedge CLK) begin
		 CONFIG_COLOURS[15:8] <= 8'b00110011;
		 CONFIG_COLOURS[7:0] <= 8'b11001100;
		 if (BUS_WE)begin
				if (X_ADDR)
					begin
						BUFFER_ADDR[7:0] <= DATA;
						//BUFFER_ADDR[7:0] <= 8'b01000000;
						BUFFER_WE <= 1'b0; 
					end
				if (Y_ADDR)
						begin
						BUFFER_ADDR[14:8] <= DATA[6:0];
						//BUFFER_ADDR[14:8] <= 7'b1000000;
						BUFFER_WE <= 1'b0; 
						end
				if (DATA)
						begin
						BUFFER_DATA <= DATA[0];
						//BUFFER_DATA <= 1'b1;
						BUFFER_WE <= 1'b1;
						end
			end		
		
	  end	

endmodule
