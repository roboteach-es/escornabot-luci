// Configuration.h
/*

Copyright (C) 2014-2019 Escornabot - http://escornabot.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
USA.

See LICENSE.txt for details

*/

#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H


//////////////////////////////////////////////////////////////////////
///// general configuration
//////////////////////////////////////////////////////////////////////

// use simple mode: no long-presses
#define SIMPLE_MODE false

// use only mode-1
#define MODE_1_ONLY false

// engine to use
#define ENGINE_TYPE_STEPPERS
#define STEPPERS_SWAPPED_CABLES false
#define STEPPERS_DEBUG_COILS false
#define IS_LUCI true

// button set to use (analog input, digital input)
#define BUTTONS_ANALOG
//#define BUTTONS_DIGITAL

// milliseconds after a button is considered as pressed
#define BUTTON_MIN_PRESSED 30

// milliseconds after a button is considered as long pressed
#define BUTTON_LONG_PRESSED 900

// put to false to add movements to the program after its execution
#define PROGRAM_RESET_ALWAYS true

// store configuration and program within internal EEPROM
#define USE_PERSISTENT_MEMORY false

// memory capacity for program movements
#define MOVE_LIMIT 100

// milliseconds for the "pause" movement
#define PAUSE_MOVE_MILLIS 1000

// milliseconds delay before starting to move
#define DELAY_BEFORE_GO 500

// milliseconds to pause after every movement
#define AFTER_MOVEMENT_PAUSE 0

// point of view set when Vacalourabot is started
#define POV_INITIAL    POV_ESCORNABOT

// bluetooth serial
#define USE_BLUETOOTH true
#define BLUETOOTH_BAUDS 9600

// buzzer
#define USE_BUZZER true
#define BUZZER_PIN 2
#define PROGRAM_FINISHED_RTTL RTTL_FIDO
#define TONE_FREQ_UP 2637
#define TONE_FREQ_RIGHT 4434
#define TONE_FREQ_DOWN 3520
#define TONE_FREQ_LEFT 2217

// simple led
#define USE_SIMPLE_LED true
#define SIMPLE_LED_PIN 13

// keypad leds
#define USE_KEYPAD_LEDS false
#define KEYPAD_LED_PIN_UP A0
#define KEYPAD_LED_PIN_RIGHT A3
#define KEYPAD_LED_PIN_DOWN A2
#define KEYPAD_LED_PIN_LEFT A1
#define KEYPAD_LED_PIN_GO 13


//////////////////////////////////////////////////////////////////////
///// Steppers engine setup
//////////////////////////////////////////////////////////////////////

#ifdef ENGINE_TYPE_STEPPERS

// stepper pin setup (digital outputs)
#if !STEPPERS_SWAPPED_CABLES

// STANDARD: YELLOW - ORANGE - RED - PINK - BLUE
#define STEPPERS_MOTOR_RIGHT_IN1 5
#define STEPPERS_MOTOR_RIGHT_IN2 4
#define STEPPERS_MOTOR_RIGHT_IN3 3
#define STEPPERS_MOTOR_RIGHT_IN4 2
#define STEPPERS_MOTOR_LEFT_IN1 9
#define STEPPERS_MOTOR_LEFT_IN2 8
#define STEPPERS_MOTOR_LEFT_IN3 7
#define STEPPERS_MOTOR_LEFT_IN4 6

#else

// SWAPPED: ORANGE - YELLOW - RED - BLUE - PINK
#define STEPPERS_MOTOR_RIGHT_IN1 4
#define STEPPERS_MOTOR_RIGHT_IN2 5
#define STEPPERS_MOTOR_RIGHT_IN3 2
#define STEPPERS_MOTOR_RIGHT_IN4 3
#define STEPPERS_MOTOR_LEFT_IN1 8
#define STEPPERS_MOTOR_LEFT_IN2 9
#define STEPPERS_MOTOR_LEFT_IN3 6
#define STEPPERS_MOTOR_LEFT_IN4 7

#endif

