#include<avr/io.h>
#include<util/delay.h>
void main()
{
int d1=1,d2=2,d3=4;
long int i=1;
DDRB=0xff;
DDRC=0xff;
DDRD=0xff;
int ld1=0x01;
int ld2=0x02;
int ld3=0x04;
while(1)
{if((i%d1)==0)
{
ld1=(~ld1)&0x01;
}

if((i%d2)==0)
{
ld2=(~ld2)&0x02;
}

if((i%d3)==0)
{
ld3=(~ld3)&0x04;
}
PORTD=(ld1|ld2|ld3);
i++;
_delay_us(1);
}
}
