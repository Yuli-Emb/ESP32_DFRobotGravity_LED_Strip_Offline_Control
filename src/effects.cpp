#include "effects.h"

void tickBreathing() {
    state.strip.setBrightness(state.breath_bright);
    state.strip.fill(state.current_color);
    state.strip.show();

    if (state.breath_state) {
        state.breath_bright += 3;
        if (state.breath_bright >= state.current_bright) {
            state.breath_state = false;
        }
    } 
    else {
        state.breath_bright -= 3;
        if (state.breath_bright <= 0) {
            state.breath_state = true;
        }
    }
}

void tickChase() {
    state.strip.clear();
    state.strip.setPixelColor(state.chase_pos, state.current_color);

    for (int t = 1; t <= 4; t++) {
        int pos = (state.chase_pos - t + state.strip.numPixels()) % state.strip.numPixels();
        uint8_t r = ((state.current_color >> 16) & 0xFF) / (t * 2);
        uint8_t g = ((state.current_color >> 8) & 0xFF) / (t * 2);
        uint8_t b = ((state.current_color) & 0xFF) / (t * 2);
        state.strip.setPixelColor(pos, state.strip.Color(r, g, b));
    }
    
    state.strip.show();
    state.chase_pos = (state.chase_pos + 1) % state.strip.numPixels();
}

void tickTwinkle() {
    int pixel = random(state.strip.numPixels());

    if (random(2)) {
        state.strip.setPixelColor(pixel, state.current_color);
    } 
    else {
        state.strip.setPixelColor(pixel, 0);
    }
    state.strip.show();
}

void tickFire() {
    for (int i = 0; i < state.strip.numPixels(); i++) {
        int flicker = random(80, 180);
        int green = random(10, 50);
        state.strip.setPixelColor(i, state.strip.Color(flicker, green, 0));
    }

    state.strip.show();
}

void tickAlarm() {
    if (state.alarm_state) {
        state.strip.fill(state.strip.Color(255, 0, 0));
    } 
    else {
        state.strip.clear();
    }

    state.strip.show();
    state.alarm_state = !state.alarm_state;
}

void tickRelax() {
    state.strip.setBrightness(state.relax_bright);
    state.strip.fill(state.strip.Color(255, 147, 41));
    state.strip.show();
    
    if (state.relax_dir) {
        state.relax_bright++;
        if (state.relax_bright >= 60) {
            state.relax_dir = false;
        }
    } 
    else {
        state.relax_bright--;
        if (state.relax_bright <= 5) {
            state.relax_dir = true;
        }
    }
}

void tickRainbow() {
    for (int i = 0; i < state.strip.numPixels(); i++) {
        state.strip.setPixelColor(i, state.strip.gamma32(state.strip.ColorHSV(state.rainbow_h + i * 65536 / state.strip.numPixels())));
    }
    state.strip.show();
    state.rainbow_h += 256;
}

void startupAnimation() {
    for (int i = 0; i < state.strip.numPixels(); i++) {
        state.strip.setPixelColor(i, state.strip.Color(0, 100, 255));
        state.strip.setPixelColor((i + 1) % state.strip.numPixels(), state.strip.Color(0, 50, 128));
        state.strip.show();
        delay(40);
    }

    state.strip.clear();
    state.strip.show();
}