#include "gyroscope.h"
gyroscope_mpu6050 gyroscope_mpu6050_1(11,10,115200);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(gyroscope_mpu6050_1.get_v());
}
