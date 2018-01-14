#include<avr/io.h>
#include<util/delay.h>
void TWI_start()
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
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
void TWI_stop()
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
while((TWCR&(1<<TWINT))==0);
}
void main()
{
DDRD=0xff;
DDRB=0xff;
TWBR=0xff;


//TWI_write(0xfe);


//TWI_write('A');

//TWI_write('B');
//PORTD=TWSR;
TWI_start();
TWI_write(0xd0);
TWI_write(0x00);
TWI_write(0x00);
TWI_stop();

TWI_start();
TWI_write(0xd0);
TWI_write(0x01);
TWI_write(0x00);
TWI_stop();
while(1);
TWI_start();
TWI_write(0xd0);
TWI_write(0x02);
TWI_write(0x00);
TWI_stop();

TWI_start();
TWI_write(0xd0);
TWI_write(0x03);
TWI_write(0x00);
TWI_stop();

TWI_start();
TWI_write(0xd0);
TWI_write(0x03);
TWI_write(0x00);
TWI_stop();

}


