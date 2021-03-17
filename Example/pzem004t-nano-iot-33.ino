#include <PZEM004Tv30.h>
#include "wiring_private.h"

PZEM004Tv30 pzem(Serial1, PZEM_DEFAULT_ADDR);

void setup(void) {

  Serial1.begin(9600);
  Serial.begin(9600);
  while (!Serial);
  Serial.print("Reset Energy");
  pzem.resetEnergy();
  Serial.print("Set address to 0x42");
  pzem.setAddress(0x42);

  delay(100);
}

void loop() {
  float volt = pzem.voltage();
  float cur = pzem.current();
  float powe = pzem.power();
  float ener = pzem.energy();
  float freq = pzem.frequency();
  float pf = pzem.pf();
  Serial.print(String("Current_sensor: ") + volt + "," + cur + "," + powe + "," + ener + "," + freq + "," + pf);
  Serial.println("");

  delay(1000);
}
