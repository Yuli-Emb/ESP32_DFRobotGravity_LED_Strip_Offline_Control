#ifndef DFR_MODULE_H
#define DFR_MODULE_H

#include "DFRobot_DF2301Q.h"
#include <Wire.h>
#include "ledstate.h"

extern DFRobot_DF2301Q_I2C asr;

void DFR_init();

#endif