#include "gyroscope.h" //include the declaration for this class
unsigned long millisWithFlushStop ;
unsigned long millisWithFlushStart ;
//<<constructor>> setup the LED, make pin 13 an OUTPUT
gyroscope_mpu6050::gyroscope_mpu6050(int rx,int tx,int boundrate)
			{
               static SoftwareSerial gyroscope_local(rx, tx);
               gyroscope_local.begin(boundrate);  
              gyroscope_local.write("0xFF");
              gyroscope_local.write("0xAA");
              gyroscope_local.write("0x52");
              gyroscope=&gyroscope_local; 
            
			}

//<<destructor>>
gyroscope_mpu6050::~gyroscope_mpu6050(){/*nothing to destruct*/}

//turn the LED on
double gyroscope_mpu6050::get_v()
		     {
         
       
        
              while (gyroscope->available()) 
                        {
                                
                                Re_buf[counter]=(unsigned char)gyroscope->read();
                                
                                if(counter==0&&Re_buf[0]!=0x55)
                                    { 
                                          
                                           gyroscope->end() ;
                                           gyroscope->begin(115200);
                                           //Serial.print("{");Serial.print(Serial1.available());Serial.print("}");
                                           delay(10);
                                           Re_buf[counter]=(unsigned char)gyroscope->read();
                                          
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
                                                                                                     
                                                                                                      byte sum=0;
                                                                                                      for(int i=0;i<10;i++)
                                                                                                      sum+=Re_buf[i];
                                                                                                      
                                                                                                      //Serial.print("[sum=");
                                                                                                      //Serial.print(sum,HEX);
                                                                                                      if(sum!=Re_buf[10])
                                                                                                        {
                                                                                                           //Serial.print("  error!");
                                                                                                           return get_v();
                                                                                                        }
                                                                                                      //Serial.print("]  ");
                                                                                                      
                                                                                                     
                                                                                                     
                                                                                                     
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
                                                                                                     /* for(int i=10;i<11;i++)
											                                                            	{
											                                                            		Serial.print(Re_buf[i],HEX);Serial.print(" ");
																											}
																									 Serial.print("(");
                                                                                                     Serial.print(degree);
                                                                                                     Serial.println(")");*/
                                                                                                     
                                                                                                     
                                                                                                     
                                                                                                     return degree;
                                                        
                                                                                                     
                                                                                                      break;
                                                                            } 
                                                                             
                                                        }
                                          }
                                         
                          
                        }
                    
                     
                        
                        return get_v();
                   
				  
		     }
int gyroscope_mpu6050::check(int checked_distance)
        {
            delay(5000);
            nows=checked_distance;
       
            return nows;     

        }
