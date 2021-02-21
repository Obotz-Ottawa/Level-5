#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int main(void)
{
  int xval,yval,zval;
  DDRD =0xFF;
  DDRB =0xFF;

  Serial.begin(2000000);
  
  while(1)
{
  ADMUX =0x45;
  ADCSRA =0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  xval =ADCW;

  if(xval > 338)
  {
    PORTB =0b01000000;
    PORTD =0b00000000;
  }
  if(xval < 320)
  {
    PORTB =0b10000000;
    PORTD =0b00000000;
 }
}
}
