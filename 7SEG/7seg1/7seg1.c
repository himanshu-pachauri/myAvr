#include<avr/io.h>
#include<util/delay.h>
void main()
{unsigned char a[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D , 0x7D, 0x07, 0x7F, 0x6F};
int i;
DDRD=0XFF;
while(1)
{for(i=0;i<10;i++)
{
PORTD=a[i];
_delay_ms(1000);
}

}
}
