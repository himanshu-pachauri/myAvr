#include<avr/io.h>
#include<util/delay.h>
#define LCD PORTD
#define PIN PORTB
void lcmd(unsigned char);
void ldata(unsigned char);
void lstr(unsigned char*);
void li2s(int);
char a[7]={0,0,0,0,0,0,0};
void main()
{int x1=0,x2=0,y1=0,y2=0;
int z1=0,z2;

DDRD=0XFF;
DDRB=0XFF;
lcmd(0X38);
lcmd(0x06);
lcmd(0x01);
lcmd(0x0c);


while(1)
{x2=x1;
y2=y1;
z2=z1;
//lcmd(0x01);
ADMUX=0x40;
ADCSRA=0xc7;
while((ADCSRA&0x10)==0x00);
x1=ADC/2;
ADCSRA|=0x10;


ADMUX=0x41;
ADCSRA=0xc7;
while((ADCSRA&0x10)==0x00);
y1=ADC/2;
ADCSRA|=0x10;


ADMUX=0x43;
ADCSRA=0xc7;
while((ADCSRA&0x10)==0x00);
z1=ADC/2;
ADCSRA|=0x10;

lcmd(0x01);//row 1
lstr("X=");
li2s(x1);

lcmd(0x87);//row 1
lstr("Y=");
li2s(y1);

lcmd(0xc0);//row 2
lstr("Z=");
li2s(z1);


if(x1>x2)
{//lcmd(0x90);//
lstr("f/b");}

if(x1<x2)
{//lcmd(0x90);
lstr("b/w");}

if(y1>y2)
{//lcmd(0xd0);
lstr("r/t");}

if(y1<y2)
{//lcmd(0xd0);
lstr("l/t");}


if(z1<z2)
{///lcmd(0xd7);
lstr("up");
}

if(z1>z2)
{//lcmd(0xd7);
lstr("dn");
}
//_delay_ms(200);

}
}
void lcmd(unsigned char x)
{
	LCD=x;//lcd data port
	PIN=0x04;//lcd rs,rw,en(0,1,2)
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
void li2s(int c)
{
/*
char buffer[10]={0,0,0,0,0};
sprintf(buffer,"%d",c);
lstr(buffer);
*/

int i=4;
while(c>0)
{
a[i]=(c%10+48);
c/=10;
i--;
}
a[5]='\0';
lstr(a+i+1);
}

