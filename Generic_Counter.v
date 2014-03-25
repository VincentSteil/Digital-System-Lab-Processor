`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:22:46 02/16/2014 
// Design Name: 
// Module Name:    Generic_Counter 
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
module Generic_Counter(CLK,
							 RESET,
							 ENABLE_IN,
							 TRIG_OUT,
							 COUNT,
							 DIRECTION
							 );
	 // Set the maximum counter value, and the width (in bits) of the output. Width must be large enough to hold the maximum counter value.
	 parameter COUNTER_WIDTH = 10;
	 parameter COUNTER_MAX = 0;

	 input DIRECTION;
	 input CLK;
	 input RESET;
	 input ENABLE_IN;
	 output TRIG_OUT;
	 output [COUNTER_WIDTH-1:0] COUNT;
	 
	 //Declare the registers that hold the Counter and TriggerOut values between clock cycles
	 reg [COUNTER_WIDTH-1:0] Counter;
	 reg TriggerOut;
	 
	 //Synchronous Counter logic
	 always@(posedge CLK or posedge RESET) begin
		if (RESET)
			Counter <= 0;
		else begin
			if (ENABLE_IN) begin
				if (DIRECTION == 0) begin
					if  (Counter == COUNTER_MAX) begin 
						Counter <= 0;
					end	
					else
						Counter <= Counter + 1;	
				end
				else begin
					if  (Counter == 0) begin 
						Counter <= COUNTER_MAX;
					end	
					else
						Counter <= Counter - 1;	
				end		
			end		
		end
	end
	
		//Synchronous Trigger Out logic

	 always@(posedge CLK or posedge RESET) begin
		if (RESET)
			TriggerOut <= 0;
		else begin
			if (DIRECTION == 0) begin
				if (ENABLE_IN && (Counter == COUNTER_MAX))
					TriggerOut <= 1;
				else 
					TriggerOut <= 0;
			end
		else begin
				if (ENABLE_IN && (Counter == 0))
					TriggerOut <= 1;
				else 
					TriggerOut <= 0;
			end		
		end		
	 end

	 //Tie the registers that hold the count and TriggerOut values to the output
	 assign COUNT = Counter;
	 assign TRIG_OUT = TriggerOut;
	 
endmodule
