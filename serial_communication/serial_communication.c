/*TTTTTTTTTTTTransmitter*/

#include<avr/io.h>
#include<util/delay.h>
void main()
{
unsigned char a[10]="HIMANSHU",i=0;
_delay_ms(1000);
UCSRB=(1<<RXEN);
UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
UBRRL=51;//9600 BAUD RATE
while(1)
{
while(UCSRA&(1<<TXC)==0);
UCSRA=(1<<TXC);
ldata(UDR);
}
}
