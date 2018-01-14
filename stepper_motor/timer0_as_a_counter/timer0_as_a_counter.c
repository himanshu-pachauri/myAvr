#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>
void lcommand(char);
void lint (int);
void lstr(char *p);
void ldata(char);
void main()
{char c[7];
unsigned long int d=0;
DDRB=0xFF;
DDRC=0xFF;
lcommand(0x38);
lcommand(0x06);
lcommand(0x01);
lcommand(0x0e);
lcommand(0x80);
ldata('A');
TCNT0=0;
TCCR0=0x06;

while(1)
{if(d<1000000)
{lcommand(0x01);
d=d+TCNT0;
TCNT0=0;
sprintf(c,"%d",d);
lstr(c);
}
else
{
d=0;
}
}

}
void lcommand(char x)
{
PORTB=x;
PORTC=0x04;
_delay_ms(50);
PORTC=0x00;}

void ldata(char x)
{
PORTB=x;
PORTC=0x05;
_delay_ms(50);
PORTC=0x01;
}
void lstr(char *p)
{
while(*p!=0)
{
ldata((*p));
p++;
}
return 0;
}
