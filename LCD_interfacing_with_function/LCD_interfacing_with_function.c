#include<avr/io.h>
#include<util/delay.h>
#define rs 1
#define rw 2
#define en 3
#define data    PORTD
#define rsrwen  PORTB
void ldata(unsigned char);
void lcmd(unsigned char);
void lstr(unsigned char*);
void li2s(long int);
void lcd();
void main()
{int i=0;
DDRD=0xff;
DDRB=0xff;
lcd();

while(1)
{
lstr("H");lcmd(0x1c);//i++;
lstr("i");lcmd(0x1c);//i++;
lstr("m");lcmd(0x1c);//i++;
lstr("a");lcmd(0x1c);//i++;
lstr("n");lcmd(0x1c);//i++;
lstr("s");lcmd(0x1c);//i++;
lstr("h");lcmd(0x1c);//i++;
lstr("u");lcmd(0x1c);//i++;
/*
lstr(" ");lcmd(0x1c);//i++;
lstr(" ");lcmd(0x1c);//i++;
lstr(" ");lcmd(0x1c);//i++;
lstr(" ");lcmd(0x1c);//i++;
lstr(" ");lcmd(0x1c);//i++;
lstr(" ");lcmd(0x1c);//i++;
lstr(" ");lcmd(0x1c);//i++;
*/
//lcmd(0x80);
//lstr(" ");lcmd(0x1c);//i++;

}
}
void lcd()
{
lcmd(0x38);
lcmd(0x06);
lcmd(0x01);
lcmd(0x0e);
lcmd(0x8f);
}
void ldata(unsigned char x)
{///lcmd(0x18);
data=x;									//define data PORT for data input -----------
									//rsrwen for rs rw en pin connected to the which port  
rsrwen|=(1<<rs);			//set rs 			define ------------->rs pin no. 
rsrwen&=~(1<<rw);			//clear rw 			define ------------->rw pin no.				
rsrwen|=(1<<en);			//set en			define ------------->en pin no.
_delay_ms(100);
rsrwen&=~(1<<en);			//EN CLEAR RS MUST BE SET
}

void lcmd(unsigned char x)
{
data=x;									//define data PORT for data input d0,d1,d2....d7
									//rsrwen for rs rw en pin connected to the which port  
rsrwen&=~(1<<rs); 			//CLEAR rs 			define ------------->rs pin no. 
rsrwen&=~(1<<rw);			//clear rw 			define ------------->rw pin no.				
rsrwen|=(1<<en);			//set en			define ------------->en pin no.
_delay_ms(100);
rsrwen&=~((1<<rs)|(1<<rw)|(1<<en));
}

void lstr(unsigned char *p)
{while(*p!=0)
{
ldata(*p);
p++;
}}
void li2s(long int c)
{unsigned char a[10];//define no.of integer store in the array lenth of array
sprintf(a,"%d",c);
lstr(&a[0]);

}




