//spi(MASTER)+usart
#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
void spi(unsigned char x);
void spiMinti(void);
void lstr1(unsigned char *p);
void  main()
{

DDRB=(1<<2)|(1<<3)|(0<<4)|(1<<5);
SPCR=(1<<SPE)|(1<<DORD)|(1<<MSTR)|(0<<SPR0)|(0<<SPR1)|(0<<CPHA);
_delay_ms(100);
lstr1("OK");

UCSRB=(1<<RXEN);
UCSRC|=(1<<URSEL);
UBRRH=0X00;
UBRRL=6;

_delay_ms(1000);
while(1)
{
spi('H');
while((UCSRA&(1<<RXC))==0X00);
spi(UDR);
UCSRA|=0x80;

}


}
void spiMinti(void)
{DDRB=(1<<2)|(1<<3)|(0<<4)|(1<<5);
SPCR|=(1<<SPE)|(1<<DORD)|(1<<MSTR)|(1<<CPHA);
}
void spi(unsigned char x)
{SPDR=x;
while((SPSR&(1<<SPIF))==0);
//ldata(SPDR);
SPSR|=(1<<SPIF);

}
void lstr1(unsigned char *p)
{while(*p!=0)
{
spi(*p);
_delay_ms(10);
p++;
}
}
