#include <NTC_temp.h>

NTC_temp ntc(A0, 10000); //pin i vrijednost otpornika na 20 ℃

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  Serial.print("Temperatura je: ");
  Serial.print(ntc.temp('C'));
  Serial.println(" ℃");

  Serial.print("Temperatura je: ");
  Serial.print(ntc.temp('F'));
  Serial.println(" ℉");
  delay(1000);
}
