#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0b00000001<<(p))
int main(void)
{
  DDRB = 0b11111011;
  while(1)
{
  if(checkbit(PIND, bitn(2)))
{ 
  PORTB = 0b10000000;
  _delay_ms(200);
}
  else
{
  PORTB = 0b00000000;
 } 
}
}
