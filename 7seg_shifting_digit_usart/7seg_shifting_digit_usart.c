#include<avr/io.h>
#include<util/delay.h>
void main()
{unsigned char a[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D , 0x7D, 0x07, 0x7F, 0x6F};
 unsigned char b[]={2,3,4,5};
 int i=0,j,k=0;
	DDRB=0XFF;
	DDRC=0XFF;
	DDRD=0XFE;
//UCSRA=(1<<U2X);
UCSRB=(1<<RXEN)|(1<<RXCIE);
UCSRC|=(1<<URSEL);
UBRRH=0X00;
UBRRL=0X06;


 while(1)
{	


for(i=3;i>=0;i--)
{
//for(k=0;k<500;k++)
{PORTC=~(0X08>>i);
PORTB=a[b[i]];
_delay_ms(2);
while((UCSRA&(1<<RXC))==1);
{//PORTB=a[0];
//_delay_ms(10000);
b[i]=UDR-48;
UCSRA|=(1<<RXC);
k++;



}

}}
		

 
 
 
 
 
}




}
