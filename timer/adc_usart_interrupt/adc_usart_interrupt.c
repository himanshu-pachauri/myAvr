#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define lcd PORTB
#define rs 0
#define rw 1
#define en 2
#include "lcd.h"
void uinti()
{
UBRRL=0x06;
UCSRB=(1<<RXEN);
UCSRB=(1<<RXCIE);
///UCSRA=(1<<RXC);

}



ISR (SIG_UART_RECV)
{
ldata(UDR);

}
void main()
{

SREG=1<<7;
DDRB=0xff;
uinti();
linti();
sei();
while(1)
{


}

}
