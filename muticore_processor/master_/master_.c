//spi(MASTER)+usart
#include<avr/io.h>
#include<util/delay.h>
void vtstr2(unsigned char *p);
void vtdisp(unsigned char x);

void spi(unsigned char x);
void spiMinti(void);
void lstr1(unsigned char *p);
void  main()
{int x;
DDRC&=0XF8;
DDRD|=0XE0;
DDRB=(1<<2)|(1<<3)|(0<<4)|(1<<5);
SPCR=(1<<SPE)|(1<<DORD)|(1<<MSTR)|(0<<SPR0)|(0<<SPR1)|(0<<CPHA);
_delay_ms(100);
lstr1("OK");

UCSRB=(1<<RXEN)|(1<<TXEN);
UCSRC|=(1<<URSEL);
UBRRH=0X00;
UBRRL=51;

_delay_ms(1000);
while(1)
{
x=PINC&0X07;
PORTD=(x<<5);
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
void vtstr2(unsigned char *p)
{while(*p!=0)
{
vtdisp(*p);
_delay_ms(10);
p++;
}
}
void vtdisp(unsigned char x)
{
UDR=x;
while((UCSRA&(1<<TXC))==0X00);

UCSRA|=0x40;
}
