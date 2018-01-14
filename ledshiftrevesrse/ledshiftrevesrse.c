#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0xFF;
unsigned char x=128,y=1;
while(1)
{
PORTD=x;
PORTD=y;
x=x/2;
y=y*2;
_delay_ms(1000);
PORTD=0;
_delay_ms(1000);
if((x==0)||(y==0))
{
x=128;
y=1;
}

}

}
