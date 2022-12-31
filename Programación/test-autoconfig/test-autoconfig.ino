/*
 * Testing Luci's keypad autoconfiguration
 * 
 * If a key is being pressed during start-up, autoconfig mode kicks in
 */

#include <Escornabot-lib.h>

Escornabot luci;
#define EB_KP_EEPROM_VALUES_INDEX (uint16_t *)(E2END - 2 * 5 + 1)

void setup() {
  Serial.begin(9600);
  luci.init();  // give a chance to execute autoconfig procedure

  // print EEPROM stored values
  uint16_t *eeprom_index = EB_KP_EEPROM_VALUES_INDEX;
  Serial.print((uint16_t)eeprom_index, HEX); Serial.print("  FW -> ");
  Serial.println(eeprom_read_word(eeprom_index++));
  
  Serial.print((uint16_t)eeprom_index, HEX); Serial.print("  TL -> ");
  Serial.println(eeprom_read_word(eeprom_index++));
  
  Serial.print((uint16_t)eeprom_index, HEX); Serial.print("  GO -> ");
  Serial.println(eeprom_read_word(eeprom_index++));
  
  Serial.print((uint16_t)eeprom_index, HEX); Serial.print("  TR -> ");
  Serial.println(eeprom_read_word(eeprom_index++));
  
  Serial.print((uint16_t)eeprom_index, HEX); Serial.print("  BW -> ");
  Serial.println(eeprom_read_word(eeprom_index));
}

void loop() {
  // put your main code here, to run repeatedly:

}
