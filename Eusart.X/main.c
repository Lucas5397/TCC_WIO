/*
 * File:   main.c
 * Author: 20187263
 *
 * Created on 27 de Setembro de 2021, 13:10
 */

//    wifi_send("AT+CWSAP=\"WIO\",\"23456789\",1,2,4,0\r\n");
//    delay(2000);
//
//    lcd.clr();
//    indice = 0;
//    fifo_filtro();
//    lcd.printpos(0,0,vtr);
//    delay(3000);
//
//    wifi_send("AT+CIPMUX=1\r\n");
//    delay(2000);
//
//    lcd.clr();
//    indice = 0;
//    fifo_filtro();
//    lcd.printpos(0,0,vtr);
//    delay(3000);

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "ihm.h"
#include "eusart.h"
#include "wifi.h"
#include "fifo.h"

void main(void)
{
    lcd.init();
    wifi_init(115200);
    delay(3000);

    lcd.clr();
    indice = 0;
    wifi.mode(1); // 1) Cliente 2) Servidor 3) Ambos

    fifo_filtro();
    lcd.printpos(0,0,vtr);
    delay(3000);

    wifi.connect("WIO","12345678");

    lcd.clr();
    indice = 0;
    fifo_filtro();
    lcd.printpos(0,0,vtr);
    delay(3000);
    
    while( 1 )
    {
        lcd.clr();
        indice = 0;
        wifi.canal_comunicacao();

        fifo_filtro();
        lcd.printpos(0,0,vtr);
        delay(3000);

        for(unsigned char a=0; a<=20000; a++ )
        {
            lcd.clr();
            indice = 0;
            fifo_filtro();
            lcd.printpos(0,0,vtr);
            delay(3000);
        }
    }
}
