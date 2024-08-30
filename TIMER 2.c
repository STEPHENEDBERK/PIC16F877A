#include<pic16f877a.h>

#define SBIT_T2CKPS1  1

char value = 0;
int count = 0;


void interrupt timer_isr()
{  
    if(TMR2IF==1)
    {
        TMR2 = 101;     /*Load the timer Value, (Note: Timervalue is 101 instead of 100 as the
                          Timer2 needs two instruction Cycles to start incrementing TMR2 */
        TMR2IF=0;       // Clear timer interrupt flag

        if(count>=2000) //500us * 2000=1000000us=1sec
        {
            count=0;
            value=~value;   // complement the value for blinking the LEDs
        }
        else
        {
            count++;  // Keep incrementing the count till it reaches 2000 to generate 1sec delay
        }
    } 
}


void main()
{    
    TRISD=0x00;    //COnfigure PORTD as output to blink the LEDs

    T2CON = (1<<SBIT_T2CKPS1);  // Timer2 with external freq and 16 as prescalar
    TMR2=100;       // Load the timer value for 500us delay
    TMR2IE=1;       //Enable timer interrupt bit in PIE1 register
    GIE=1;          //Enable Global Interrupt
    PEIE=1;         //Enable the Peripheral Interrupt
    TMR2ON = 1;

    while(1)
    {
        PORTD = value;
    }
}

