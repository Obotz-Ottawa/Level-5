#include <avr/io.h>
#include <util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int main(void)
{
  int leftIR,rightIR;
  DDRB = 0xFF;
  Serial.begin(2000000);
  while(1)
{
  ADMUX = 0x40;
  ADCSRA = 0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  rightIR = ADCW;
  ADMUX = 0x41;
  ADCSRA = 0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  leftIR = ADCW;
  Serial.println(leftIR);
  Serial.println(rightIR);

  if(rightIR > 380 && leftIR > 380)
  {
    PORTB = 0b01100000;
    _delay_ms(500);
  }
    if(rightIR < 380 && leftIR < 380)
  {
    PORTB = 0b10010000;
    _delay_ms(500);
  }
  if(rightIR > 380 && leftIR < 380)
  {
    PORTB = 0b01010000;
    _delay_ms(500);
  } 
  if(rightIR < 380 && leftIR > 380)
  {
    PORTB = 0b10100000;
    _delay_ms(500);
}
}
}  
