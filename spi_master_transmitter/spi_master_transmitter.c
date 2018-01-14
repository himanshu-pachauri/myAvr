//MASTER
#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
unsigned char spi(unsigned char);
 
void main()
{int x;
DDRD=0XFF;
DDRC=0XFF;
DDRB=(1<<2)|(1<<3)|(1<<5);
lcd();
lstr("M");
//_delay_ms(1000);
SPCR=(1<<SPE)|(1<<MSTR)|(1<<DORD);
ldata(spi('M'));
}
unsigned char spi(unsigned char x)
{
SPDR=x;
while((SPSR&(1<<SPIF))==0);
SPSR|=(1<<SPIF);
return SPDR;

}

