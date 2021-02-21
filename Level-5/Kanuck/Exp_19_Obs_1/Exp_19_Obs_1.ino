#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int main (void)
{
  int left,right;
  DDRD =0xFF;
  Serial.begin(2000000);
  DDRC =0xFF;
  while(1)
{
  ADMUX =0x40;
  ADCSRA =0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  right = ADCW;
  ADMUX =0x41;
  ADCSRA =0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  left =ADCW;
  Serial.println(left);
  Serial.println(right);
   if(right<45)
  {
    PORTB =0xFF;
  }
    else
  {
    PORTB =0x00;  
  }
    if(left<45)
  {
    PORTC =0xFF;
  }
    else
  {
    PORTC =0x00;
  }
 }
}   
  
