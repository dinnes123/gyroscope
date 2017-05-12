#include "gyroscope.h"
gyroscope_mpu6050 gyroscope_mpu6050_1;
void setup() 
    {
          Serial.begin(9600);
    }
void loop() 
    {
          gyroscope_mpu6050_1.get_v();  //取得陀螺儀的角度
          Serial.print("z axis=");Serial.println( gyroscope_mpu6050_1.z_axis );  //顯示z軸的值
          Serial.print("x axis=");Serial.println( gyroscope_mpu6050_1.x_axis );  //顯示x軸的值
          Serial.print("y axis=");Serial.println( gyroscope_mpu6050_1.y_axis );  //顯示y軸的值
    }
