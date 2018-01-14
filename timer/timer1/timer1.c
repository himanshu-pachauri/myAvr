#include<avr/io.h>
void timer1()
{
TCCR1B=0X03;
TCNT1H=0Xc2;
TCNT1L=0Xf6;
while((TIFR&0x04)==0x00);
TIFR=0x04;


}
void main()
{

DDRD=0XFF;
while(1)
{
PORTD=0xff;
timer1();
PORTD=0x00;
timer1();

}




}
