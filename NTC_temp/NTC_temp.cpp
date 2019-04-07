#include <Arduino.h>
#include "NTC_temp.h"

int Vo;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
 
NTC_temp::NTC_temp(int pin, int value){
 r_value = value;
 ntc_pin = pin;
}
 
float NTC_temp::temp(char unit){
  
  Vo = analogRead(ntc_pin);
  R2 = r_value * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  
  
  switch(unit){
    case 'C':
      Tc = T - 273.15;
      return Tc;
      break;    

    case 'F':
      Tf = (Tc * 9.0)/ 5.0 + 32.0;
      return Tf;
      break;

    default:
      return T;
      break;
 }
}
