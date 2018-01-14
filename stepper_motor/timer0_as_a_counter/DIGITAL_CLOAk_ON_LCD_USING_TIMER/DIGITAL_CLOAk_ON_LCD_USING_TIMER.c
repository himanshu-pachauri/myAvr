#include<avr/io.h>
#include<util/delay.h>
void lcmd(unsigned char);
void ldata(unsigned char);
void lint(unsigned char);
void delay();
void main()
{int i=0,j=0,k=0;
DDRD=0XFF;
DDRC=0XFF;
lcmd(0x38);
lcmd(0x06);
lcmd(0x01);
lcmd(0x0e);
lcmd(0x80);
lint(i);
ldata(':');
lint(j);
ldata(':');
lint(k);

while(1)
{
for(i=0;i<12;i++)//hour
{lcmd(0x80);
lint(i);

for(j=0;j<60;j++)//minute
{
lcmd(0x83);
lint(j);

for(k=0;k<60;k++)//second
{lcmd(0x86);
lint(k);
delay();
}}}}}
void delay()
{

int i=0;
for(i=0;i<3700;i++)
{TCNT0=0X06;
TCCR0=0X01;
while((TIFR&0X01)==0);
TIFR|=1;

}}
void lcmd(unsigned char x)
{
PORTD=x;
PORTC=0x04;
_delay_ms(5);
PORTC=0;
}
void ldata(unsigned char x)
{
PORTD=x;
PORTC=0x05;
_delay_ms(5);
PORTC=0x01;



}
void lint(unsigned char x)
{int a;
a=x%10;
x/=10;
ldata(x+48);
ldata(a+48);
}

