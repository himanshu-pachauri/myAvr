#include<avr/io.h>
#include<util/delay.h>
void delay();
void main()
{
DDRD=0XFF;
while(1)
{
PORTD=0XFF;
delay();
PORTD=0X00;
delay();


}
}

void delay()
{
int i=0;
for(i=0;i<(15625/5);i++)
{TCCR0=0X03;
TCNT0=0X7D;
while(TIFR==0X01);
TIFR&=0XFe;
}
}
