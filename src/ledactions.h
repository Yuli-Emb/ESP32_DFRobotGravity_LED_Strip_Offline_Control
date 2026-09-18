#ifndef LEDACTIONS_H
#define LEDACTIONS_H

#include <stdint.h>

#include "ledstate.h"
#include "com_lookup.h"

uint32_t cctToColor(int temp);
void setColor(uint8_t r, uint8_t g, uint8_t b);
void setBrightness(int brightness);
void applyColorTemp();
void adjustCCT(int delta);
void activateMode(Mode mode, int brightness = -1);

#endif