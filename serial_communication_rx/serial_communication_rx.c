#include<avr/io.h>
#include<util/delay.h>
void ldata(unsigned char);
void lcmd(unsigned char);
str(unsigned char *);
void main()
{//unsigned char i=0;
DDRB=0XFF;
DDRC=0XfF;
unsigned char a[]="Himanshu have a hp laptop";

lcmd(0x38);
lcmd(0x01);
lcmd(0x06);
lcmd(0x0e);
{
lcmd(0x80);
str("SOFCON INDIA");
lcmd(0xc0);
str("Pvt. LIMITED CO.");

}
}
void ldata(unsigned char x)
{
PORTB=x;
PORTC=0x05;
_delay_ms(10);
PORTC=0x01;
}

void lcmd(unsigned char x)
{
PORTB=x;
PORTC=0x04;
_delay_ms(10);
PORTC=0;
}
str(unsigned char *p)
{
	while(*p)
	{
		ldata(*p);
		p++;
	}
}
