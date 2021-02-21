#include<avr/io.h>
#include<util/delay.h>
int var = 0;
int angle = 0;
int main (void)
{
  TCCR0 = 0x03;
  DDRB = 0xFF;
  DDRD = 0xFF;
  while(1)
  {
  angle = 0; 
  servo();
  PORTD = 0b00000010;
  _delay_ms(500);
  angle = 90; 
  servo();
  PORTD = 0b00000001;
  _delay_ms(500);
 }
}
void servo()
 {
  for(int i = 0; i<20; i++)
  {
   int tem = (5 + (angle/10));
   TCNT0 = 0;
   while(var < 200)
  {
   if(TCNT0 == 25)
   {
    var ++;
    TCNT0 = 0;
  }
  if(var == tem)
  {
    PORTB = 0x00;
  }
 }
 if(var == 200)
 {
  PORTB = 0xFF;
  var = 0;
   
  }
 }
}
