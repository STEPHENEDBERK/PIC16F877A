#include<pic.h>
void delay();
int i;
void main()
{
TRISC2=0;
CCP1M3=1;
CCP1M2=1;
CCP1CON=0X5E;
PR2=124;
CCPR1L=63;  //75%

T2CKPS0=1;
T2CKPS1=0;
TMR2ON=1;
}
void delay()
{
for(i=0;i<30000;i++);
}