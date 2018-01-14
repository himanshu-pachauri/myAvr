#include<avr/io.h>
#include<util/delay.h>
void i2c_slave(unsigned char x)
{TWAR=x;
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
while((TWCR&(1<<TWINT))==0);
}

void i2c_start()
{TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
}
unsigned char i2c_write(unsigned char x)
{
TWDR=x;
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
while((TWCR&(1<<TWINT))==0);
return TWDR;
}
void i2c_stop()
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO)|(1<<TWEA);
while((TWCR&(1<<TWINT))==0);
}

void main()
{DDRD=0xff;
i2c_slave('D');
i2c_write(0x05);

while(1)
PORTD=i2c_write(6);
//PORTD=i2c_read();
}
