#include<stdio.h>
#include<util/delay.h>
#define rs 0
#define rw 1
#define en 2
#define lcd PORTD
void ldata(unsigned char x);
void lcmd(unsigned char x);
void main()
{
lcmd(0x02);
lcmd(0x28);
lcmd(0x06);
lcmd(0x0c);
lcmd(0x01);
ldata('A');
}
void ldata(unsigned char x)//rs=1,rw=0,en=1,,,,,en =0
{
lcd=0xf0&x;
lcd|=1<<rs;
lcd&=~(1<<rw);
lcd|=1<<en;
_delay_ms(10);
lcd&=~(1<<en);
lcd=(0x0f&x)<<3;
lcd|=1<<rs;
lcd&=~(1<<rw);
lcd|=1<<en;
_delay_ms(10);




}
void lcmd(unsigned char x)
{
lcd=0xf0&x;
lcd&=(1<<rs);
lcd&=~(1<<rw);
lcd|=1<<en;
_delay_ms(10);
lcd&=~(1<<en);
lcd=(0x0f&x)<<3;
lcd&=~(1<<rs);
lcd&=~(1<<rw);
lcd|=1<<en;
_delay_ms(10);

}
