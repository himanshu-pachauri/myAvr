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

void i2c_stop()
{
TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void i2c_write(unsigned char x)
{
TWDR=x;
TWCR=(1<<TWEN)|(1<<TWINT);
while((TWCR&(1<<TWINT))==0);

}
unsigned char i2c_read()
{
TWCR=(1<<TWEN)|(1<<TWINT);
while((TWCR&(1<<TWINT))==0);
return TWDR;
}
void lcd_blink()
{int i=0;
for(i=0;i<25;i++)
{
PORTD=0xff;
_delay_ms(100);
PORTD=0x00;
_delay_ms(100);
}
}
void main()
{DDRD=0xff;
DDRB=0xff;
i2c_initi();
i2c_start();
i2c_write(0xa0);
i2c_write(0x00);
i2c_write(0x00);
i2c_write('A');
i2c_stop();


lcd_blink();


i2c_start();
i2c_write(0xa0);
i2c_write(0x00);
i2c_write(0x00);
_delay_ms(1000);
i2c_start();
i2c_write(0xa1);
PORTD=i2c_read();
i2c_stop();


}
