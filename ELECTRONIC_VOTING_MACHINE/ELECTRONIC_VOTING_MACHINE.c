#include<avr/io.h>
#include<util/delay.h>
#define DATA_PIN    PORTD
#define CONTROL_PIN PORTC
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);
 
void main()
{
DDRD=0XFF;
DDRC=0XFF;
DDRB=0X00;

int vote_bank_1=0,vote_bank_2=0;

							    LCD_COMMAND(0x38);
								LCD_COMMAND(0x06);
								LCD_COMMAND(0x01);
								LCD_COMMAND(0x0C);
LCD_COMMAND(0x80);

LCD_DATA('A');
LCD_DATA('=');
LCD_INTEGER2STRING(vote_bank_1);
																
																
LCD_COMMAND(0xc0);
LCD_DATA('C');
LCD_DATA('=');
LCD_INTEGER2STRING(vote_bank_2);
																
while(1)
{	
if(PINB&0x01)
{LCD_COMMAND(0x82);
LCD_INTEGER2STRING((++vote_bank_1));
while(PINB&0x01);
}
													if(PINB&0x02)
													{	
													LCD_COMMAND(0xc2);
													LCD_INTEGER2STRING((++vote_bank_2));
													while(PINB&0x02);
													}

}
}
void LCD_COMMAND(unsigned char COMMAND)
{
DATA_PIN=COMMAND;
CONTROL_PIN=0x04;
_delay_ms(50);
CONTROL_PIN=0x00;
}
void LCD_DATA(unsigned char DATA)
{
DATA_PIN=DATA;
CONTROL_PIN=0x05;
_delay_ms(50);
CONTROL_PIN=0x01;
}
void LCD_WRITE_STRING(unsigned char *p)
{
while(*p)
{
LCD_DATA(*p);
p++;
}
}

void LCD_INTEGER2STRING(int vote)
{
unsigned char int2string[40];
sprintf(int2string,"%d",vote);
LCD_WRITE_STRING(int2string);
}
