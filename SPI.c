#include<pic.h>
#define s1 RD0
#define s2 RD1
#define s3 RD2

void delay();
int i;
void main()
{
	TRISB=0X00;
	TRISC=0X00;
	TRISD=0X00;
	SSPSTAT=0X00;
	SSPCON=0X20;
if(s1==0)
{
RB0=0;

}
else if(s2==0)
{
RB1=0;
}
else if(s3==0)
{
RB2=0;
}
{
	if(RB0==0)
{
	RB1=1;
	RB2=1;
	SSPBUF='A';

}
	else if(RB1==0)
{
	RB0=1;
	RB2=1;
	SSPBUF='C';

}
	else if(RB2==0)
{
	RB0=1;
	RB1=1;
	SSPBUF='B';
}
	while(SSPIF==0);
	SSPIF=0;
	delay();
}	
}
void delay()
{
	for(i=0;i<30000;i++);
}