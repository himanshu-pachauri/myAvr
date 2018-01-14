///////___-----master
#include<avr/io.h>
#include<util/delay.h>
void lstr(unsigned char*);
void main()
{unsigned char a[10]="Himanshu";

DDRB=(1<<2)|(1<<3)|(1<<5)|(0<<4);
SPCR=(1<<SPE)|(1<<MSTR)|(1<<DORD);
_delay_ms(5000);
lstr(a);



}
void lstr(unsigned char *p)
{while(*p!=0)
{
SPDR=*p;
while((SPSR&(1<<SPIF))==0);
SPSR|=(1<<SPIF);
_delay_ms(10);
p++;

}}
