/*
 * File:   serial_in.c
 * Author: 21193665
 *
 * Created on 25 de Agosto de 2021, 14:36
 */


#include <xc.h>

#include "delay.h"
#define  CLK    TRISAbits.TRISA2    
#define  SH     TRISAbits.TRISA3

void serial_init(void) 
{
     ANSELH = 0;
    TRISAbits.TRISA6 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA0 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD7 = 0;
    PORTBbits.RB0 = 0;
}
  char i=7;
void serial_in(void)
{
    
     SH = 1;
     
    if (i<=7)
    {
        while(i)
       {
        CLK = 1;
        delay(100);
        CLK = 0;
        delay(100);
        
        i--;
       }
    }
     if (i==0)
    {
        SH = 0;
        delay(1);
        SH = 1;
        
        i=7;
    }
}
char ler_serial (void)
{
    return PORTAbits.RA1;
}