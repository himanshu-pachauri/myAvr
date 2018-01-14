#include<avr/io.h>
#include<util/delay.h>
void main()
{DDRD=(1<<5)|(1<<3);//,MOSI AS OUTPUT&SCK|AS A OUTPUT

DDRD=0xff;//PORTD AS A OUTPUT
DDRC=0xff;//PORTC AS A OUTPUT
_delay_ms(1000);
SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
SPDR='A';
while(SPSR&(1<<SPIF)==0);
SPSR|=1<<SPIF;





}
