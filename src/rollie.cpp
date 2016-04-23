/*************************************************************
*
*  rollie.cpp - Self balencing robot project
*
*  Authours: Jonas Menge and Michael Jones
*
*  Usage:
*
*
*************************************************************/
#include "imu.h"
#include "pid.h"
#include "stepper.h"

#include <stdio.h>
#include <wiringPi.h>
#include <thread>
#include <math.h>

#define DEADBAND 0.0    // Absolute amount of angle error that is exeptable
//#define DEADBAND 0.00001    // Absolute amount of angle error that is exeptable


// function prototypes
void loop(pid_filter_t *pidAngle, pid_filter_t *pidPos, int devAccel, int devGyro, struct stepper *stepper);


int main()
{
<<<<<<< HEAD
    /* PID controller setup */
    pid_filter_t pid;
    pid_init(&pid);



//    pid_set_gains(&pid, 0.026, /*0.0000108*/0.0, 0.000024);
//    pid_set_gains(&pid, 0.020, /*0.0000108*/0.0, 0.00004);
//    pid_set_gains(&pid, 0.027,/* 0.0000808*/0.0, /*0.000024*/ 0.001);
//    pid_set_gains(&pid, 0.029,/* 0.0000808*/0.0, /*0.000024*/ 0.001);
//    pid_set_gains(&pid, 0.050,/* 0.0000808*/0.0, /*0.000024*/ 0.002);
//    pid_set_gains(&pid, 0.20,/* 0.0000808*/0.00001, /*0.000024*/ 0.003);
    pid_set_gains(&pid, 0.260,/* 0.0000808*/0.0000, /*0.000024*/ 0.000010);
=======
    /* Angle PID controller setup */
    pid_filter_t pidAngle;
    pid_init(&pidAngle);

    /* Position PID controller setup */
    pid_filter_t pidPos;
    pid_init(&pidPos);

    // pid_set_gains(&pid, 0.026, /*0.0000108*/0.0, 0.000024);
    // pid_set_gains(&pid, 0.020, /*0.0000108*/0.0, 0.00004);
    // pid_set_gains(&pid, 0.027,/* 0.0000808*/0.0, /*0.000024*/ 0.001);
    // pid_set_gains(&pid, 0.029,/* 0.0000808*/0.0, /*0.000024*/ 0.001);
    // pid_set_gains(&pid, 0.050,/* 0.0000808*/0.0, /*0.000024*/ 0.002);
    // pid_set_gains(&pid, 0.20,/* 0.0000808*/0.00001, /*0.000024*/ 0.003);
    pid_set_gains(&pidAngle, 0.260,/* 0.0000808*/0.0000, /*0.000024*/ 0.000010);
    pid_set_gains(&pidPos, 0.001,/* 0.0000808*/0.00001, /*0.000024*/ 0.00000);
>>>>>>> 1e1e50d99d68b44656080dec1f8223732d36597f

    /* IMU setup */
    int devAccel = accConfig();
    int devGyro = gyroConfig();
/*    float pitch = ;
    for (size_t i = 0; i < 200; i++) {
      getAngle(&pitch,devAccel,devGyro); // Get an agle to clear out the crap
    }
*/

    /* Start Stepper Motor Thread */
    struct stepper *stepper;
    setSpeed(0.0, &stepper->period);

    std::thread t_stepper;
    t_stepper = std::thread(stepperControl, stepper);

    //bool enable = 1;
    /* Motor tester eh
    while (1){
      printf("Set velocity to 0.01 m/s\n");
      setSpeed(0.01, &period);
      delay(10000);
      printf("Set velocity to 0.02 m/s\n");
      setSpeed(0.02, &period);
      delay(10000);
      printf("Set velocity to 0.03 m/s\n");
      setSpeed(0.03, &period);
      delay(10000);
      printf("Set velocity to 0.04 m/s\n");
      setSpeed(0.04, &period);
      delay(10000);
      printf("Set velocity to 0.05 m/s\n");
      setSpeed(0.05, &period);
      delay(10000);
    }
  */


    loop(&pidAngle, &pidPos, devAccel, devGyro, stepper);


    return 0;
}


void loop(pid_filter_t *pidAngle, pid_filter_t *pidPos, int devAccel, int devGyro, struct stepper *stepper)
{
    float error = 0.0;
    float pitch = 0.0;
    float setpointPos   = 0.0;
    float setpointAngle = 0.0;
    float pidOutput;

    while (1){

        getAngle(&pitch,devAccel,devGyro);


        // if(abs(error) < DEADBAND){
        //   error = 0;
        // }

        errorPos = setpointPos - count;
        setpointAngle = pid_process(pidPos, stepper->count);

        errorAngle = setpointAngle - pitch;
        pidOutput = pid_process(pidAngle, errorAngle);

        setSpeed(pidOutput, &stepper->period);

        printf("\rerPos = %f, spAngle = %f, erAngle = %f, PID = %f",errorPos, setpointAngle, errorAngle, pidOutput);

    }
}
