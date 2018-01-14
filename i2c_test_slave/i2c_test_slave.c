#include<avr/io.h>
#include<util/delay.h>
void TWI_start()
{TWBR=0x02;
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
while((TWCR&(1<<TWINT))==0);
}
void TWI_write(unsigned char x)
{TWDR=x;
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
while((TWCR&(1<<TWINT))==0);
}
unsigned char TWI_read()
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
while((TWCR&(1<<TWINT))==0);
return TWDR;
}

void main()
{
DDRD=0xff;
DDRB=0xff;

TWAR=0xFE;
TWI_start();




PORTD=TWI_read();
PORTD=TWI_read();
PORTB=TWSR;


}
