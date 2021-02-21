#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int main (void)
{
  void Forward()
  PORTD = 0b01100000;
}

{
  void Backward()
  PORTD = 0b10010000;
}

{
  void Stop()
  PORTD = 0b00000000;
}

int main(void) {
  int yval;
  DDRD = 0xFF;
  DDRA = 0x00;
}

ADMUX = 0x46;
ADCSRA = 0xC7;
while (checkbit(ADCSRA, bit(ADSC)));
yval = ADCW;

if (yval > 380) {
  Forward();
}
else if (yval < 330) {
  backward
}
else {
  Stop();
}
}



