#include <avr/io.h>              
#include <util/delay.h>           
#define setbit(x,y)(x|=y)         //Define macro to make a bit/bits high
#define clearbit(x,y)(x&=~y)      //Define macro to make a bit/bits low
#define bitn(p)(0x01<<(p))        //Define macro for bit position 

int main(void)
  {
  setbit(DDRD, 0xFF);
  setbit(DDRB, bitn(4));
  while(1)
  {
  setbit(PORTD, bitn(0));
  _delay_ms(1000);
  clearbit(PORTD, bitn(0));

   setbit(PORTD, bitn(1));
  _delay_ms(1000);
  clearbit(PORTD, bitn(1));
   
   setbit(PORTD, bitn(4));
  _delay_ms(1000);
  clearbit(PORTD, bitn(4));   
  }
}
