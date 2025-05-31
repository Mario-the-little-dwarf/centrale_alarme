/*
 * File:   LCD.c
 * Author: ADM
 *
 * Created on 31 mai 2025, 22:10
 */

#include "LCD.h"

void commande_LCD(uint8_t value)
{
 uint8_t transm[]= {0x00, 0x00};
 transm[0] = 0x80;
 transm[1] = value;
 I2C1_WriteNBytes(LCD_ADDRESS, transm, 2);
}

void write_LCD(uint8_t value)
{
 uint8_t transm[]= {0x00, 0x00};
 transm[0] = 0x40;
 transm[1] = value;
 I2C1_WriteNBytes(LCD_ADDRESS, transm, 2);
} 
void pos_LCD(int ligne, int colonne)
{
    /*lignes entre 0 et 1
     *colonnes entre 0 et 15 compris*/
    static int c, k;
    commande_LCD(0x01);__delay_ms(50);
    if(ligne == 0){}
    if(ligne == 1){for(k =0; k<40; k++){write_LCD(' ');__delay_ms(5);}}
    //ligne 2 atteinte lorsque 40 caracteres ecrits sur la ligne 1
    
    for(c=0; c<colonne; c++){write_LCD(' ');__delay_ms(5);}
}

void clear_LCD(void)
{
    commande_LCD(0x01);
}