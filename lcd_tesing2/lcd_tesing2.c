#include<avr/io.h>
#include<util/delay.h>
#define rs 0
#define rw 1
#define en 2
#define lcd PORTD
void lint(unsigned long x);
void ldata(unsigned char x);
void lcmd(unsigned char x);
void lstr(unsigned char*);
void main()
{unsigned char a[5];
DDRD=0xff;
lcmd(0x02);
lcmd(0x28);
lcmd(0x06);
lcmd(0x0c);
lstr("ok");
lint(32767);



}
void ldata(unsigned char x)//rs=1,rw=0,en=1,,,,,en =0
{
lcd=0xf0&x;//send higher
lcd|=(1<<rs);//rs=1
lcd&=~(1<<rw);//rw=0
lcd|=(1<<en);//en=1
_delay_ms(1);
lcd&=~(1<<en);//en=0;


lcd=(0x0f&x)<<4;//send lower
lcd|=(1<<rs);//rs =1
lcd&=~(1<<rw);//rw=0
lcd|=(1<<en);//en=1
_delay_ms(1);
lcd&=~(1<<en);//en=0;
}
void lcmd(unsigned char x)
{
lcd=0xf0&x;
lcd&=~(1<<rs);//rs=0
lcd&=~(1<<rw);//rw=0
lcd|=(1<<en);//en=1
_delay_ms(1);
lcd&=~(1<<en);//en=0



lcd=((0x0f&x)<<4);
lcd&=~(1<<rs);//rs=0
lcd&=~(1<<rw);//rw=0
lcd|=(1<<en);//en=1
_delay_ms(1);
lcd&=~(1<<en);//en=0;
}
void lstr(unsigned char *p)
{
while(*p)
{
ldata(*p);
p++;
}
}
void lint(unsigned long x)
{
unsigned long y=x;
int i=0;


}
