#include<avr/io.h>
#include<util/delay.h>
void delay(int );
void main()
{
DDRD=0XFF;
while(1)
{
PORTD=0XFF;
delay(1);
PORTD=0X00;
delay(1);


}
}

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
