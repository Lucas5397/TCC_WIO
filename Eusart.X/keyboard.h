#ifndef KEYBOARD_H
#define KEYBOARD_H

unsigned char previousKey( void );  // retorna Tecla Anterior.
unsigned char currentKey( void );   // retorna Tecla Atual.
unsigned char keyboard_scan( void ); // Varredura do teclado.
void keyboard_init( void );          // Inicializar hw de acesso ao teclado.

#endif
