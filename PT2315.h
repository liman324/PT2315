// liman324@yandex.ru rcl-radio.ru

#ifndef PT2315_H
#define PT2315_H

#define PT2315_address     0x40

#include <Arduino.h>
class PT2315
{
  public:
    PT2315();
    void set_volume(int vol);     // int 0...56 === 0...-70 dB step 1.25 dB
    void set_att_l(int att_l);   // int 0...24 === 0...-30 db step 1.25 dB  
    void set_att_r(int att_r);   // int 0...24 === 0...-30 db step 1.25 dB  
    void set_loudness(bool loud); // bool 0...1 = on...off  
    void setBass(int bass);      // int -7...+7 === -14...+14 dB step 2 dB
    void setTreble(int treble);  // // int -7...+7 === -14...+14 dB step 2 dB

 private:
    void writeWire(byte a);
};
	
#endif //PT2315_H