#if IS_LUCI
#define STEPPERS_MOTOR_RIGHT_IN1 11
#define STEPPERS_MOTOR_RIGHT_IN2 10
#define STEPPERS_MOTOR_RIGHT_IN3 9
#define STEPPERS_MOTOR_RIGHT_IN4 8
#define STEPPERS_MOTOR_LEFT_IN1 7
#define STEPPERS_MOTOR_LEFT_IN2 6
#define STEPPERS_MOTOR_LEFT_IN3 5
#define STEPPERS_MOTOR_LEFT_IN4 4
#endif



// step calibration
// make sure you measure this values for your own Escornabot
#define WHEEL_DIAMETER 75.5f //mm Luci, wheel diameter
#define WHEEL_DISTANCE 80.0f //mm Luci, separation between the wheels (contact points in the ground)
// defaults
#define MOVE_DISTANCE_DEFAULT 100.0f //mm
#define TURN_DEGREES_DEFAULT 90.0f //°
// calculations
// Steppers have a gear ratio of 1:63.7, with 32 steps per turn, using half-stepping -> 63.7 * 32 * 2 = 4076.8
#define STEPPERMOTOR_FULLREVOLUTION_STEPS 4076.8f //number of steps for a full revolution of the axis
#define WHEEL_CIRCUNFERENCE float(PI * WHEEL_DIAMETER)
#define ROTATION_CIRCUNFERENCE float(PI * WHEEL_DISTANCE) // rotation circunference determined by the wheel distance
#define STEPPERS_STEPS_MM float(STEPPERMOTOR_FULLREVOLUTION_STEPS / WHEEL_CIRCUNFERENCE) // how many steps to move 1 mm
#define STEPPERS_STEPS_DEG float((ROTATION_CIRCUNFERENCE/360) * STEPPERS_STEPS_MM) // how many steps to rotate the robot 1 degree
// result values
#define STEPPERS_LINE_STEPS int16_t(STEPPERS_STEPS_MM * MOVE_DISTANCE_DEFAULT)
#define STEPPERS_TURN_STEPS int16_t(STEPPERS_STEPS_DEG * TURN_DEGREES_DEFAULT)

// stepping speed
#define STEPPERS_STEPS_PER_SECOND 1000 // 1500 max. with fully charged batteries
#define STEPPERS_ACCELERATION_STEPS 600
#define STEPPERS_MAX_DELTA_STEPS_PER_SECOND 1200 // Additional steps above STEPPERS_STEPS_PER_SECOND


#endif



//////////////////////////////////////////////////////////////////////
///// Button set digital
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_DIGITAL

// keypad pin setup (digital or analog inputs) (use 255 if key doesn't exist)
#define BS_DIGITAL_UP A0
#define BS_DIGITAL_RIGHT A1
#define BS_DIGITAL_DOWN A2
#define BS_DIGITAL_LEFT A3
#define BS_DIGITAL_GO A4
#define BS_DIGITAL_RESET 255

#endif // BUTTONS_DIGITAL



//////////////////////////////////////////////////////////////////////
///// Button set analog
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_ANALOG

#define BS_ANALOG_WIRES 2
//#define BS_ANALOG_WIRES 3

// keypad pin setup (analog input)
#define BS_ANALOG_PIN A4

// input values for each key pressed (0 if key doesn't exist)
// values pre-configured for this keypad -> https://github.com/mgesteiro/escornakeypad
#define BS_ANALOG_VALUE_UP 230
#define BS_ANALOG_VALUE_RIGHT 550
#define BS_ANALOG_VALUE_DOWN 470
#define BS_ANALOG_VALUE_LEFT 400
#define BS_ANALOG_VALUE_GO 600
#define BS_ANALOG_VALUE_RESET 0

#endif // BUTTONS_ANALOG



//////////////////////////////////////////////////////////////////////
///// Button set Bluetooth
//////////////////////////////////////////////////////////////////////

#ifdef USE_BLUETOOTH

// Arduino serial port (default is Serial, use Serial1 with Arduino Micro)
//#define BLUETOOTH_SERIAL    Serial
//#define BLUETOOTH_SERIAL    Serial1
//#define BLUETOOTH_SERIAL    Serial2
//#define BLUETOOTH_SERIAL    Serial3

#endif // USE_BLUETOOTH




//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


#endif // _CONFIGURATION_H

// EOF
