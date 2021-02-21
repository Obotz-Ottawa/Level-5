#include <avr/io.h>
#include <util/delay.h>
int count = 0;
int main (void)
  {
  Serial.begin(2000000);

  while (1)
  {
  Serial.println(count);
  _delay_ms(1000);
  count = count + 50000000;
  }
  
}
