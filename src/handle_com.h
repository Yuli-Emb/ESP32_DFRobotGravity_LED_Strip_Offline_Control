#ifndef HANDLE_COM_H
#define HANDLE_COM_H

#include <stdint.h>
#include <Arduino.h>

#include "com_lookup.h"
#include "ledactions.h"
#include "ledstate.h"

void handle_com(uint8_t CMDID);

#endif