#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BITN(BIT_NUM)               (0x01 << (BIT_NUM))
#define CHECK_BIT(PORT, BIT_NUM)    ((PORT) & (BITN(BIT_NUM)))
#define KEY5 0x01FEB04F

int count = 0;
long keycode = 0;
int main()
{
  DDRB = 0xFB;
  DDRD = 0x01;
  DDRC = 0xFF;
  int on_time = 0;
  int off_time = 0;
  int bit_position = -2;
  while(true)
  {
    while (!(CHECK_BIT(PINB, 2))){
      on_time++;
      if(on_time == 1){
        bit_position++;
        if (bit_position >= 1 && bit_position <=32){
          if(off_time > 700){
            keycode |= (long)1<<(32 - bit_position);
          }
        }
        if (bit_position >= 32){
          compare();
          bit_position = -2;
          keycode = 0;
        }
      }
      off_time = 0;
    }

    while (CHECK_BIT(PINB, 2))
    {
      off_time++;
      on_time = 0;
      if (off_time > 6000){
        off_time = 0;
        bit_position = -2;
      }
    }
  }
}

void compare()
{
  if (keycode == KEY5){
    count++;
    _delay_ms(500);
  }
  if(count == 1){
    PORTC = 0xFF;
    PORTD = 0x00;
  }
  if(count == 2){
    PORTC = 0x00;
    PORTD = 0x01;
    count = 0;
  }
}
