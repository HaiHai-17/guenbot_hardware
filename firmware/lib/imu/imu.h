#ifndef IMU_CONFIG_H
#define IMU_CONFIG_H

#if defined(USE_MPU9150_IMU) && !defined(USE_MPU6050_IMU)
#define USE_MPU6050_IMU
#endif

#include "default_imu.h"

#ifdef USE_MPU6050_IMU
    #define IMU MPU6050IMU
#endif

#endif
