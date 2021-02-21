#include <avr/io.h>
#include <util/delay.h>
#define checkbit(x,y) ((x)&(y))
#define bitn(p) (0x01<<(p))
int var = 0;
int angle = 0;
int main(void)
{
  char data;
  TCCR0 = 0x03;
  DDRD = 0xF0;
  UCSRA = 0x00;
  UCSRB = 0x18;
  UCSRC = 0x06;
  UBRRH = 0x00;
  UBRRL = 0x67;
  while(1)
  {
  while(!(checkbit(UCSRA,bitn(RXC))));
  data = UDR;
    if((checkbit(PIND,bitn(2))))
  {
    servo();
      angle = 90;
  }  
    if((checkbit(PIND,bitn(3)))) 
  {
    servo();
      angle = 0;
  }
  void servo();
 { 
  for(int i = 0;i<20;i++)
  {
    int tem = (5 + (angle/10));
    TCNT0 = 0;
    while(var < 200)
    {
     if(TCNT0 == 25)
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
