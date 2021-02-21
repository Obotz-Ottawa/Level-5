#include <avr/io.h>
#include <util/delay.h>
int main (void)
{
  Serial.begin(2000000);
  DDRC = 0b11111111;
  while(1)
  
{
  int var = 0b1100000;
  int var1 = 0b00100000;
  PORTC = 0b10101010;

  int result1 = ! PORTC ;
  Serial.println(result1, BIN);
  _delay_ms(5000);

}
}
