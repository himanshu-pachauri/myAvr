#include<avr/io.h>
#include<util/delay.h>
void main()
{

PORTB=0xff;

while(1)
{
DDRD=0xff;
PORTD=0xff;
_delay_ms(1000);
PORTD=0x00;
_delay_ms(1000);

DDRD=0x00;
PORTD=0xff;
_delay_ms(1000);
PORTD=0x00;
_delay_ms(1000);

}
}
