`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: University of Edinburgh
// Engineer: Vincent Steil
// 
// Create Date:    22:25:34 02/24/2014 
// Design Name: 
// Module Name:    SevenSegmentDisplay 
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
/*
This is a piece of verilog code originally written by BlueSolrac and refactored by myself
For the original, see https://stackoverflow.com/questions/15194206/seven-segment-multiplexing-on-basys2
*/

module SevenSegmentDisplay(
	input 			CLK,
	input [3:0]		DIGIT1, DIGIT2, DIGIT3, DIGIT4,
	output			AN0, AN1, AN2, AN3,
	output			CA, CB, CC, CD, CE, CF, CG, CDP
);


	reg [7:0] 	cathode; //cathode data
	reg [3:0] 	anode; //anode data
	reg [2:0] 	digit = 0;
	reg [3:0] 	data = 0;
	reg 			setdp = 0;
	reg [19:0] 	counter = 0;

	assign CA 	= cathode [7];
	assign CB 	= cathode [6];
	assign CC 	= cathode [5];
	assign CD 	= cathode [4];
	assign CE 	= cathode [3];
	assign CF 	= cathode [2];
	assign CG 	= cathode [1];
	assign CDP 	= cathode [0];
	assign AN3 	= anode [3];
	assign AN2 	= anode [2];
	assign AN1 	= anode [1];
	assign AN0 	= anode [0];


		 //Multiplexing
		 //Board Clock: 50MHz
		 //p = t*f
		 //t = 16ms
		 //p = 16ms * 50*10^6 = 800,000 cycles
		 //200,000 cycles for each digit
		 //Refreshed every 16ms (~60Hz)

	always@(posedge CLK)
	begin
		 if (digit == 0)
			  begin
					if (counter == 200000)
						 begin
							  digit = 1;
						 end
					else
						 begin
						 counter = counter + 1;
						 data = DIGIT1;
						 end
			  end
		 else if (digit == 1)
			  begin
					if (counter == 400000)
						 begin
							  digit = 2;
						 end
					else
						 begin
							  counter = counter + 1;
							  data = DIGIT2;
						 end
			  end
		 else if (digit == 2)
			  begin
					if (counter == 600000)
						 begin
							  digit = 3;
						 end
					else
						 begin
							  counter = counter + 1;
							  data = DIGIT3;
						 end
			  end
		 else if (digit == 3)
			  begin
					if (counter == 800000)
						 begin
							  digit = 0;
							  counter = 0;
						 end 
					else
						 begin
							  counter = counter + 1;
							  data = DIGIT4;
						 end
			  end 
	end


	always @ (*)
	begin

		 case (data)
			  4'h0: cathode = 8'b00000011; //0
			  4'h1: cathode = 8'b10011111; //1
			  4'h2: cathode = 8'b00100101; //2
			  4'h3: cathode = 8'b00001101; //3
			  4'h4: cathode = 8'b10011001; //4
			  4'h5: cathode = 8'b01001001; //5
			  4'h6: cathode = 8'b01000001; //6
			  4'h7: cathode = 8'b00011111; //7
			  4'h8: cathode = 8'b00000001; //8
			  4'h9: cathode = 8'b00001001; //9
			  4'hA: cathode = 8'b00010001; //A
			  4'hb: cathode = 8'b11000001; //B
			  4'hC: cathode = 8'b01100011; //C
			  4'hD: cathode = 8'b10000101; //D
			  4'hE: cathode = 8'b00100001; //E
			  4'hF: cathode = 8'b01110001; //F
			  default: cathode = 8'b11111111; //default all off
		 endcase

		 if (setdp == 1) //decimal point
			  cathode = cathode & 8'hFE;

		 case(digit)
			  4: anode = 4'b1111; //all OFF
			  3: anode = 4'b1110; //AN0
			  2: anode = 4'b1101; //AN1
			  1: anode = 4'b1011; //AN2
			  0: anode = 4'b0111; //AN3
			  default:
			  anode = 4'b1111; //all OFF
		 endcase

	end 
endmodule