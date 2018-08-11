/*
 * File:   main.c
 * Author: Mateus
 *
 * Created on 15 de Maio de 2018, 01:21
 */


#include <xc.h>
#include "config.h"
#include "pic16f870.h"


void main() {

    //PORTA and PORTB Configuration
    TRISA = 0xFF;
    TRISB = 0x00;
   
    //A/D Conversion Clock Select Bits
    ADCON0bits.ADCS1 = 0;
    ADCON0bits.ADCS0 = 0;
    
    //Analog Channel Select Bits
    ADCON0bits.CHS2 = 0;
    ADCON0bits.CHS1 = 0;
    ADCON0bits.CHS0 = 0;
    
    //A/D Result Format Select Bits
    ADCON1bits.ADFM = 0;
    
    //A/D Port Configuration Control Bits
    ADCON1bits.PCFG3 = 0;
    ADCON1bits.PCFG2 = 0;
    ADCON1bits.PCFG1 = 0;
    ADCON1bits.PCFG0 = 0;
    
    //A/D Conversion Status Bit
    ADCON0bits.GO_nDONE = 1;
    
    //A/D On Bit
    ADCON0bits.ADON = 1;
    
    char leitura;
    
    while(1){
        if(ADCON0bits.GO_nDONE == 0){
           ADCON0bits.GO_nDONE = 1;
           leitura = ADRESH;
           
           if(leitura < 10)
               PORTBbits.RB0 = 1;
           else
               PORTBbits.RB0 = 0;
        }            
        
    }
}
