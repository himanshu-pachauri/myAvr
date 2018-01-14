#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTB
#define rs 0
#define rw 1
#define en 2 
#include "lcd.h"
void adcinti()
{
ADCSRA=0x80;
ADMUX&=0x0f;


}
void adc0(unsigned char x)
{
ADMUX|=(0x07&x) ;
ADCSRA|=(1<<ADSC);
while((ADCSRA &(1<<ADIF)==0));

ADCSRA|=(1<<ADIF);
li2s(ADC);
ADMUX=0x00;


}



void main()
{
int i=0;
DDRB=0xff;
linti();
adcinti();

while(1)
{
for(i=0;i<4;i++)
{
switch(i)
{
case 0:
lcmd(0x80);
break;

case 1: 
lcmd(0x87);
break;

case 2:
lcmd(0xc0);
break;

case 3:
lcmd(0xc7);
break;

}

adc0(i);

}
_delay_ms(1000);
lcmd(0x01);
}

}
