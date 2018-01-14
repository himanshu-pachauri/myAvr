#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0XFF;
PORTD=0x80;
PORTD|=0x10;
PORTD&=~0x10;



}
