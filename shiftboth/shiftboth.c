#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0xFF;
int i,y=1;
unsigned char x=128;
while(1)
{
for(i=0;i<8;i++)

{
PORTD=x;
PORTD=y;


}
}
