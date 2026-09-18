#include "DFR_module.h"

DFRobot_DF2301Q_I2C asr;

void DFR_init() {
  Wire.begin(16, 17);
  while (!(asr.begin())) {
    Serial.println("Communication with device failed");
    state.strip.fill(state.strip.Color(255, 0, 0));
    state.strip.show();
    delay(3000);
  }
  Serial.println("DFROBOT INITIALIZED\n");

  asr.setVolume(3);
  asr.setMuteMode(0);
  asr.setWakeTime(20);
}