#include<avr/io.h>
void delay(int);
void main()
{int i;
DDRB=0xff;

while(1)
{
for(i=1;i<=10;i++)
{ICR1=20000;
OCR1A=2000*(i);
TCCR1A=0X82;
TCCR1B=0X19;
delay(1);
}
}}

void delay(int x)
{
int i=0,j;
for(j=0;j<x;j++)
{for(i=0;i<20;i++)
{
TCCR0=0X05;
TCNT0=0Xce;
while(TIFR==0X00);
TIFR|=0x01;
}}
}
