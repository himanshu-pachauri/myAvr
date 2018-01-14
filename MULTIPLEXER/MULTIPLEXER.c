#include<avr/io.h>
#include<util/delay.h>
void main()
{DDRB= 0XFF;
DDRD= 0XFF;
unsigned char  a[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D , 0x7D, 0x07, 0x7F, 0x6F};

while(1)
{
PORTD=0;
PORTB=0X01;
PORTD=a[5];
_delay_ms(10);
PORTD=0x00;
PORTB=0X02;
PORTD=a[7];
_delay_ms(10);

}

}
