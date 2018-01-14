#include<avr/io.h>
#include<util/delay.h>
void lcommand(char);
void ldata(char);
void lstr(char*);
void main()
{char c[10]="String";//type string for print
DDRB=0XFF;//connect data pin Bx to data pin x of lcd x=0 to 7
DDRD=0XFF;// rs pin of lcd to PD0,rw--->PD1,en ----->>PD2
lcommand(0x38);//commands for lcd initialise
lcommand(0x06);
lcommand(0x01);
lcommand(0x0e);
while(1)
{lstr(c);
ldata('A');//print the character by this format, replace  A
lstr("string");//print the string also by this format,,replace  string
lcommand(0x01);//lcd intialiaze


}
}
void lcommand(char x)
{
	PORTB=x;
	PORTD=0x04;
	_delay_ms(50);
	PORTD=0;
	}
void ldata(char x)
{	PORTB=x;
	PORTD=0x05;
	_delay_ms(50);
	PORTD=0x01;
	}
void lstr(char *p)
{while(*p!=0)
{
ldata(*p);
p++;
}
}
