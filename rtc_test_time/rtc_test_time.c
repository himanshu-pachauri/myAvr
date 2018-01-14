#include<avr/io.h>
#include<util/delay.h>
void i2c_initi()
{
TWBR=10;
TWSR=0x00;
}
void i2c_start()
{TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
}

unsigned char i2c_data(unsigned char x)
{TWDR=x;
TWCR=(1<<TWINT)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
PORTB=0xff;
return TWDR;
}

void i2c_stop()
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
while((TWCR&(1<<TWINT))==0);

}

void main()
{
DDRB=0xff;
PORTD=0x0f;
i2c_initi();
i2c_start();
i2c_data('A');

i2c_data('B');



)


}
