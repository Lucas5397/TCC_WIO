/*
 * File:   interrupt.c
 * Author: 21193665
 *
 * Created on 27 de Outubro de 2021, 16:21
 */


#include <xc.h>
#include "fifo.h"

void __interrupt() isr(void)
{
    if( PIR1bits.RCIF )
    {
        fifo_inserir( RCREG );
    }

}