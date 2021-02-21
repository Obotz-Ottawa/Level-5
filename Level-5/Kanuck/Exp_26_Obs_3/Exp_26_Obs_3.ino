#include <LCD.h>
#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))

int main(void)
{
  LCD lcd;
  lcd.init();
  Serial.begin(2000000);
  while(1)
{
  ADMUX =0x42;
  ADCSRA =0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  Serial.println(ADCW);
  lcd.cmd(0x01);
  lcd.line1(0);  
  lcd.showvalue(ADCW);
  _delay_ms(500);
  {
  ADMUX =0x41;
  ADCSRA =0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  Serial.println(ADCW);
  lcd.cmd(0x01);
  lcd.line2(0); 
  lcd.showvalue(ADCW);
  _delay_ms(500);
  }
 }
}
