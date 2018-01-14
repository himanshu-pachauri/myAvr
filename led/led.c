#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0xFF;
unsigned char x;
while(1)
{
PORTD=x;
x=x*2;
_delay_ms(1000);
PORTD=0;
_delay_ms(1000);
if(x==0)
{
x=1;
}
}

}
