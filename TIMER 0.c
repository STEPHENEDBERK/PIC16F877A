#include<pic16f877a.h>

char value = 0;
#define SBIT_PS2  2

void interrupt timer_isr()
{  
    if(TMR0IF==1)
    {
        value=~value;   // complement the value for blinking the LEDs
        TMR0 = 101;     /*Load the timer Value, (Note: Timervalue is 101 instaed of 100 as the
                          TImer0 needs two instruction Cycles to start incrementing TMR0 */
        TMR0IF=0;       // Clear timer interrupt flag
    } 
}


void main()
{    
    TRISD=0x00;    //COnfigure PORTD as output to blink the LEDs

    OPTION_REG = (1<<SBIT_PS2);  // Timer0 with external freq and 32 as prescalar
    TMR0=100;       // Load the time value for 1ms delay
    TMR0IE=1;       //Enable timer interrupt bit in PIE1 register
    GIE=1;          //Enable Global Interrupt
    PEIE=1;         //Enable the Peripheral Interrupt

    while(1)
    {
        PORTD = value;
    }
}
