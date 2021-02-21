#include <LCD.h>

#include<LCD.h>
#include<avr/io.h>
#include<util/delay.h>

int main(void)
{
  LCD lcd1;
  lcd1.init();
  lcd1.string("1a2b3c4d");
}
