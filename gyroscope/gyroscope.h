#ifndef TOROI_NEW_H
#define TOROI_NEW_H

#include "Arduino.h"
//2017/5/9 新增新功能 
class gyroscope_mpu6050 
        { 
              public:
              	gyroscope_mpu6050();
              	~gyroscope_mpu6050();
              	double x_axis;
              	double y_axis;
              	double z_axis;
              	double get_v();
              	
              private:
        		unsigned char Re_buf[11],counter=0;
                unsigned char sign=0;
                int check(int checked_distance);
                int before=0;
                int nows;
                double a[3],w[3],angle[3],T;
                
                int degree;
                void niceCallback();
                unsigned long millisNoFlushStop ;
                unsigned long millisNoFlushStart ;
                long double aa;
                long double t;
                long double d;
                
        };
#endif
