////////BT2
#include<avr/io.h>
#include<util/delay.h>
#define data    PORTB  //define data port
#define rsrwen  PORTC // define rsrwen port
#define rs 1 	     //define rs pin no.
#define rw 2 	    //define rw pin no.
#define en 3 	   //define en pin no.
void ldata(unsigned char);
void lcmd(unsigned char);
void lstr(unsigned char*);
void li2s(long int);
void usart_inti();
void utrans(unsigned char *p);
void lcd();
void main()
{DDRB=0xff;
DDRC=0xfe;
usart_inti();
lcd();
lstr("Ok"); 
li2s("123");
while(1)
{if((PINC&0X01)==1)
{
utrans("HimanshuBT2");///write the stringfor tranmision

}

if((PINC&0X01)==0)
{
while((!(UCSRA&0X80))&(!(PINC&0X01)));
if(UCSRA&0X80)
{ldata(UDR);
UCSRA|=(1<<RXC);
}
}

}








}
void lcd()
{
lcmd(0x38);
lcmd(0x06);
lcmd(0x01);
lcmd(0x0e);
lcmd(0x80);
}
void ldata(unsigned char x)
{
data=x;									//define data PORT for data input -----------
									//rsrwen for rs rw en pin connected to the which port  
rsrwen|=(1<<rs);			//set rs 			define ------------->rs pin no. 
rsrwen&=~(1<<rw);			//clear rw 			define ------------->rw pin no.				
rsrwen|=(1<<en);			//set en			define ------------->en pin no.
_delay_ms(2);
rsrwen&=~(1<<en);			//EN CLEAR RS MUST BE SET
}

void lcmd(unsigned char x)
{
data=x;									//define data PORT for data input d0,d1,d2....d7
									//rsrwen for rs rw en pin connected to the which port  
rsrwen&=~(1<<rs); 			//CLEAR rs 			define ------------->rs pin no. 
rsrwen&=~(1<<rw);			//clear rw 			define ------------->rw pin no.				
rsrwen|=(1<<en);			//set en			define ------------->en pin no.
_delay_ms(2);
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

void usart_inti()
{
UCSRB|=(1<<TXEN)|(1<<RXEN);
UCSRC|=(1<<URSEL)|(0<<UMSEL);
UBRRH=0X00;
UBRRL=51;//51 SET 9600 BAUD RATE  FOR 8Mhz Freq.  
		//06 SET 9600 BAUD RATE  FOR 8Mhz Freq.  
				
}
void utrans(unsigned char *p)
{
while(*p!=0)
{UDR=*p;
while((UCSRA&(1<<TXC))==0);
UCSRA|=(1<<TXC);
_delay_ms(3);
p++;
}



}


