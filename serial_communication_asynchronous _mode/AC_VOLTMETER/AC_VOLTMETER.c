#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>
void ldata(unsigned char);
void lcmd(unsigned char);
void lvalue(int c);
void lstr1(unsigned char *p,int c );
void main()
{int  adc2=0,adc1=0;
DDRD=0XFF;
DDRB=0XFF;
lcmd(0x38);
lcmd(0x06);
lcmd(0x01);
lcmd(0x0c);
ADMUX=0X01;
ADCSRA=0Xc5;
while(1)
{ADCSRA|=0X40;
ldata
lvalue(ADC);

}
}
void lcmd(unsigned char x)
{
	PORTD=x;
	PORTB=0x04;
	_delay_ms(2);
	PORTB=0;
	}
void ldata(unsigned char x)
{	PORTD=x;
	PORTB=0x05;
	_delay_ms(2);
	PORTB=0x01;
	}
void lstr(unsigned char *p)
{while(*p!=0)
{
ldata(*p);
p++;

}}
void lvalue(int c)
{
unsigned char a[4];
//if(c>1000)
{
//c=1000;
}
sprintf(a,"%d",(c/2));
lstr1(&a[0],c);

}
void lstr1(unsigned char *p,int c )
{unsigned char i=0;
if(c<200)
{
lstr("0.0");
}
else
{
i=1;
}
while(*p)
{
ldata(*p);
p++;
if(i==1)
{
ldata('.');
i=5;
}
}


}
