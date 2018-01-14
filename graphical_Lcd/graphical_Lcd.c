#include<avr/io.h>
#include<util/delay.h>
void glcmd(unsigned char);
void gldata(unsigned char);
void gcas(unsigned char,unsigned char);
void main()
{
DDRB=0xff;
DDRD=0XFF;
glcmd(0x3f);
glcmd(0xBB);
glcmd(0x40);
gldata(0xff);
while(1);




}
void gldata(unsigned char x)
{PORTD=x;
PORTB=0x15;
_delay_ms(1000);
PORTB&=0xfe;


}
void glcmd(unsigned char x)
{PORTD=x;
PORTB=0x19;
_delay_ms(1000);
PORTB&=0;
}

