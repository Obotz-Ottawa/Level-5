#include <LCD.h>

#include<LCD.h>
#include<avr/io.h>
#include<util/delay.h>

int main(void)
{
  LCD lcd;
  lcd.init();
  lcd.showvalue(0x8D);
}
