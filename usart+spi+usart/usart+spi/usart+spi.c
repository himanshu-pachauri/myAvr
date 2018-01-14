//USART+SPI+Master
#include<avr/io.h>
#include<util/delay.h>
void lstr(unsigned char*);
void main()
{

//usart
UCSRB=(1<<TXEN)|(0<<UCSZ2)|(1<<RXEN);//RX&TX ENABLE
UCSRC=(1<<URSEL)|(3<<UCSZ0);
UBRRH=0X00;
UBRRL=51;
lstr("USART+SPI//MASTER");
//spi+master
DDRB=(1<<DDB2)|(1<<DDB3)|(0<<DDB4)|(1<<DDB5);
SPCR=(1<<SPE)|(1<<DORD)|(1<<CPHA)|(1<<MSTR);
while(1)
{
while((UCSRA&(1<<RXC))==0);
SPDR=UDR;
UCSRA=(1<<RXC);
while((SPSR&(1<<SPIF))==0);
SPSR|=(1<<SPIF);




}




}
void lstr(unsigned char *p)
{
while(*p!=0)
{
UDR=*p;
while((UCSRA&(1<<TXC))==0);
UCSRA=0x40;
p++;

}

}
