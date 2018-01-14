#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTD
#define rs 0
#define rw 1
#define en 2
#include"lcd.h"
void main()
{
DDRD=0xff;
DDRC=0xff;
DDRB=0x00;
linti();
while(1)
{
if((PINB&0x03)==0x00)
{
PORTC=0x00;
lcmd(0x01);
lstr("STOP");
while((PINB&0x03)==0x00);
}

if((PINB&0x03)==0x03)
{
PORTC=0x09;
lcmd(0x01);
lstr("FORWORD");
while((PINB&0x03)==0x03);
}

if((PINB&0x03)==0x01)
{
PORTC=0x08;
lcmd(0x01);
lstr("LEFT");
while((PINB&0x03)==0x01);
}

if((PINB&0x03)==0x02)
{
PORTC=0x02;
lcmd(0x01);
lstr("RIGHT");
while((PINB&0x03)==0x02);
}



}

}
