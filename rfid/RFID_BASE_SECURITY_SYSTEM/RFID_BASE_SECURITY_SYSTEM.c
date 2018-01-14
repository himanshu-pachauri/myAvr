#include<avr/io.h>
#include<util/delay.h>
#define data    PORTB  //define data port
#define rsrwen  PORTC // define rsrwen port
#define rs 0 	     //define rs pin no.
#define rw 1 	    //define rw pin no.
#define en 2 	   //define en pin no.
void ldata(unsigned char);
void lcmd(unsigned char);
void lstr1(unsigned char* );
void lstr(unsigned char*);
void li2s(long int);
void lcd();
void check(unsigned char c[]);
void main()
{unsigned char a[20],i=0;;
DDRB=0xff;
DDRC=0xff;
lcd();
lstr("Ok"); 
//li2s("123");
//usart section
UCSRA|=0x02;
UCSRB=(1<<RXEN)|(1<<TXEN)|(0<<UCSZ2);
UCSRC=(1<<URSEL)|(3<<UCSZ0);
UBRRH=0X00;
UBRRL=0x0c;

//DDRD=0xff;
//PORTD=0xff;
//lstr1("string lenght must have 12 character ");

while(1)
{
for(i=0;i<12;i++)
{
while((UCSRA&(1<<RXC))==0);
a[i]=UDR;              //ldata(UDR);
UCSRA|=(1<<RXC);

}
a[i]=0;
lcmd(0x01);
check(a);
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

void lstr1(unsigned char *p )
{
while(*p!=0)
{UDR=*p;
while((UCSRA&(1<<TXC))==0);
UCSRA|=(1<<TXC);
p++;


}

}

void check(unsigned char c[])
{int i=0,j;
unsigned char a[6]="Sonu";
//unsigned char h[9]="Himanshu";
//unsigned char m[5]="ANNU";
//unsigned char r[6]="RAJA";
//unsigned char s[4]="SIR";
unsigned char x[13]={"4D00FF9A88A0"};//ABDUL //10   a[]
					   //,{"4D00FF7401C7"}//HIMANSHU///3  h[]
					   //,{"4F006DB875EF"}//MANISH///20 m[]
					   //,{"4D00FF755A90"}//RAJA///  r
					   //,{"4D00FFC8057F"}};//SIR////9  s[]


///for(i=0;i<5;i++)
for(j=0;(j<12)&(c[j]==x[j]);j++);

if(j==12)
{

lstr("ACCESSED");

}
else
{

lstr("try again");
}

}








