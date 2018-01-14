void ewrite(unsigned char x,int y)
{while(EECR & (1<<EEWE));

EEAR=y;
EEDR=x;
EECR|=(1<<EEMWE);
EECR|=(1<<EEWE);



}
unsigned char eread(int y)
{while(EECR & (1<<EEWE));

EEAR=y;
EECR|=(1<<EERE);
return EEDR;

}
