#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int main(void)
{
  DDRB =0b11111111;
  DDRD =0b00000000;
  int count =0;
  while(1)
{
  if(checkbit(PIND, bitn(2)))
  {
    count++;
    _delay_ms(500);
  }

  if (count == 1)
  {
    PORTB = 0b00100000;
  }

  if(count == 2)
  {
    PORTB = 0b01000000;
  }

  if (count == 3)
  {
    count = 1;
    PORTB = 0b00000000;
  }
 }
} 
