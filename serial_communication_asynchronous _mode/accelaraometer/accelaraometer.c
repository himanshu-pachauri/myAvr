#include<avr/io.h>
#include<util/delay.h>
#define LCD PORTD
#define PIN PORTB
void lcmd(unsigned char);
void ldata(unsigned char);
void lstr(unsigned char*);
void li2s(long int);
void main()
{int adc1,adc2,adc3,adc4,adc5;
DDRD=0XFF;
DDRB=0XFF;
lcmd(0X38);
lcmd(0x06);
lcmd(0x01);
lcmd(0x0c);

ADCSRA=0Xcf;


while(1)
{
ADMUX=0X00;
ADCSRA|=0x40;
while((ADCSRA&(1<<ADIF))==0);
adc1=ADC/2.049;
ADCSRA|=(1<<ADIF);

ADMUX=0X01;
ADCSRA|=0x40;
while((ADCSRA&(1<<ADIF))==0);
adc2=ADC/2.049;
ADCSRA|=(1<<ADIF);

ADMUX=0X02;
ADCSRA|=0x40;
while((ADCSRA&(1<<ADIF))==0);
adc3=ADC/2.049;
ADCSRA|=(1<<ADIF);


ADMUX=0X03;
ADCSRA|=0x40;
while((ADCSRA&(1<<ADIF))==0);
adc4=ADC/2.049;
ADCSRA|=(1<<ADIF);

ADMUX=0X04;
ADCSRA|=0x40;
while((ADCSRA&(1<<ADIF))==0);
adc5=ADC/2.049;
ADCSRA|=(1<<ADIF);


lcmd(0x80);//row 1
lstr("X1=");
li2s(adc1);


lcmd(0xc0);//row 2
lstr("Y1=");
li2s(adc2);

lcmd(0x90);//row 2
lstr("Z=");
li2s(adc3);

lcmd(0xd0);
lstr("mfd. by Himanshu");

lcmd(0x87);//row 1
lstr("X2=");
li2s(adc4);

lcmd(0xc7);//row 2
lstr("Y2=");
li2s(adc5);

}

}
void lcmd(unsigned char x)
{
	LCD=x;//lcd data port
	PIN|=0x04;//lcd rs,rw,en(0,1,2)
	_delay_ms(2);
	PIN=0;
	}
void ldata(unsigned char x)
{	LCD	=x;
	PIN=0x05;
	_delay_ms(2);
	PIN=0x01;
	}
void lstr(unsigned char *p)
{while(*p!=0)
{
ldata(*p);
p++;
}}
void li2s(long int c)
{unsigned char a[5]="0.00";
int i=3;
while((c>0))
{a[i]=(c%10+48);
c/=10;
i--;
if(i==1)
{
i=0;
}
}
a[5]=0;
lstr(a);
}

