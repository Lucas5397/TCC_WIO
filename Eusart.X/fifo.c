/*
 * File:   fifo.c
 * Author: 21193665
 *
 * Created on 27 de Outubro de 2021, 16:25
 */


#include <xc.h>

#define FIFO_SIZE   16
unsigned char fifo[FIFO_SIZE];
unsigned char fifo_head = 0;
unsigned char fifo_tail = 0;


void fifo_inserir( unsigned char d )
{
    fifo[fifo_head] = d;
    fifo_head = ++fifo_head % FIFO_SIZE;
}


unsigned char fifo_retirar( void )
{
    unsigned char aux = 0;
    if( fifo_tail != fifo_head ) 
    {
        aux = fifo[fifo_tail];
        fifo_tail = ++fifo_tail % FIFO_SIZE;
    }
    return( aux );
}

unsigned char fifo_tam( void )
{
    return( (fifo_head - fifo_tail) % FIFO_SIZE );
}

void fifo_init( void )
{
    fifo_head = 0;
    fifo_tail = 0;
}

extern char indice = 0;
extern char vtr[33] = " ";
//unsigned char hex[40] = " ";

void fifo_filtro( void )
{
        while( fifo_tam() )
        {
            unsigned char d = fifo_retirar();
            if( d >= 20 )
            {
                vtr[indice] = d;
                indice = ++indice % 32;
            }
            else if( d == '\r' )
            {
                vtr[indice] = " ";
                indice = ++indice % 32;
                vtr[indice] = " ";
                indice = ++indice % 32;
            }
            else if( d == '\n' )
            {
                vtr[indice] = " ";
                indice = ++indice % 32;
                vtr[indice] = " ";
                indice = ++indice % 32;
            }
        }
}