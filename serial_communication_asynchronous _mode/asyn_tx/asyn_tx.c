/*******transmiterr*/
#include<avr/io.h>
#include<util/delay.h>
int main()
{ DDRB=0XFF;
_delay_ms(1000);
UCSRB=(1<<TXEN);
UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0)|(1<<UMSEL);
UBRRH=0x00;
UBRRL=51;//BAUD RATE 9600
while(1)
{
UDR='A';
while((UCSRA&(1<<TXC))==0);
UCSRA=(1<<TXC);
PORTB=0X0F;
}



}
