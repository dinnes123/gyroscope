
#include <Timer.h>

#include "gyroscope.h" //include the declaration for this class
unsigned long millisWithFlushStop ;
unsigned long millisWithFlushStart ;
//<<constructor>> setup the LED, make pin 13 an OUTPUT
gyroscope_mpu6050::gyroscope_mpu6050()
			{
		      Serial1.begin(115200);
              Serial1.write("0xFF");
              Serial1.write("0xAA");
              Serial1.write("0x52");
              
            
			}

//<<destructor>>
gyroscope_mpu6050::~gyroscope_mpu6050(){/*nothing to destruct*/}

//turn the LED on
double gyroscope_mpu6050::get_v()
		     {
         
       
         
              while (Serial1.available()) 
                        {
                                
                                Re_buf[counter]=(unsigned char)Serial1.read();
                                
                                if(counter==0&&Re_buf[0]!=0x55)
                                    { 
                                          
                                           Serial1.end() ;
                                           Serial1.begin(115200);
                                           //Serial.print("{");Serial.print(Serial1.available());Serial.print("}");
                                           delay(10);
                                           Re_buf[counter]=(unsigned char)Serial1.read();
                                          
                                    }
                              
                                
                                counter++;       
                                if(counter==11)             //接收到11个数据
                                         {    
                                               //Serial.println("runnung"); 
                                               counter=0;               //重新赋值，准备下一帧数据的接收 
                                               if(Re_buf[0]==0x55)      //检查帧头
                                                       {  

                                                              switch(Re_buf [1])
                                                                            {
                                                                                                case 0x53:
                                                                                                      angle[0] = (short(Re_buf [3]<<8| Re_buf [2]))/32768.0*180;
                                                                                                      angle[1] = (short(Re_buf [5]<<8| Re_buf [4]))/32768.0*180;
                                                                                                      angle[2] = (short(Re_buf [7]<<8| Re_buf [6]))/32768.0*180;
                                                                                                      T = (short(Re_buf [9]<<8| Re_buf [8]))/340.0+36.25;
                                                                                                      
                                                                                                      //Serial.print((int)angle[0]);Serial.print(" \t\t");
                                                                                                      //Serial.print((int)angle[1]);Serial.print(" \t\t");
                                                                                                      //Serial.println((int)angle[2]);Serial.print(" \t\t");
                                                                                                      
                                                                                                      double degree=angle[2];
                                                                                                      z_axis=angle[2];
                                                                                                      y_axis=angle[1];
                                                                                                      x_axis=angle[0];
                                                                                                      /*for(int i=0;i<11;i++)
											                                                            	{
											                                                            		Serial.print(Re_buf[i],HEX);Serial.print(" ");
																											}*/
																									/* Serial.print("(");
                                                                                                     Serial.print(degree);
                                                                                                     Serial.print(")");*/ 
                                                                                                    
                                                                                                     return degree;
                                                        
                                                                                                     
                                                                                                      break;
                                                                            } 
                                                                             
                                                        }
                                          }
                                         
                          
                        }
                        //Serial.print("{");Serial.print(Serial1.available());Serial.print("}");
                     
                        
                        return get_v();
                       /* Serial.println(" ");
                        Serial.print(Serial1.available(), DEC); Serial.print(" ");
                        Serial.print(Serial1.available(), DEC); Serial.print(" ");
                        Serial.print(Serial1.available(), DEC); Serial.print(" ");
                        
                        Serial.print(Serial1.available(), DEC); Serial.println(" ");*/
				  
		     }
int gyroscope_mpu6050::check(int checked_distance)
        {
            delay(5000);
            nows=checked_distance;
         /*   if(   (nows-before) >50  || (nows-before) <-50) return before;
            Serial.print("nows=");Serial.println( nows );
            Serial.print("before=");Serial.println( before );
            
            before=checked_distance;
            Serial.print("nows=");Serial.println( nows );
            Serial.print("before=");Serial.println( before );
            */
            return nows;     

        }
