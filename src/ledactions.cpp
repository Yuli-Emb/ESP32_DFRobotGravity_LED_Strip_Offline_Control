#include "ledactions.h"

uint32_t cctToColor(int temp) {
	temp = constrain(temp, 0, 100);
	uint8_t r = map(temp, 0, 100, 255, 180);
	uint8_t g = map(temp, 0, 100, 180, 220);
	uint8_t b = map(temp, 0, 100, 80, 255);
	return state.strip.Color(r, g, b);
}

void setColor(uint8_t r, uint8_t g, uint8_t b) {
	state.current_color = state.strip.Color(r, g, b);
	if (state.isOn) { 
		state.strip.fill(state.current_color); 
		state.strip.show(); 
	}
}

void setBrightness(int brightness) {
	state.current_bright = constrain(brightness, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
	state.strip.setBrightness(state.current_bright);
	state.strip.show();
}

void applyColorTemp() {
	state.current_mode = Mode::Static;
	state.current_color = cctToColor(state.color_temp);
	if (state.isOn) { 
		state.strip.fill(state.current_color); 
		state.strip.show(); 
	}
}

void adjustCCT(int delta) {
	state.color_temp = constrain(state.color_temp + delta, 0, 100);
	applyColorTemp();
}

void activateMode(Mode mode, int brightness) {
	state.current_mode = mode;
	state.isOn = true;
	state.breath_bright = 0;
	state.breath_state = true;
	state.chase_pos = 0;
	state.rainbow_h = 0;
	state.alarm_state = false;
	state.relax_bright = 5;
	state.relax_dir = true;
	if (brightness >= 0) {
		state.strip.setBrightness(brightness);
	}
	else {
		state.strip.setBrightness(state.current_bright);
	}
}