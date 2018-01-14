#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<avr/interrupt.h>
volatile int i=0;
void main()
{int j;
unsigned char a[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D , 0x7D, 0x07, 0x7F, 0x6F};

DDRB=0xff;
DDRC=0xff;
sei();
MCUCR=0x02;

GICR=(1<<INT0);

while(1)
{
j=i%100;
PORTC=~0x01;
PORTB=a[j/10];
_delay_ms(1);
PORTB=0x00;


PORTC=~0x02;
PORTB=a[i%10];
_delay_ms(1);
PORTB=0x00;







}
}
ISR (INT0_vect)
{

++i;

}
