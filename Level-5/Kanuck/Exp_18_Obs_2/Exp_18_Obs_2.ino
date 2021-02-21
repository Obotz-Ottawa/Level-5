#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int main(void)
{
  int HI;
  DDRB = 0xFF;
  DDRD = 0xFF;
  Serial.begin(2000000);
  while(1)
 {
  ADMUX =0x45;
  ADCSRA = 0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  HI=ADCW;
  Serial.println(HI);
  if(HI<25)
 {
  PORTB =0xFF;
  PORTD =0x00;
 }
  else
 {
  PORTB =0x00;
  PORTD =0xFF; 
 }
}
}
