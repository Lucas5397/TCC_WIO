/*
 * File:   main.c
 * Author: 21193665
 *
 * Created on 25 de Agosto de 2021, 14:35
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "serial_in.h"
#include "ihm.h"
#include "serialIO.h" 

#define SERIALIO_SIZE   4

void main(void) 
{
    unsigned char entrada[SERIALIO_SIZE];
    unsigned char saida[SERIALIO_SIZE];
    
    dispLCD_init();
    serialIO_init( entrada, saida, SERIALIO_SIZE );

    while( 1 )
    {
        saida[0] = entrada[0];
        saida[1] = entrada[1];
     
        
        serialIO_scan();
    }
   
}
