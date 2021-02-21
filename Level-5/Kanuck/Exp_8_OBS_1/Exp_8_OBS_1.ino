#include <avr/io.h>
#include <util/delay.h>
#define setbit(x,y) (x|=y)
#define clearbit(x,y)(x&=~y)
#define bitn(p) (0x01<<(p))
int main (void)
{
  setbit(DDRD, 0xFF);    //to set bit
  for(int i = 0;i<5;i++) //loop
{
  setbit(PORTD, 0x03);
  _delay_ms(500);
  clearbit(PORTD, 0x03);
  _delay_ms(500);
 }
}
