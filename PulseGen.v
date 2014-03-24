`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Organization:       The University of Edinburgh
// Student:            Mihail Mitev s1032574
//  
//
//////////////////////////////////////////////////////////////////////////////////
module PulseGen(
    input CLK,
    input RST,
    input pack_strobe,
    input pack_gen_EN,
    output Pulse,
    output Pulse_Strobe
    );
//Clock(source) Counter Parameters    
parameter Counter_Width=10;
parameter Counter_Max=694; 
 
 
wire Pulse_half_period_strobe; //output from Clock Counter
reg Pulse_Trig=0; //register which is negated at each Pulse Half Period Strobe
reg Pulse_Str=0;  //register which is set to one(for one clock cycle) only at the start of each pulse full period

//counter which generates a strobe for the half period of each pulse
Counter  	# 		(.Counter_Width(Counter_Width),
						.Counter_Max(Counter_Max)
						)
						Clock_Counter
					  (.CLK(CLK),
						.Reset(pack_strobe || RST),
						.ENABLE_IN(pack_gen_EN),
						.COUNT(),
						.TRIG_OUT(Pulse_half_period_strobe)
					);
               
//generation of Pulse and Pulse Strobe Signals               
always@(posedge CLK)begin
   Pulse_Str = 0;
   if(RST || pack_strobe) begin
      Pulse_Str = 1;
      Pulse_Trig = 0;
   end
   else if(Pulse_half_period_strobe)begin
      Pulse_Trig = ~Pulse_Trig;
      if(Pulse_Trig)begin
         Pulse_Str = 1;
      end
      else begin
         Pulse_Str = 0;
      end
   end   
   else
      Pulse_Trig = Pulse_Trig;
end

assign Pulse = Pulse_Trig;
assign Pulse_Strobe = Pulse_Str;
endmodule
