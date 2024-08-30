#include <pic.h>

#define RS RB0
#define RW RB1
#define E RB2

void delay();
void lcd_cmd(int x);
void lcd_dat(char Y);

int a, b, c, d, e, f, g, a_a, b_b, c_c, d_d, e_e, f_f, g_g;
int result;

void main()
{
    TRISB = 0x00; // Set all pins on PORTB as output
    TRISC = 0x00; // Set all pins on PORTC as output

    lcd_cmd(0x0E); // Turn on display and cursor
    lcd_cmd(0x38); // Set LCD to 8-bit mode, 2 line, 5x7 dots

    ADCON1 = 0xCE; // Configure A/D module
    ADCS1 = 0;
    ADCS0 = 1;
    CHS2 = 0;
    CHS1 = 0;
    CHS0 = 0;
    ADON = 1;
    
    while (1)
    {
        GODONE = 1;
        while (GODONE == 1);
        a = ADRESL | (ADRESH << 8); 
        b = a / 10;
        c = a % 10;
        d = b / 10;
        e = b % 10;
        f = d / 10;
        g = d % 10;

        lcd_dat(f + '0');
        delay();

        lcd_dat(g + '0');
        delay();

        lcd_dat(e + '0');
        delay();

        lcd_dat(c + 0x30);
        delay();

        // Switch to second ADC channel
        CHS2 = 0;
        CHS1 = 0;
        CHS0 = 1;
        GODONE = 1;
        while (GODONE == 1);
        a_a = ADRESL | (ADRESH << 8); 
        lcd_cmd(0xC0); // Move cursor to second line
        b_b = a_a / 10;
        c_c = a_a % 10;
        d_d = b_b / 10;
        e_e = b_b % 10;
        f_f = d_d / 10;
        g_g = d_d % 10;

        lcd_dat(f_f + '0');
        delay();

        lcd_dat(g_g + '0');
        delay();

        lcd_dat(e_e + '0');
        delay();

        lcd_dat(c_c + 0x30);
        delay();

        lcd_cmd(0x01); // Clear display
    }
}

void lcd_cmd(int x)
{
    PORTC = x;
    RS = 0;
    RW = 0;
    E = 1;
    delay();
    E = 0;
}

void lcd_dat(char Y)
{
    PORTC = Y;
    RS = 1;
    RW = 0;
    E = 1;
    delay();
    E = 0;
}

void delay()
{
    int b;
    for (b = 0; b < 30000; b++);
}
 
