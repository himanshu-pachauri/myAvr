#include<avr/io.h>
#include<util/delay.h>
void main()
{int i=0;
DDRC=0XFF;
while(1)
{for(i=0;i<4;i++)
{
	PORTC=1<<i;
	_delay_ms(200);
}
}
}
