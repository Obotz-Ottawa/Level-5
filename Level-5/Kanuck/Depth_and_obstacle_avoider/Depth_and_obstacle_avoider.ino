we#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x)&(y))
#define bitn(p)(0x01  << (p))
double distance;
int main(void)
{
  int count; 
  int leftIR; 
  int rightIR; 
  DDRD = 0xFF;
  DDRB = 0x01;
  DDRB = 0xFF;
  TCCR0=0x6B;
  Serial.begin(9600);
  int pinstate;
  while(1)
 {
  ADMUX = 0x40;
  ADCSRA = 0xC7;
  while(checkbit(ADCSRA, bitn(ADSC)));
  rightIR = ADCW;
  ADMUX = 0x41;
  ADCSRA = 0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  leftIR = ADCW;
  Serial.println(leftIR);
  Serial.println(rightIR);

  
  trigger();
  while(checkbit(PINB, bitn(1)))
  {
    TCCR1A = 0x00;
    TCCR1B = 0x03;
    pinstate = 1;
  }
  while(!checkbit(PINB,bitn(1))&& pinstate == 1)
  {
   TCCR1B = 0x00;
   count = TCNT1;
   distance = (count*0.008575);
   Serial.println(distance);
   compare();
   pinstate = 0;
   TCNT1 = 0; 
  }
  if(rightIR > 320 && leftIR > 320)
  {
    PORTD = 0b00000000;
    _delay_ms(300);
  }
    if(rightIR < 320 && leftIR < 320)
  {
    PORTD = 0b01100000;
    _delay_ms(300);
  }
  if(rightIR > 320 && leftIR < 320)
  {
    PORTD = 0b01010000;
    _delay_ms(300);
  } 
  if(rightIR < 320 && leftIR > 320)
  {
    PORTD = 0b10100000;
    _delay_ms(500);
  }
 }
}
void trigger()
{
   PORTB = 0x00;
   _delay_us(10);
   PORTB = 0x01;
   _delay_us(10);
   PORTB = 0x00;
}
void compare()
{
  if(distance <= 5)
  {
    PORTD =0b10100000;
    _delay_ms(500);
    PORTD =0b10100000;
    _delay_ms(500);
  }
 else
  {
    PORTD =0b01100000;
  }
 }
