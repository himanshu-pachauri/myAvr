/*******reciever*/
#include<avr/io.h>
#include<util/delay.h>
void ldata(unsigned char);
void lcmd(unsigned char);
void lstr(unsigned char*);
int main()
{unsigned char a[10],i;
DDRB=0XFF;
DDRC=0XFF;
UCSRB=(1<<RXEN);
UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
UBRRH=0x00;
UBRRL=51;//BAUD RATE 9600
lcmd(0x38);
lcmd(0x06);
lcmd(0x0e);
lcmd(0x01);
lcmd(0x80);
while(1)
{while((UCSRA&(1<<RXC))==0);
UCSRA=(1<<RXC);
ldata(UDR);
}
}
void ldata(unsigned char x)
{
PORTB=x;
PORTC=0x05;
_delay_ms(5);
PORTC=0x01;
}

void lcmd(unsigned char x)
{
PORTB=x;
PORTC=0x04;
_delay_ms(5);
PORTC=0;
}


