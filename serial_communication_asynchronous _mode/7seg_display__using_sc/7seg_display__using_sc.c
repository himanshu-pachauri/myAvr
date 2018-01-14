#include<avr/io.h>
#include<util/delay.h>
void main()
{DDRB=0xff;
DDRC=0XFF;
unsigned char a[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D , 0x7D, 0x07, 0x7F, 0x6F};
int i=0,j;
UCSRB=(1<<RXEN);
UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
UBRRL=51;
for(j=48;j<57;j++)
{UDR=j;
while(1)
{
while((UCSRC&(1<<RXC))==0);
PORTB=0;
i=UDR-48;
PORTB=~a[i%10];
PORTC=1<<0;
_delay_ms(1000);

while((UCSRC&(1<<RXC))==0);
i=UDR-48;
PORTB=a[i%10];
PORTC=1<<1;
_delay_ms(5);

while((UCSRC&(1<<RXC))==0);
i=UDR-48;
PORTB=a[i%10];
PORTC=1<<2;
_delay_ms(5);

while((UCSRC&(1<<RXC))==0);
i=UDR-48;
PORTB=a[i%10];
PORTC=1<<3;
_delay_ms(5);


}

}
}
