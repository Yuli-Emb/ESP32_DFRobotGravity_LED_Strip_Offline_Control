#ifndef EFFECTS_H
#define EFFECTS_H

#include <Adafruit_NeoPixel.h>
#include <math.h>
#include "ledstate.h"

void tickBreathing();
void tickChase();
void tickTwinkle();
void tickFire();
void tickAlarm();
void tickRelax();
void tickRainbow();
void startupAnimation();


#endif