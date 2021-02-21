#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int main(void)
{
  Serial.begin(2000000);
  TCCR0 =0x6B;
  DDRB =0xFF;
  DDRD =0x00;
  OCR0 =0;
  while(1)
 {
  if (checkbit(PIND,bitn(2)))
 {
  OCR0 = OCR0 + 50;
  _delay_ms(200);
  Serial.println(OCR0);
  } 
 }
} 
