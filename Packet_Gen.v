`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Organization:       The University of Edinburgh
// Student:            Mihail Mitev s1032574
//  
//
//////////////////////////////////////////////////////////////////////////////////
module Packet_Gen(
    input CLK,
    input Pulse,
    input RST,
    input pack_strobe,
    input Pulse_Strobe,
    input [3:0] current_dir_state,
    output IR_LED
    /*output Packet_Finished_Flag_2,
    output Pulse_CNT_RST_2,
    output [7:0]j_2,
    output [2:0]packet_state_2,
    output [2:0]packet_previous_state_2 */
    );
//Packet Generator parameters
parameter Pulse_Counter_Width = 8;
parameter StartBurstSize = 192;
parameter CarSelectBurstSize = 24;
parameter GapBurstSize = 24;
parameter AssertBurstSize = 48;
parameter DeAssertBurstSize = 24;

reg Packet_Finished_Flag;      //indication flag on whether a full packet has been generated and transmitted
reg Pulse_CNT_RST;             //control signal(reset) for the pulse counter
reg[Pulse_Counter_Width-1:0] j;//number of transmitted pulses - resets after each packet state,so maximum is StartBurstSize
reg IR_Transmit;               //register to control wheter LED is connected to PULSE or GND while a packet is generated

//Pulse Counter
always@(posedge CLK or posedge Pulse_CNT_RST)begin //HIERARCHY IS ESSENTIAL
   if(Pulse_CNT_RST)begin                       //I
		j = 0;
	end
   else if(RST || Packet_Finished_Flag)begin    //II
      j = 0;
   end
   else if(Pulse_Strobe)begin                   //III 
      j = j+1;
   end
   else begin                                   //IV
      j = j;
   end
end
//End of Pulse Counter



//packet SM States Definition
parameter StartBurst = 3'b001;
parameter CarSelectBurst = 3'b010;
parameter RightBurst = 3'b011;
parameter LeftBurst = 3'b100;
parameter BackwardBurst = 3'b101;
parameter ForwardBurst = 3'b110;
parameter GapInterval = 3'b000;// 7 states, so 3 bits

//Packet SM State Registers
reg [2:0] packet_state = 3'b000;          //stores currently generated packet state - decision whether IR_Transmit is connected to 0 or Pulse
reg [2:0] packet_previous_state = 3'b000; //stores previously generated packet state - used to set the next state after a gap interval

//Packet Generator SM
always@(posedge CLK or posedge RST)begin
   if(RST)begin   //Reset initializes the SM
      packet_state = GapInterval;
      packet_previous_state = GapInterval;
      Packet_Finished_Flag = 1;
      Pulse_CNT_RST = 1;
   end
   else if(pack_strobe)begin //begin generation of packet by setting packet_state to first state- StartBurst, at pack_strobe from 10Hz Counter in Main FSM
      packet_state = StartBurst;
      Packet_Finished_Flag = 0; 
      Pulse_CNT_RST = 0;      
   end
   else if(Packet_Finished_Flag == 1)begin //When Packet has been Transmitted IR_Transmit is set to 0
      IR_Transmit = 0;
      Pulse_CNT_RST = 1;
   end                          
   else begin
      case(packet_state)
      StartBurst:begin    
                     if(j < StartBurstSize) begin
                        packet_state = StartBurst;
                        Pulse_CNT_RST = 0;
                        IR_Transmit = Pulse;
                     end
                     else begin
                        Pulse_CNT_RST = 1;
                        packet_state = GapInterval;
                        packet_previous_state = StartBurst;
                     end
                  end   
      CarSelectBurst:begin
                        if(j == CarSelectBurstSize)begin
                           Pulse_CNT_RST = 1;
                           packet_state = GapInterval;
                           packet_previous_state = CarSelectBurst;
                        end
                        else begin
                           packet_state = CarSelectBurst;
                           Pulse_CNT_RST = 0;
                           IR_Transmit = Pulse;
                        end
                     end   
       RightBurst:begin
                     if((j == AssertBurstSize) && (current_dir_state[0]))begin
                        Pulse_CNT_RST = 1;
                        packet_state = GapInterval;
                        packet_previous_state = RightBurst;
                     end
                     else if((j == DeAssertBurstSize) && (!current_dir_state[0]))begin
                        Pulse_CNT_RST = 1;
                        packet_state = GapInterval;
                        packet_previous_state = RightBurst;
                     end
                     else begin
                        packet_state = RightBurst;
                        Pulse_CNT_RST = 0;
                        IR_Transmit = Pulse;
                     end 
                  end   
        LeftBurst:begin
                     if((j == AssertBurstSize) && (current_dir_state[1]))begin
                        Pulse_CNT_RST = 1;
                        packet_state = GapInterval;
                        packet_previous_state = LeftBurst;
                     end
                     else if((j == DeAssertBurstSize) && (!current_dir_state[1]))begin
                        Pulse_CNT_RST = 1;
                        packet_state = GapInterval;
                        packet_previous_state = LeftBurst;
                     end
                     else begin
                        packet_state = LeftBurst;
                        Pulse_CNT_RST = 0;
                        IR_Transmit = Pulse;
                     end
                  end   
         ForwardBurst:begin
                        if((j == AssertBurstSize) && (current_dir_state[3]))begin
                           Pulse_CNT_RST = 1;
                           packet_state = GapInterval;
                           packet_previous_state = ForwardBurst;
                        end
                        else if((j == DeAssertBurstSize) && (!current_dir_state[3]))begin
                           Pulse_CNT_RST = 1;
                           packet_state = GapInterval;
                           packet_previous_state = ForwardBurst;
                        end 
                        else begin
                           packet_state = ForwardBurst;
                           Pulse_CNT_RST = 0;
                           IR_Transmit = Pulse;
                        end 
                      end
          BackwardBurst:begin
                           if((j == AssertBurstSize) && (current_dir_state[2]))begin
                              Pulse_CNT_RST = 1;
                              packet_state = GapInterval;
                              packet_previous_state = BackwardBurst;
                           end
                           else if((j == DeAssertBurstSize) && (!current_dir_state[2]))begin
                              Pulse_CNT_RST = 1;
                              packet_state = GapInterval;
                              packet_previous_state = BackwardBurst;
                           end
                           else begin
                              packet_state = BackwardBurst;
                              Pulse_CNT_RST = 0;
                              IR_Transmit = Pulse;
                           end  
                         end  
          GapInterval:begin
                        if(Packet_Finished_Flag == 0)begin 
                           if(j == GapBurstSize)begin
                              Pulse_CNT_RST = 1;
                              case(packet_previous_state)
                                 StartBurst:       begin packet_state = CarSelectBurst;packet_previous_state = GapInterval; end
                                 CarSelectBurst:   begin packet_state = RightBurst;packet_previous_state = GapInterval; end
                                 RightBurst:       begin packet_state = LeftBurst;packet_previous_state = GapInterval; end
                                 LeftBurst:        begin packet_state = BackwardBurst;packet_previous_state = GapInterval; end
                                 BackwardBurst:    begin packet_state = ForwardBurst;packet_previous_state = GapInterval; end
                                 ForwardBurst:     begin packet_state = GapInterval; packet_previous_state = GapInterval;end
                                 GapInterval:      begin packet_state = packet_previous_state; Packet_Finished_Flag = 1;packet_previous_state = GapInterval; end
                                 default:          begin packet_state = GapInterval;packet_previous_state = GapInterval; end
                              endcase
                            end
                            else begin
                              packet_state = GapInterval;
                              IR_Transmit = 0;
                              Pulse_CNT_RST = 0;
                            end 
                         end   
                         else if(Packet_Finished_Flag == 1)begin  //when packet has been fully generated and transmitted IR_Transmit is set to 0
                             IR_Transmit = 0;
                             Pulse_CNT_RST = 1;
                         end   
                       end     
          default: begin packet_state = packet_previous_state; packet_previous_state = GapInterval;     end            
          endcase              
    end
end
//end of packet generator SM

assign IR_LED = IR_Transmit;

/* SIMULATION OUTPUTS
assign Packet_Finished_Flag_2 = Packet_Finished_Flag;
assign Pulse_CNT_RST_2 = Pulse_CNT_RST;
assign j_2 = j;
assign packet_state_2 = packet_state;
assign packet_previous_state_2 = packet_previous_state;
*/
endmodule

