#include<pic.h>
#define RS RB0
#define RW RB1
#define E RB2
void delay();

void lcd_cmd(int x);
void lcd_dat(char Y);

int adc();

int a,b,c,d,e,f,g;
int result;

void main()
{
TRISB=0x00; // all pin output
TRISC=0x00;
ADCON0=0X01;
ADCON1=0X80;
lcd_cmd(0X0E);

while(1)
{
GODONE=1;
while(GODONE==1);
a=ADRESL+(ADRESH<<8); 
b=a/10;
c=a%10;
d=b/10;
e=b%10;
f=d/10;
g=d%10;

lcd_dat(f+'0');
delay();

lcd_dat(g+'0');
delay();

lcd_dat(e+'0');
delay();
 

lcd_dat(c+0x30);
delay();

lcd_cmd(0X01); 

}

}



void lcd_cmd(int x)
{
	PORTC=x;
	RS=0;
	RW=0;
	E=1;
	delay();
	E=0;
}

void lcd_dat(char Y)
{
    PORTC=Y;
	RS=1;
	RW=0;
	E=1;
	delay();
	E=0;
	
}

	void delay() 
{
	 int b;
	for (b = 0; b < 30000; b++);
}
