#include<avr/io.h>
#include<util/delay.h>
void main()
{unsigned char i;
DDRB=0XFF;
while(1)
{
for(i=0;i<=255;i++)
PORTB=i;
_delay_ms(2000);
PORTB=0;
_delay_ms(2000);

}

}
