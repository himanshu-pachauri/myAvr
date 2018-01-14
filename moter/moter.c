#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0XFF;
DDRB=0X00;
while(1)
{
if((PINB&0X03)==0X01)
{
PORTD=0X01;//CLOAKWISE
}

if((PINB&0X03)==0X02)
{
PORTD=0X02;//COUNTER CLOAKWISE
}
if((PINB&0X03)==0X03)
{
PORTD=0X03;//STOP
}

}
}
