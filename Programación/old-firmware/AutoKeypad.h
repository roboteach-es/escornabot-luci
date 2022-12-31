/*
 * AutoKeypad.h
 *
 *  Created on: Jul 3, 2022
 *      Author: miguel
 */

#ifndef AUTOKEYPAD_H_
#define AUTOKEYPAD_H_

#include "ButtonSetAnalog.h"
#include <avr/eeprom.h>

// Index to the last 5 uint16_t EEPROM positions; E2END = The last EEPROM address (bytes). 1023 for Arduino Nano 328
#define EEPROM_KEYPAD_VALUES_INDEX (uint16_t *)(E2END - 2 * 5 + 1)

class AutoKeypad {
public:
	AutoKeypad();
	virtual ~AutoKeypad();
	void autoConfig();
	void fixConfig(ButtonSetAnalog::Config* config);
private:
	ButtonSetAnalog::Config* _autoconfig = NULL;
};

#endif /* AUTOKEYPAD_H_ */
