/*
 * AutoKeypad.cpp
 *
 *  Created on: Jul 3, 2022
 *      Author: mgesteiro
 */

#include <Arduino.h>
#include "AutoKeypad.h"
#include "Configuration.h"
#include "Buzzer.h"

#define PULLUP_MARGIN 140

// constructor
AutoKeypad::AutoKeypad() {
	// read EEPROM keypad values
	uint16_t *eeprom_index = EEPROM_KEYPAD_VALUES_INDEX;
	_autoconfig->value_button_up    = eeprom_read_word(eeprom_index);
	eeprom_index++;
	_autoconfig->value_button_left  = eeprom_read_word(eeprom_index);
	eeprom_index++;
	_autoconfig->value_button_go    = eeprom_read_word(eeprom_index);
	eeprom_index++;
	_autoconfig->value_button_right = eeprom_read_word(eeprom_index);
	eeprom_index++;
	_autoconfig->value_button_down  = eeprom_read_word(eeprom_index);


	// check values, use defaults if invalid
	if ((_autoconfig->value_button_up == 0x00) || (_autoconfig->value_button_up == 0xFFFF)) {
		_autoconfig->value_button_up = BS_ANALOG_VALUE_UP;
	}
	if ((_autoconfig->value_button_left == 0x00) || (_autoconfig->value_button_left == 0xFFFF)) {
		_autoconfig->value_button_left = BS_ANALOG_VALUE_LEFT;
	}
	if ((_autoconfig->value_button_go == 0x00) || (_autoconfig->value_button_go == 0xFFFF)) {
		_autoconfig->value_button_go = BS_ANALOG_VALUE_GO;
	}
	if ((_autoconfig->value_button_right == 0x00) || (_autoconfig->value_button_right == 0xFFFF)) {
		_autoconfig->value_button_right = BS_ANALOG_VALUE_RIGHT;
	}
	if ((_autoconfig->value_button_down == 0x00) || (_autoconfig->value_button_down == 0xFFFF)) {
		_autoconfig->value_button_down = BS_ANALOG_VALUE_DOWN;
	}
}

// destructor
AutoKeypad::~AutoKeypad() {}

/*
 * autoConfig()
 * Detects if a key is pressed during start and updates the new five key values in the eeprom
 */
void AutoKeypad::autoConfig() {
	// detect key pressed to start
	pinMode(BS_ANALOG_PIN, INPUT_PULLUP); // if not "pullupable" works as normal INPUT
	bool press_detected = false;
	int port_read_value = analogRead(BS_ANALOG_PIN);
	if ((port_read_value > PULLUP_MARGIN) && (port_read_value < (1023-PULLUP_MARGIN))) { // something pressed
		for (byte i=0; i < 4; i++) {
			tone(BUZZER_PIN, BUZZER_BEEP_FREQUENCY, BUZZER_BEEP_MILLIS);
		    delay(BUZZER_BEEP_MILLIS*5);
		}
		press_detected = true;
	}
	// save keys if detected
	if (press_detected) {
		//Serial.println("port detected!");
		for (byte i=0; i < 5; i++) {
			// read value
			port_read_value = analogRead(BS_ANALOG_PIN);
			while ((port_read_value < PULLUP_MARGIN) || (port_read_value > 1023-PULLUP_MARGIN)) // wait por key press
				port_read_value = analogRead(BS_ANALOG_PIN);
			// store value for each key
			switch (i) {
				case 0: _autoconfig->value_button_up    = port_read_value; break;
				case 1: _autoconfig->value_button_left  = port_read_value; break;
				case 2: _autoconfig->value_button_go    = port_read_value; break;
				case 3: _autoconfig->value_button_right = port_read_value; break;
				case 4: _autoconfig->value_button_down  = port_read_value; break;
			}
			// signal + delay
			tone(BUZZER_PIN, BUZZER_BEEP_FREQUENCY, BUZZER_BEEP_MILLIS);
			delay(350);
		} // for 5 keys
		// write values to eeprom
		uint16_t *eeprom_index = EEPROM_KEYPAD_VALUES_INDEX;
		eeprom_update_word(eeprom_index, _autoconfig->value_button_up);
		eeprom_index++;
		eeprom_update_word(eeprom_index, _autoconfig->value_button_left);
		eeprom_index++;
		eeprom_update_word(eeprom_index, _autoconfig->value_button_go);
		eeprom_index++;
		eeprom_update_word(eeprom_index, _autoconfig->value_button_right);
		eeprom_index++;
		eeprom_update_word(eeprom_index, _autoconfig->value_button_down);
		eeprom_index++;
	} // if (press_detected)
} // AutoKeypad::autoConfig()

/*
 * fixConfig()
 * Updates the provided configuration structure with the saved/obtained values
 */
void AutoKeypad::fixConfig(ButtonSetAnalog::Config* config) {
	// update config values
	config->value_button_up    = _autoconfig->value_button_up;
	config->value_button_left  = _autoconfig->value_button_left;
	config->value_button_go    = _autoconfig->value_button_go;
	config->value_button_right = _autoconfig->value_button_right;
	config->value_button_down  = _autoconfig->value_button_down;
} // AutoKeypad:fixConfig()
