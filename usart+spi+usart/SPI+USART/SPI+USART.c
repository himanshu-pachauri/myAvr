//SPI+usart++++slave
#include<avr/io.h>
#include<util/delay.h>
void lstr(unsigned char*);
void main()
{int x;
UCSRB=(1<<TXEN)|(0<<UCSZ2)|(1<<RXEN);//RX&TX ENABLE
UCSRC=(1<<URSEL)|(3<<UCSZ0);
UBRRH=0X00;
UBRRL=51;
lstr("SPI + USART//SLAVE");///USART OKK TRANSMITER
lstr(10);
lstr("SPI + USART//SLAVE");
//spi+slave
DDRB=(0<<DDB2)|(0<<DDB3)|(1<<DDB4)|(0<<DDB5);
SPCR=(1<<SPE)|(1<<DORD)|(1<<CPHA);
while(1)
{
while((SPSR&(1<<SPIF))==0);
SPSR|=(1<<SPIF);
UDR=SPDR;
while((UCSRA&(1<<TXC))==0);
UCSRA=0x40;



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
