#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
ISR (INT0_vect)
{
PORTB=0xff;


}
void main()
{DDRB=0xff;
DDRC=0xff;
SREG|=0x80;
GICR|=0x40;
while(1)
{
PORTB=0;

}

}
