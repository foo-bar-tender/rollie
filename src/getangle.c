//this code was edited from the toilet

#include <iostream>
#include <errno.h>

#include "stdio.h"
#include <math.h>
#include <wiringPiI2C.h>

int main() {

        int fd, result;

        fd = wiringPiI2CSetup(0x60);

        //cout << "Init result: "<< fd << endl;
        printf("fd:%d",fd);
        return fd;
}

