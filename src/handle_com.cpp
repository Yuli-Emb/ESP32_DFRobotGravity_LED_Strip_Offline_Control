#include "handle_com.h"

void handle_com(uint8_t CMDID) {
    unsigned long responseStart = millis();

    for (int i = 0; i < colorCount; i++) {
		if (CMDID == colorCommands[i].cmdID) {
        	setColor(colorCommands[i].r, colorCommands[i].g, colorCommands[i].b);
        	Serial.print("Color: "); Serial.println(CMDID);
        	CMDID = 0; break;
      	}
    }

    for (int i = 0; i < effectCount; i++) {
      	if (CMDID == effectCommands[i].cmdID) {
        	activateMode(effectCommands[i].mode, effectCommands[i].brightness);
        	Serial.print("Effect: "); Serial.println(CMDID); Serial.print(" ");
        	CMDID = 0; break;
      	}
    }

    for (int i = 0; i < brightnessCount; i++) {
      	if (CMDID == brightnessCommands[i].cmdID) {
        	if (brightnessCommands[i].isAbsolute) {
          		setBrightness(brightnessCommands[i].value);
			}
        	else {
          		setBrightness(state.current_bright + brightnessCommands[i].value);
			}
        	Serial.print("Brightness: "); Serial.println(CMDID);
       		CMDID = 0; break;
      	}
    }

    for (int i = 0; i < modeCount; i++) {
      	if (CMDID == modeCommands[i].cmdID) {
        	state.color_temp = modeCommands[i].cctTemp;
        	applyColorTemp();
        	setBrightness(modeCommands[i].brightness);
        	Serial.print("Mode: "); Serial.println(CMDID);
        	CMDID = 0; break;
      	}
    }

    switch (CMDID) {
      	case 109: 
			adjustCCT(+CCT_STEP); Serial.println("CCT+");
			break;
      	case 110: 
			adjustCCT(-CCT_STEP); Serial.println("CCT-");
			break;
      	case 111: 
			adjustCCT(+100);
				Serial.println("CCT max");
			break;
      	case 112: adjustCCT(-100);
			Serial.println("CCT min");
			break;
      	case 103:
        	state.isOn = true;
        	state.current_mode = Mode::Static;
        	state.strip.setBrightness(state.current_bright);
        	state.strip.fill(state.current_color);
        	state.strip.show();
        	Serial.println("ON");
        	break;
    	case 104:
    		state.isOn = false;
        	state.current_mode = Mode::Static;
        	state.strip.clear();
        	state.strip.show();
        	Serial.println("OFF");
        	break;
      	default:
        	if (CMDID != 0) {
          		Serial.print(">>> Unknown: "); Serial.println(CMDID);
        	}
        	break;
    }

    Serial.print("Response time: ");
    Serial.print(millis() - responseStart);
}