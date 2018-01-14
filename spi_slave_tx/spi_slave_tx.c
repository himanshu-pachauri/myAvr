//SLAVE
#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
unsigned char spi(unsigned char );
 
void main()
{DDRB=0x10;
unsigned char x;
DDRD=0XFF;
DDRC=0XFF;
lcd();

lstr("s");
SPCR|=(1<<SPE)|(1<<DORD);
{//_delay_ms(5000);
ldata(spi('H'));
}}
unsigned char spi(unsigned char x)
{
SPDR=x;
while((SPSR&(1<<SPIF))==0);
SPSR=(1<<SPIF);
return SPDR;

}


