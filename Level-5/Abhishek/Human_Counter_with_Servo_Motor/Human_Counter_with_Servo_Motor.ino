#include <avr/io.h>
#include <util/delay.h>

#define IR_THRESHOLD 500

#define BITN(BIT_NUM)               (0x01 << (BIT_NUM))
#define SET_BIT(PORT, BIT_NUM)      ((PORT) |= (BITN(BIT_NUM)))
#define CHECK_BIT(PORT, BIT_NUM)    ((PORT) & (BITN(BIT_NUM)))
#define CLEAR_BIT(PORT, BIT_NUM)    ((PORT) &= (~(BITN(BIT_NUM))))

void servo(int angle)
{
  int tem = 0;
  int var = 0;
  for(int i = 0; i < 20; i++){
    tem = (5 +(angle/10));
    TCNT0 = 0;
    while(var < 200){
      if (TCNT0 == 25){
        var++;
        TCNT0 = 0;
      }
      if(var == tem){
        PORTB = 0x00;
      }
    }
    if(var == 200){
      PORTB = 0x0F;
      var = 0;
    }
  }
}

int main (void)
{
  int ir = 0;
  int person = 0; //if person is in front of ir sensor, value is 1, if no person is infront of sensor, value is 0
  int count = 0;
  Serial.begin(2000000);
  DDRB = 0xFF;
  TCCR0 = 0x03;

  servo(90);
  while (true) {
    //checking and storing right ir sensor
    ADMUX = 0x41;
    ADCSRA = 0xC7;
    while(CHECK_BIT(ADCSRA, ADSC)){
      ir = ADCW;
    }

    if(ir < IR_THRESHOLD){
      person = 1;
    }

    if(ir > IR_THRESHOLD && person == 1 && count < 10){
      count += 1;
      Serial.println(count);
      person = 0;
      _delay_ms(500);
    }

    if(count == 10){
      servo(0);
      SET_BIT(PORTB, 4);
    }

    if(CHECK_BIT(PIND, 2)){
      CLEAR_BIT(PORTB, 4);
      count = 0;
      servo(90);
    }
  }
}
