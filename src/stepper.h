#ifndef STEPPER_H_
#define STEPPER_H_

#include <pthread.h> 
#include <stdio.h>
#include <wiringPi.h>

// function prototypes
void motorSetup();
void wait(float *rate);
void *stepperControl(float *rate, bool *enable);



#endif