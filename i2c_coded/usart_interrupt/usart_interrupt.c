#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
ISR(USART_RXC_vect )
{
PORTB=UDR;
}
void main()
{SREG|=0x80;
DDRB=0xff;
//cli();
//sei();
UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
//UCSRC=(1<<URSEL);
UBRRL=51;
UCSRB=(1<<RXEN)|(1<<RXCIE);

while(1);
}
