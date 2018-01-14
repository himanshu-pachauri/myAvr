#include<avr/io.h>
#include<util/delay.h>
void main()
{ int i,j;
DDRB=0XFF;///row
DDRC=0XFF;///collum
unsigned int x[8][8]={1,1,1,1,1,1,1,0 /
					  0,1,0,0,0,0,0,1 /
					  0,1,0,0,0,0,0,1 /
					  0,1,0,0,0,0,0,1 /
			          0,1,0,0,0,0,0,1 /
					  0,1,0,0,0,0,0,1 /
					  0,1,0,0,0,0,0,1 /
					  1,1,1,1,1,1,1,0};
for(i=0;i<8;i++)
{
 for(j=0;j<7;j++)
{
PORTB=x[i][j];
}
//_delay_ms(1000);

}
}			
