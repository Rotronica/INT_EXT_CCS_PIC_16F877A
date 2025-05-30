/*
 * Autor: Rodrigo C.C.
 * El siguiente programa realiza el uso de la interrupcion externa 
 */

#include <16f877a.h>
#fuses xt, nowdt, noput, noprotect, nolvp, nobrownout
#use delay(clock = 4M)
#define  TIME  500  //Tiempo de parpadeo del led conectado al PIN_B1
#INT_EXT //Especifica que la funcion que le sigue es una interrupcion #INT_RB,#INT_TIMER0..
//Funcion que atiende la interrupcion por externa
void INT_RB0(void){
   output_toggle(PIN_B2);  //Prende y apaga el led
}
//Prototipo de funciones
void configurar_hardware(void);

void configurar_hardware(void){
   set_tris_b(0x01); // Configura el puerto como entrada o salida
   output_low(PIN_B1);  //Se coloca en bajo el pin RB1
   output_low(PIN_B2);  //Se coloca en bajo el pin RB2
   //Se activan las resistencias pull-ups
   PORT_B_PULLUPS(true);
   //habilitar interrupcion INT RB0
   ext_int_edge(H_TO_L);   //Escoger por flanco de alto a bajo
   enable_interrupts(INT_EXT);   //Activar interrupcion externa
   enable_interrupts(GLOBAL);    //Activar interrupcion global
}

//Funcion principal
void main(void){
   configurar_hardware();  //Configuracion de registros
   while(true){
      output_toggle(PIN_B1);  //Enciende apaga led
      delay_ms(TIME);         //Tiempo de encendido
   }
}
