#include<avr/io.h>    //arduino
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int main(void)
{
  DDRD = 0b11111011;   //initializing what is the input and output
  while(1)             //forever loop
{
  if(checkbit(PIND, bitn(2))) //if D2 pressed
{ 
  PORTD = 0b00000001;    //led red on
  _delay_ms(200);        //wait a certain amount of seconds
}
  else    //else
{
  PORTD = 0b00000010;    //led green on
 } 
}
}
