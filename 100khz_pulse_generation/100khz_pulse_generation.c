#include<avr/io.h>
#include<util/delay.h>
void delay();
void main()
{
DDRC=0XFF;
while(1)
{
PORTC|=0x01;
TCCR2=0X01;
TCNT2=0xff-5;
while((TIFR&0X40)==0);
TIFR|=0x40;

PORTC&=0xfe;
TCCR2=0X01;
TCNT2=0xff-5;
while((TIFR&0X40)==0);
TIFR|=0x40;
}
}

