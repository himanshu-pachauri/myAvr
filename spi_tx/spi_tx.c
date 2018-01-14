#include<avr/io.h>
#include<util/delay.h>
void main()
{
SPCR|=(1<<SPIE)|(1<<SPE)|(1<<DORD)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0);
SPDR='A';
while(1)
{
SPDR='A';
while(SPSR&(1<<SPIF)==0);
SPSR|=(1<<SPIF);


}



}
