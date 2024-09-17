#ifndef ESP32_CONFIG_H
#define ESP32_CONFIG_H

#define LED_PIN LED_BUILTIN

#define LINO_BASE MECANUM 

#define USE_GENERIC_2_IN_MOTOR_DRIVER

#define USE_MPU6050_IMU
// #define IMU_TWEAK {}


#define K_P 0.6                             // P constant
#define K_I 0.8                             // I constant
#define K_D 0.5                             // D constant

#define ACCEL_COV { 0.01, 0.01, 0.01 }
#define GYRO_COV { 0.001, 0.001, 0.001 }
#define ORI_COV { 0.01, 0.01, 0.01 }
#define MAG_COV { 1e-12, 1e-12, 1e-12 }
#define POSE_COV { 0.001, 0.001, 0.001, 0.001, 0.001, 0.001 }
#define TWIST_COV { 0.001, 0.001, 0.001, 0.003, 0.003, 0.003 }

#define MOTOR_MAX_RPM 170                   // motor's max RPM
#define MAX_RPM_RATIO 0.85                  // max RPM allowed for each MAX_RPM_ALLOWED = MOTOR_MAX_RPM * MAX_RPM_RATIO
#define MOTOR_OPERATING_VOLTAGE 12          // motor's operating voltage (used to calculate max RPM)
#define MOTOR_POWER_MAX_VOLTAGE 12          // max voltage of the motor's power source (used to calculate max RPM)
#define MOTOR_POWER_MEASURED_VOLTAGE 12     // current voltage reading of the power connected to the motor (used for calibration)
#define COUNTS_PER_REV1 450                 // wheel1 encoder's no of ticks per rev
#define COUNTS_PER_REV2 450                 // wheel2 encoder's no of ticks per rev
#define COUNTS_PER_REV3 450                 // wheel3 encoder's no of ticks per rev
#define COUNTS_PER_REV4 450                 // wheel4 encoder's no of ticks per rev
#define WHEEL_DIAMETER 0.096               // wheel's diameter in meters
#define LR_WHEELS_DISTANCE 0.2            // distance between left and right wheels
#define PWM_BITS 10                         // PWM Resolution of the microcontroller
#define PWM_FREQUENCY 20000                 // PWM Frequency
#define SERVO_BITS 12                       // Servo PWM resolution
#define SERVO_FREQ 50                       // Servo PWM frequency

// INVERT ENCODER COUNTS
#define MOTOR1_ENCODER_INV false
#define MOTOR2_ENCODER_INV false
#define MOTOR3_ENCODER_INV false
#define MOTOR4_ENCODER_INV false

// INVERT MOTOR DIRECTIONS
#define MOTOR1_INV false
#define MOTOR2_INV false
#define MOTOR3_INV false
#define MOTOR4_INV false

// ENCODER PINS
#define MOTOR1_ENCODER_A 39
#define MOTOR1_ENCODER_B 36

#define MOTOR2_ENCODER_A 34
#define MOTOR2_ENCODER_B 35

#define MOTOR3_ENCODER_A 32
#define MOTOR3_ENCODER_B 33

#define MOTOR4_ENCODER_A 25
#define MOTOR4_ENCODER_B 26

// MOTOR PINS
#ifdef USE_GENERIC_2_IN_MOTOR_DRIVER
  #define MOTOR1_PWM 19
  #define MOTOR1_IN_A 23
  #define MOTOR1_IN_B 16

  #define MOTOR2_PWM 18
  #define MOTOR2_IN_A 4
  #define MOTOR2_IN_B 15

  #define MOTOR3_PWM 5
  #define MOTOR3_IN_A 13
  #define MOTOR3_IN_B 12

  #define MOTOR4_PWM 17
  #define MOTOR4_IN_A 14 
  #define MOTOR4_IN_B 27

  #define PWM_MAX pow(2, PWM_BITS) - 1
  #define PWM_MIN -PWM_MAX
#endif

#define BAUDRATE 921600
#define SDA_PIN 21 
#define SCL_PIN 22
#define NODE_NAME "esp32"

#define USE_SHORT_BRAKE
#define BOARD_INIT { \
    Wire.begin(SDA_PIN, SCL_PIN); \
    Wire.setClock(400000); \
}

// #ifdef USE_SYSLOG
// #define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){ \
//     syslog(LOG_ERR, "%s RCCHECK failed %d", __FUNCTION__, temp_rc); \
//     return false; }}
// #else
// #define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){ \
//     flashLED(3); \
//     return false; }}
// #endif

#endif
