#include<avr/io.h>
#include<util/delay.h>
#define LCD PORTD
#define PIN PORTB
void lcmd(unsigned char);
void ldata(unsigned char);
void lstr(unsigned char*);
void li2s(long int);
void main()
{int x1=0,x2=0,y1=0,y2=0;
int z1=0,z2;

DDRD=0XFF;
DDRB=0XFF;
lcmd(0X38);
lcmd(0x06);
lcmd(0x01);
lcmd(0x0c);

ADCSRA=0Xc7;


while(1)
{//lcmd(0x01);
y2=y1;
x2=x1;
z2=z1;

ADMUX=0X03;
ADCSRA|=0xc7;
while((ADCSRA&(0x01))==0);
z1=ADC/2;
ADCSRA|=(0x01);

ADMUX=0X00;
ADCSRA|=0xc7;
while((ADCSRA&(0x01))==0);
x1=ADC/2;
ADCSRA|=(0x01);

ADMUX=0X01;
ADCSRA|=0xc7;
while((ADCSRA&(0x01))==0);
y1=ADC/2;
ADCSRA|=(0x01);



lcmd(0x80);//row 1
lstr("X=");
li2s(x1);

lcmd(0x87);//row 1
lstr("Y=");
li2s(y1);

lcmd(0xc0);//row 2
lstr("Z=");
li2s(z1);


if(x1>x2)
{lcmd(0x90);//
lstr("f/b");}

if(x1<x2)
{lcmd(0x90);
lstr("b/w");}

if(y1>y2)
{lcmd(0xd0);
lstr("r/t");}

if(y1<y2)
{lcmd(0xd0);
lstr("l/t");}


if(z1<z2)
{lcmd(0xd7);
lstr("up");
}

if(z1>z2)
{lcmd(0xd7);
lstr("dn");
}


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
while(c>0)
{a[i]=(c%10+48);
c/=10;
i--;
if(i==1)
{
i=0;
}
}
a[5]=0;
lstr(&a[0]);
}

