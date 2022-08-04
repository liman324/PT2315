#include <Arduino.h>
#include <Wire.h>
#include "PT2315.h"

PT2315::PT2315(){
	Wire.begin();
}

void PT2315::set_volume(int vol){
  writeWire(vol);
  Serial.println(vol,BIN);
}

void PT2315::set_att_l(int att_l){
  att_l = 0b10000000 + att_l;
  writeWire(att_l);
}

void PT2315::set_att_r(int att_r){
  att_r = 0b10100000 + att_r;
  writeWire(att_r);
}

void PT2315::set_loudness(bool loud){
  writeWire(0b01000000 + (loud << 2));
}

void PT2315::setBass(int bass){
  switch (bass){
    case -7: bass = 0b01100000;break;
    case -6: bass = 0b01100001;break;
    case -5: bass = 0b01100010;break;
    case -4: bass = 0b01100011;break; 
    case -3: bass = 0b01100100;break;
    case -2: bass = 0b01100101;break;
    case -1: bass = 0b01100110;break;
    case 0:  bass = 0b01100111;break;
    case 1:  bass = 0b01101110;break;
    case 2:  bass = 0b01101101;break;
    case 3:  bass = 0b01101100;break;
    case 4:  bass = 0b01101011;break;
    case 5:  bass = 0b01101010;break;
    case 6:  bass = 0b01101001;break;
    case 7:  bass = 0b01101000;break;
  }
  writeWire(bass);
}

void PT2315::setTreble(int treb){
  switch (treb){
    case -7: treb = 0b01110000;break;
    case -6: treb = 0b01110001;break;
    case -5: treb = 0b01110010;break;
    case -4: treb = 0b01110011;break; 
    case -3: treb = 0b01110100;break;
    case -2: treb = 0b01110101;break;
    case -1: treb = 0b01110110;break;
    case 0:  treb = 0b01111111;break;
    case 1:  treb = 0b01111110;break;
    case 2:  treb = 0b01111101;break;
    case 3:  treb = 0b01111100;break;
    case 4:  treb = 0b01111011;break;
    case 5:  treb = 0b01111010;break;
    case 6:  treb = 0b01111001;break;
    case 7:  treb = 0b01111000;break;
  }
  writeWire(treb);
}

void PT2315::writeWire(byte a){
  Wire.beginTransmission(PT2315_address);
  Wire.write (a);
  Wire.endTransmission();
}
