#include<avr/io.h>
void main()
{DDRB=0xff;
ICR1=20000;
OCR1A=5000;
TCCR1A=0X82;
TCCR1B=0X19;
while(1);

}
