#include<avr/io.h>
#include<util/delay.h>
void main()
{int i; 
DDRD=0XFF;
while(1)
{for(i=0;i<3000;i++)
{
WDTCR|=(1<<WDCE)|(1<<WDE);
}
					PORTD=0XFF;
{for(i=0;i<300;i++)
{
WDTCR|=(1<<WDCE)|(1<<WDE);
}
						PORTD=0;


}
}
}
