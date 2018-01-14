#include<stdlib.h>
void ldata(unsigned char x)
{
lcd=x&0xf0;
lcd|=(1<<rs);
lcd&=~(1<<rw);
lcd|=(1<<en);
_delay_ms(1);
lcd&=~(1<<en);


lcd=(x<<4)&0xf0;
lcd|=(1<<rs);
lcd&=~(1<<rw);
lcd|=(1<<en);
_delay_ms(1);
lcd&=~(1<<en);
}
void lcmd(unsigned char x)
{
lcd=x&0xf0;
lcd&=~(1<<rs);
lcd&=~(1<<rw);
lcd|=(1<<en);
_delay_ms(1);
lcd&=~(1<<en);


lcd =(x<<4)&0xf0;
lcd&=~(1<<rs);
lcd&=~(1<<rw);
lcd|=(1<<en);
_delay_ms(1);
lcd&=~(1<<en);
}
void lstr(unsigned char *p)
{
while(*p)
{
ldata(*p);
p++;
}
}
void li2s(unsigned int x)
{
unsigned char a[7];
sprintf(a,"%d",x);
lstr(a);
}
void linti(void )
{
lcmd(0x02);
lcmd(0x28);
lcmd(0x06);
lcmd(0x0c);
ldata('A');
}
