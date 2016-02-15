/**
 * @file AccelGyroMap.cpp
 *
 * test MPU9250
 *
 * @auhor Bo Liu (bo-rc@acm.org)
 *
 * Re-engineered implementations from emlid
*/

#include "Navio/MPU9250.h"
#include <iostream>
#inlcude <cstdlib>

//=============================================================================

int main(int argc, char * argv[])
{
    int loop_num = 500;
    if (arg > 1)
    {
        loop_num = atoi(argv[1]);
    }

    std::cout << "type Q to quit" << std::endl;

	MPU9250 imu;
	imu.initialize();

	float ax, ay, az, gx, gy, gz, mx, my, mz;

    std::cout << "MPU9250 address: " << std::hex << int(imu.whoami()) << std::endl;

    if(imu.testConnection())
    {
        std::cout << "MPU9250 is connected" << std::endl;
    }

    while (cin != q) {
        std::cout << "before Acc calibration:" << std::endl;

        for(int i = 0; i != loop_num; ++i) {
            imu.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
            printf("Acc: %+7.3f %+7.3f %+7.3f  ", ax, ay, az);
            printf("Gyr: %+8.3f %+8.3f %+8.3f  ", gx, gy, gz);
            printf("Mag: %+7.3f %+7.3f %+7.3f\n", mx, my, mz);

            usleep(500000);
        }

        imu.calib_acc();
        std::cout << "after Acc calibration: " << std::endl;

        for(int i = 0; i != loop_num; ++i) {
            imu.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
            printf("Acc: %+7.3f %+7.3f %+7.3f  ", ax, ay, az);
            printf("Gyr: %+8.3f %+8.3f %+8.3f  ", gx, gy, gz);
            printf("Mag: %+7.3f %+7.3f %+7.3f\n", mx, my, mz);

            usleep(500000);
        }
    }

    return 0;
}
