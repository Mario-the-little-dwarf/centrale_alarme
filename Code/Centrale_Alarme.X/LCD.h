/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#include <xc.h> // include processor files - each processor file is guarded.
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#define LCD_ADDRESS 0x3E 
  
//Fonctions LCD de base
void commande_LCD(uint8_t value);
void write_LCD(uint8_t value);

void pos_LCD(int ligne, int colonne);
/*
    *pos_LCD(numero de ligne, numero de colonne)
    *lignes allant de 0 à 1 
    *colonnes allant de 0 à 15
    *Attention, utilise un clear lcd
 */

void clear_LCD(void);
/*Fais clear le LCD, 
 * c'est juste la commande appropriée pour le clear
 * Attention, pas de délai dans la fonction, délai à ajuster
 * personnellement*/