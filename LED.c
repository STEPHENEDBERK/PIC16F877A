#include<pic.h>
void delay();
#define led RB0
void main()
{
	TRISB = 0x00;
	led = 1;
	delay();
	led = 0;
	delay();
}
void delay()
{
	int j;
	for(j=0;j<20000;j++);
}