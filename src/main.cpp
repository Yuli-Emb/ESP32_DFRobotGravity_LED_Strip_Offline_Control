#include <Adafruit_NeoPixel.h>
#include "DFRobot_DF2301Q.h"

#include "effects.h"
#include "com_lookup.h"
#include "DFR_module.h"
#include "ledstate.h"
#include "handle_com.h"
#include "ledactions.h"

void setup() {
	Serial.begin(115200);
	Serial.println("STARTING...\n");

	state.strip.begin();
	state.strip.setBrightness(state.current_bright);
	state.strip.clear();
	state.strip.show();
	state.strip.fill(state.strip.Color(0, 0, 255));
	state.strip.show();
	Serial.println("LEDS INITIALIZED\n");

	delay(2000);

	DFR_init();

	startupAnimation();
	Serial.println("READY FOR WORK");
}

void loop() {
	uint8_t CMDID = asr.getCMDID();

	if (CMDID != 0) {
		handle_com(CMDID);
	}

  	if (!state.isOn && state.current_mode != Mode::Alarm) {
    	delay(100);
    	return;
	}

  	unsigned long now = millis();
  	for (int i = 0; i < tickCount; i++) {
    	if (state.current_mode == effectTicks[i].mode) {
      		if (now - state.lastUpdate > effectTicks[i].interval) {
        		effectTicks[i].tickFn();
        		state.lastUpdate = now;
      		}
      		break;
    	}
  	}
}