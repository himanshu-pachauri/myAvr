#include<avr/io.h>
#include<util/delay.h>
void main()
{int i=0;
DDRC=0X0F;
while(1)
{
if(PINC&0x10)
{
PORTC|=0x01;
PORTC&=0xf7;
_delay_ms(200);

PORTC|=0x02;
PORTC&=0xfe;
_delay_ms(200);


PORTC|=0x04;
PORTC&=0xfd;
_delay_ms(200);


PORTC|=0x08;
PORTC&=0xfb;
_delay_ms(200);

}
else
{
PORTC&=0XF0;
}
}
}
