#include <avr/io.h>
#include <util/delay.h>
int main (void)
{
 DDRC = 0b11111111;
 Serial.begin(2000000);
 int var1 = 0b10100000;
 int var2 = 0b01100011;
 while (1) 
{

  int result2 = var1 & var2;
  Serial.println(result2, BIN);
  _delay_ms(5000);

 }
}
