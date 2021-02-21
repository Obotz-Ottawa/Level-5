#include <avr/io.h>
#include <util/delay.h>
int main (void)
{
 Serial.begin(2000000);
 int var1 = 0b00100000;
 while (1) 
{
  int result1 = ~(var1);
  Serial.println(result1, BIN);
  _delay_ms(5000);

 }
}
