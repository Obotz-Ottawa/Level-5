#include <LCD.h>
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
  LCD lcd;
  lcd.init();

  while(1)
  {
    for(int i=0;i<16;i++)
  {
    lcd.cmd(0x01);
    lcd.line1(i);
    lcd.string("Hello");
    _delay_ms(500);
  }
    for(int u=16; u>0; u--)
    {
    lcd.cmd(0x01);
    lcd.line2(u);
    lcd.string("World");
    _delay_ms(500);
  }
 }
} 
