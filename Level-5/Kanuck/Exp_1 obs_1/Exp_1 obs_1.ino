#include <avr/io.h>
#include <util/delay.h>
int main (void)
{
  DDRB = 0b10110011;

 
  while (1)
  {
PORTB = 0b10110011;
_delay_ms(1000);
PORTB = 0b00000000;
_delay_ms(1000);
  }
}
