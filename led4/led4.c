#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0xFF;
PORTD=0xFF;
_delay_ms(500);
PORTD=0x00;
_delay_ms(500);
main();

}
