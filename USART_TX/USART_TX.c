////USART_TRANSMITEER
#include<avr/io.h>
#include<util/delay.h>
void main()
{
UCSRC|=(0<<UMSEL)|(0<<UCSZ2)|(1<<UCSZ1)|(1<<UCSZ0);//SYNCHRONOUS MODE |8BIT CHARACTER SIZE
UCSRB=(1<<TXEN)|(0<<UMSEL);
UBRRL=51;
while(1)
{
UDR='a';

while((UCSRA&(1<<TXC))==0);

UCSRA|=1<<TXC;
_delay_ms(1000);

}

}
