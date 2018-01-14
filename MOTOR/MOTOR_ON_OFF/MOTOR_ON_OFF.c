#include<avr/io.h>
#include<util/delay.h>
void main()
{DDRD=0XFF;
while(1)
{if(PINC&0X01)
PORTD=0X09;
else
PORTD=0;
}

}
