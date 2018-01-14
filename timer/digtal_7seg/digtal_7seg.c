#include<avr/io.h>
unsigned char a[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D , 0x7D, 0x07, 0x7F, 0x6F};
void timer0(int x)
{
TCCR0=0x05;
TCNT0=0XFF-x;
while(TIFR&(1<<TOV0)==0);
TIFR|=(1<<TOV0);
TCNT0=0X00;


}

void main()
{int i,j,k,l;
DDRB=0XFF;
DDRD=0XFF;
while(1)
{
for(i=0;i<24;i++)
{
for(j=0;j<60;j++)
{for(k=0;k<60;k++)
{
for(l=0;l<500;l++)
{
PORTB=(1<<0);
PORTD=~a[k%10];
timer0(2);
timer0(500);
/*
PORTB=~(1<<1);
PORTD=~a[k/10];
timer0(2);

PORTB=~(1<<2);
PORTD=a[j%10];
timer0(2);

PORTB=~(1<<3);
PORTD=a[j/10];
timer0(2);

PORTB=~(1<<4);
PORTD=a[i%10];
timer0(2);

PORTB=~(1<<5);
PORTD=a[i/10];
timer0(2);
*/
}}

}

}


}
}
