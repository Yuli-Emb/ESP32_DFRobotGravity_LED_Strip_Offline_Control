#ifndef COM_LOOKUP_H
#define COM_LOOKUP_H

#define BRIGHTNESS_STEP 30
#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 5
#define CCT_STEP 10

#include <math.h>
#include "effects.h"

extern const int colorCount;
extern const int modeCount;
extern const int brightnessCount;
extern const int effectCount;
extern const int tickCount;

struct ColorCommand {
	uint8_t cmdID;
	uint8_t r, g, b;
};

struct ModeCommand {
	uint8_t cmdID;
	int cctTemp;
	int brightness;
};

struct BrightnessCommand {
	uint8_t cmdID;
	int value;
	bool isAbsolute;
};

struct EffectCommand {
	uint8_t cmdID;
	Mode mode;
	int brightness;
};

struct EffectTick {
	Mode mode;
	void (*tickFn)();
	unsigned long interval;
};

extern ColorCommand colorCommands[];
extern ModeCommand modeCommands[];
extern BrightnessCommand brightnessCommands[];
extern EffectCommand effectCommands[];
extern EffectTick effectTicks[];

#endif