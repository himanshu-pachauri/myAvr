#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
unsigned char bcd2decimal(unsigned char x)
{unsigned char decimal=0;
decimal=((x>>4)&0x0f)*10 +(x&0x0f);
return decimal;
}
void i2c_initi()
{
TWBR=10;
TWSR=0x00;

}
void i2c_start()
{TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
}

unsigned char i2c_write(unsigned char x)
{
TWDR=x;
TWCR=(1<<TWINT)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
return TWDR;
}
unsigned char i2c_read()
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
while((TWCR&(1<<TWINT))==0);
return TWDR;
}

void i2c_stop()
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
//while((TWCR&(1<<TWSTO))==0);
}
void i2c_string(unsigned char *p)
{
while(*p)
{
i2c_write(*p);
_delay_ms(1000);
p++;
}
}
int main()
{lcd_ini();

DDRB=0xff;
lcd_integer(bcd2decimal(0x38));
while(1);
i2c_initi();
i2c_start();
i2c_write(0xd0);
i2c_write(0x00);
i2c_write(0x01);
i2c_write(0x02);
i2c_write(0x03);
i2c_write(0x01);
i2c_write(0x04);
i2c_write(0x04);
i2c_write(0x04);
i2c_stop();
i2c_start();
i2c_write(0xd0);
i2c_write(0x00);
_delay_ms(3000);
i2c_start();
i2c_write(0xd1);
PORTB=i2c_read();
PORTB=i2c_read();
PORTB=i2c_read();
PORTB=i2c_read();

PORTB=i2c_read();
PORTB=i2c_read();

PORTB=i2c_read();
PORTB=i2c_read();

}
















