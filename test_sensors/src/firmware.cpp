#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <stdio.h>
#include <i2cdetect.h>

#include <nav_msgs/msg/odometry.h>
#include <sensor_msgs/msg/imu.h>
#include <geometry_msgs/msg/twist.h>
#include <geometry_msgs/msg/vector3.h>

#include "config.h"
#include "odometry.h"
#include "imu.h"
#define ENCODER_USE_INTERRUPTS
#define ENCODER_OPTIMIZE_INTERRUPTS
#include "pwm.h"

#ifndef BAUDRATE
#define BAUDRATE 115200
#endif

nav_msgs__msg__Odometry odom_msg;
sensor_msgs__msg__Imu imu_msg;
geometry_msgs__msg__Twist twist_msg;

Odometry odometry;
IMU imu;

void setup()
{
    Serial.begin(BAUDRATE);
#ifdef BOARD_INIT // board specific setup
    BOARD_INIT;
#endif
    i2cdetect();  // default range from 0x03 to 0x77
    initPwm();
    imu.init();
}

void loop() {
    delay(1000);
    imu_msg = imu.getData();
    Serial.printf("ACC %5.2f %5.2f %5.2f GYR %5.2f %5.2f %5.2f",
	   imu_msg.linear_acceleration.x, imu_msg.linear_acceleration.y, imu_msg.linear_acceleration.z,
	   imu_msg.angular_velocity.x, imu_msg.angular_velocity.y, imu_msg.angular_velocity.z);
}
