#include<avr/io.h>
#include<util/delay.h>
void delay(unsigned char a )
{
for(;a--;)
{
timer0();
}
}
void timer0()
{
TCCR0=0x05;
TCNT0=255-49;
while(!(TIFR&0x01));
TIFR|=0x01;
TCCR0=0x00;
}
void main()
{
DDRD=0xff;
while(1)
{
PORTD=0x0f;
delay(20);
PORTD=0x00;
delay(20);
}

}

