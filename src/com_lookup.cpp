#include "com_lookup.h"

const ColorCommand colorCommands[] = {
	{116, 255, 0, 0},
	{117, 255, 128, 0},
	{118, 255, 255, 0},
	{119, 0, 255, 0},
	{120, 0, 255, 255},
	{121, 0, 128, 255},
	{122, 153, 51,  255},
	{123, 255, 255, 255},
};
const int colorCount = sizeof(colorCommands) / sizeof(colorCommands[0]);


const ModeCommand modeCommands[] = {
	{113, 100, 200},
	{114, 20,  15},
	{128, 90,  150},
	{129, 10,  150},
};
const int modeCount = sizeof(modeCommands) / sizeof(modeCommands[0]);


const BrightnessCommand brightnessCommands[] = {
	{105,  BRIGHTNESS_STEP, false},
	{106, -BRIGHTNESS_STEP, false},
	{107,  MAX_BRIGHTNESS,  true},
 	{108,  MIN_BRIGHTNESS,  true},
};
const int brightnessCount = sizeof(brightnessCommands) / sizeof(brightnessCommands[0]);


const EffectCommand effectCommands[] = {
	{5,  Mode::Twinkle, -1},
	{6,  Mode::Fire, -1},
	{7,  Mode::Breathing, 1},
	{8,  Mode::Chase, -1},
	{9,  Mode::Alarm, 200},
	{115, Mode::Rainbow, -1},
	{10, Mode::Relax, -1},
};
const int effectCount = sizeof(effectCommands) / sizeof(effectCommands[0]);


const EffectTick effectTicks[] = {
	{Mode::Breathing, tickBreathing, 15},
	{Mode::Chase, tickChase, 40},
	{Mode::Twinkle, tickTwinkle, 80},
	{Mode::Fire, tickFire, 120},
	{Mode::Alarm, tickAlarm, 300},
	{Mode::Rainbow, tickRainbow, 20},
	{Mode::Relax, tickRelax, 30},
};
const int tickCount = sizeof(effectTicks) / sizeof(effectTicks[0]);