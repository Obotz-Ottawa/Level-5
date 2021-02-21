#include <avr/io.h>
#include <util/delay.h>
int main (void)
{
  Serial.begin(2000000);
  while(1)
  
{
  int var1 = 0b10100000;
  int var2= 0b11111111;
  
  int result1 = var2 || var1;
  Serial.println(result1, BIN);
  _delay_ms(5000);

  
}
}
