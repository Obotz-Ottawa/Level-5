#include <Arduino.h>
#include <util/delay.h>
#define setbit(x,y) (x|=y)
#define clearbit(x,y)(x&=~y)
#define bitn(p) (0x01<<(p))
int main (void)
{
  setbit(DDRD, 0xFF);
  for(int i = 0;i<5;i++)
   {
  setbit(PORTD, 0x01);
  _delay_ms(500);
  clearbit(PORTD, 0x01);
  _delay_ms(500);
   }
 for(int i = 0;i<5;i++)
 {
 setbit(PORTD, 0x02);
  _delay_ms(500);
  clearbit(PORTD, 0x02);
  _delay_ms(500);
  }
 }
