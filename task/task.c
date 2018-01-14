#include<avr/io.h>
#include<util/delay.h>
void main()
{
PORTD=0xff;
unsigned char i,j=1;
for(i=0;i<16;i++)
{
PORTD=(j<<1);
_delay_ms(100);


}
}
