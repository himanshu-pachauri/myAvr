#include<avr/io.h>
#include<util/delay.h>

void lcmd4(unsigned char x);
void ldata4(unsigned char x);
void main()
{DDRD=0XFF;
DDRC=0XFF;
lcmd4(0x28);//28_FOR 4 BIT COMMUNICATION
lcmd4(0x06);
lcmd4(0x01);
lcmd4(0x0c);
lcmd4(0x80);
while(1)
{lcmd4(0x87);
ldata4('A');
ldata4('B');
ldata4('C');
lcmd4(0x14);
//lcmd4(0xc8);
ldata4('C');
int i=0;
for(i=0;i<5;i++)
{

lcmd4(0x18);
_delay_ms(500);
}
ldata4('E');

}
}


void lcmd4(unsigned char x)
{

PORTD=x;////HIGHER FOUR BITS
PORTC=0x04;
_delay_ms(10);
PORTC=0;

PORTD=(0X0F&x)<<4;//SEND_LOWER FOUR BITS
PORTC=0x04;
_delay_ms(1000);
PORTC=0;
//PORTD=0;
//PORTC=0X02;

//while(PORTD);
*/
}
void ldata4(unsigned char x)
{
PORTD=x;////HIGHER FOUR BITS
PORTC=0x05;
_delay_ms(10);
PORTC=0X01;

PORTD=(0X0F&x)<<4;//SEND_LOWER FOUR BITS
PORTC=0x05;
_delay_ms(1000);
PORTC=0X01;
//PORTC=0X06;
//while(PORTD);

*/
}
