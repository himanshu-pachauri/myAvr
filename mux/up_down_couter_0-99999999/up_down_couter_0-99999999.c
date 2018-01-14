#include<avr/io.h>
#include<util/delay.h>
void main()
{long int i,j;
int k;
unsigned char a[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D , 0x7D, 0x07, 0x7F, 0x6F};
DDRD=0XFF;
DDRB=0XFF;
while(1)
{for(i=0;i<=99999999;i++)
{for(k=0;k<20;k++)
{j=i;
PORTB=0xfe;//1st digit
PORTD=a[j%10];
j/=10;
_delay_ms(5);

PORTB=0xfd;//2nd digit
PORTD=a[j%10];
j/=10;
_delay_ms(5);

PORTB=0xfb;//3rd digit
PORTD=a[j%10];
j/=10;
_delay_ms(5);

PORTB=0xf7;//4th digit
PORTD=a[j%10];
j/=10;
_delay_ms(5);

PORTB=0xef;//5th digit
PORTD=a[j%10];
j/=10;
_delay_ms(5);

PORTB=0xdf;//6th digit
PORTD=a[j%10];
j/=10;
_delay_ms(5);

PORTB=0xbf;//7th digit
PORTD=a[j%10];
j/=10;
_delay_ms(5);

PORTB=0x7f;//8th digit
PORTD=a[j%10];
j/=10;
_delay_ms(5);
}
//_delay_ms(1000);
}

}
}
