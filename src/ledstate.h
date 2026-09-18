#ifndef LEDSTATE_H
#define LEDSTATE_H

#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 60
#define DATA_PIN 4

enum class Mode {
    Static, Rainbow, Breathing, Chase, Twinkle, Fire, Alarm, Relax
};

struct LedState {
    Adafruit_NeoPixel strip;

    bool isOn = true;
    Mode current_mode = Mode::Static;
    int  current_bright = 80;
    uint32_t current_color = 0;
    int  color_temp = 50;

    int breath_bright = 0;
    bool breath_state = true;
    int  chase_pos = 0;
    bool alarm_state = false;
    int  relax_bright = 5;
    bool relax_dir = true;
    uint8_t rainbow_h = 0;

    unsigned long lastUpdate = 0;

    LedState(uint16_t numLeds, uint8_t dataPin, neoPixelType stripType) : strip(numLeds, dataPin, stripType) {}
};

extern LedState state;

#endif