#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
ISR(INT0_vect)
{
PORTC=0XFF;
_delay_ms(1000);
PORTC=0x00;
_delay_ms(1000);

}
void main()
{
DDRC=0XFF;
DDRB=0xff;
GICR=1<<INT0;
cli();
sei();
while(1)
{
PORTB=0XFF;
_delay_ms(1000);

PORTB=0X00;
_delay_ms(1000);

}

}
