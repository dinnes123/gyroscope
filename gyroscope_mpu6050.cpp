#include "gyroscope.h" //include the declaration for this class

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


int gyroscope_mpu6050::check(int checked_distance)
        {
            delay(5000);
            nows=checked_distance;
       
            return nows;     

        }
