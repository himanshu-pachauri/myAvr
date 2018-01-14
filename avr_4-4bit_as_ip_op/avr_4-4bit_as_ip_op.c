#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0XFF;
PORTD=0;
while(1)
{
PORTD=1;
_delay_ms(1000);
PORTD=0;
_delay_ms(1000);
}



}
