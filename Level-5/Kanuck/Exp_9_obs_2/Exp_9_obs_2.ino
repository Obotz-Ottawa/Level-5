#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
  DDRD = 0xFB;
  while(1)
 {
  if (PIND & 0x80)
  {
  PORTD = 0x80;
  _delay_ms(200);
  }
  PORTD = 0x00;
 }
}   
