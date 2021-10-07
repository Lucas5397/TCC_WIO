#ifndef SERIAL_IN_H
#define SERIAL_IN_H
#define  SH     TRISAbits.TRISA3

void serial_init(void);
void serial_in(void);
char ler_serial (void);

#endif