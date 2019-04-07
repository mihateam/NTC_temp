#ifndef NTC_temp_h
#define NTC_temp_h
 
#include <Arduino.h>

class NTC_temp
{
public:
 NTC_temp(int pin, int value);
 float temp(char unit);
 
private:
 int r_value;
 uint8_t ntc_pin;
};
 
#endif