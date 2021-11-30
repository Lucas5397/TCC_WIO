/*
 * File:   esp8266.c
 * Author: 21193665
 *
 * Created on 29 de Outubro de 2021, 15:47
 */


#include <xc.h>
#include "wifi.h"
#include "ihm.h"

void Wifi_mode(unsigned char *d )
{
    if(d == 1) // modo de estação
    {
        lcd.clr();
        wifi_send("AT+CWMODE1\r\n");
    }

    if(d == 2) // modo SoftAP
    {
        lcd.clr();
        wifi_send("AT+CWMODE2\r\n");
    }
    if(d == 3) // modo SoftAP + estação
    {
        lcd.clr();
        wifi_send("AT+CWMODE3\r\n");
    }
    else // modo nulo
        lcd.clr();
        wifi_send("AT+CWMODE0\r\n");
}

void Wifi_connect(unsigned char *SSID, unsigned char *PASS )
{
    lcd.clr();
    wifi_send("AT+CWJAP=[<automation>],[<12345678>]\r\n");
}

void Wifi_ip( void )
{
//    lcd.clr();
//    wifi_send("AT+\r\n");
}
