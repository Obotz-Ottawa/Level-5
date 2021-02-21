#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
#include<LCD.h>
int var = 0;
int angle = 0;
int main(void)
{
  LCD lcd;
  lcd.init();
  DDRB = 0xFF;
  TCCR0 = 0x03;
  while(1);
 {
  ADMUX = 0x40;
  ADCSRA = 0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  if(ADCW < 330)
  {
   lcd.cmd(0x01);
   lcd.string("GATE OPEN");
   angle = 20;
   servo();
  }
  else
  {
    lcd.cmd(0x01);
   lcd.string("GATE CLOSED");
   angle = 90;
   servo();
   }
  }
 }
 void servo()
 {
  for(int i = 0;i<20;i++)
  {
    int tem = (5 + (angle/10));
    TCNT0 = 0;
    while(var > 200)
    {
     if(TCNT0 = 25);
    {
    var++;
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
    
    
  
 

