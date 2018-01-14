#include<avr/io.h>
#include<util/delay.h>
void main()
	{
DDRD=0xFF;
unsigned char i=1;
while(1)
{

PORTD=i;
i=(i*2)|i;
_delay_ms(500);
PORTD=0x00;
		_delay_ms(500);

if(i==0xff)
{
PORTD=0xff;
_delay_ms(500);
PORTD=0x00;
_delay_ms(500);


i=1;
		
}



}

}
