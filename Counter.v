`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Organization:       The University of Edinburgh
// Student:            Mihail Mitev s1032574
//  
// This is just the generic counter module from 3rd year - code reuse
//////////////////////////////////////////////////////////////////////////////////
module Counter(
    Reset,
    CLK,
    ENABLE_IN,
    COUNT,
    TRIG_OUT
    );
	 
    parameter Counter_Width = 8;
    parameter Counter_Max = 192;
 
    input Reset;
    input CLK;
    input ENABLE_IN;
    output [Counter_Width-1:0] COUNT;
    output TRIG_OUT;
 
    reg [Counter_Width-1:0] Counter;
    reg TriggerOut;
	 
    //counter output
    always@(posedge CLK or posedge Reset) begin
      if(Reset)
         Counter <= 0;
      else begin
         if (ENABLE_IN) begin
            if(Counter==Counter_Max) begin
               Counter<=0;
               TriggerOut<=1;
            end
            else begin
               Counter<=Counter+1;
               TriggerOut<=0;
            end
         end
         else begin
            Counter<=0;
            TriggerOut<=0;
         end   
      end
    end
	
	assign COUNT = Counter;
	assign TRIG_OUT = TriggerOut;

endmodule

