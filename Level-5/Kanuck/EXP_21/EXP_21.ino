#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int main(void)
{
  int xval,yval,zval;
  Serial.begin(2000000);
  
  while(1)
{
  ADMUX =0x45;
  ADCSRA =0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  xval =ADCW;
  Serial.print("X-axis ");
  Serial.print(xval);
  ADMUX =0x46;
  ADCSRA =0xC7;
  while(checkbit(ADCSRA,bitn(ADSC)));
  yval =ADCW;
  Serial.print(" Y-axis ");
  Serial.print(yval);
  while(checkbit(ADCSRA,bitn(ADSC)));
  zval =ADCW;
  Serial.print(" Z-axis ");
  Serial.println(zval);
  _delay_ms(1000);
 }
}
