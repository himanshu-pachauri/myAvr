#include<avr/io.h>
#include<util/delay.h>
#include"font.h"
#include"eeprom8.h"
void main()
{int i;
DDRD=0XFF;
for(i=0;i<92;i++)
{ewrite(font[i],i);
}
for(i=0;i<92;i++)
{PORTD=eread(i);
_delay_ms(1000);
PORTD=00;
_delay_ms(1000);

}

}

