#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTD
#define rs 0
#define rw 1
#define en 2
#include"lcd.h"
void main()
{
DDRD=0xff;
linti();
//li2s(20);
lf2s1(55.999);

}
