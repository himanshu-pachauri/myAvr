#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTD
#define rs 0
#define rw 1
#define en 2
#include"lcd.h"

void main()
// function contain Commands to initialize the LCD
{int s[8]={0x1f,0x04,0x0e,0x15,0x0d,0x04,0x04};
int a;
DDRD=0xff;
linti();
ldata('B');
for(a=0;a<8;a++)
{
lcmd(0x40 + a); // 0x40 is starting address of CG RAM (auto increment also)
ldata(s[a]); // write the data to CG RAM (Normal write function of LCD)
}
ldata(0x00);




}
