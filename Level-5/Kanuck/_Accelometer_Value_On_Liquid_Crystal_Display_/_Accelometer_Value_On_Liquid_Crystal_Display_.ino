#include <LCD.h>
#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))

int main(void)
{
  LCD lcd;
  lcd.init();
  while(1)
{  
  int xval,yval,zval;
  xval = ADCW;
{
  ADMUX =0x45;
  ADCSRA =0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  lcd.cmd(0x01); 
  lcd.showvalue(ADCW);
  _delay_ms(500);
  }
 }
}
