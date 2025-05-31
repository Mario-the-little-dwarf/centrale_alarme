/*
 * File:   Matrice.c
 * Author: ADM
 *
 * Created on 31 mai 2025, 22:10
 */

#include "Matrice.h"

void lecture_mat(void)
{
    if(!RB4)
        {
            if(!RB0){overflow++;compteur++;valeur=clavier[0][0];__delay_ms(20);}//Affiche 1
            if(!RB1){overflow++;compteur++;valeur=clavier[1][0];__delay_ms(20);}//Affiche 4
            if(!RB3){overflow++;compteur++;valeur=clavier[2][0];__delay_ms(20);}//Affiche 7
            if(!RB2){overflow++;compteur++;valeur=clavier[3][0];__delay_ms(20);}//Affiche *
            //commande_LCD(0x01);__delay_ms(15);write_LCD(valeur);__delay_ms(10);
            LATB = 0b11011111;
        }
        
        //colonne 2
        if(!RB5)
        {
            if(!RB0){overflow++;compteur++;valeur=clavier[0][1];__delay_ms(20);}//Affiche 2
            if(!RB1){overflow++;compteur++;valeur=clavier[1][1];__delay_ms(20);}//Affiche 5
            if(!RB3){overflow++;compteur++;valeur=clavier[2][1];__delay_ms(20);}//Affiche 8
            if(!RB2){overflow++;compteur++;valeur=clavier[3][1];__delay_ms(20);}//Affiche 0
            //commande_LCD(0x01);__delay_ms(15);write_LCD(valeur);__delay_ms(10);
            LATB = 0b01111111;//LATB = 0b10111111;
        }
        
        //colonne 3
        if(!RB7) 
        {
            if(!RB0){overflow++;compteur++;valeur=clavier[0][2];__delay_ms(20);}//Affiche 3
            if(!RB1){overflow++;compteur++;valeur=clavier[1][2];__delay_ms(20);}//Affiche 6
            if(!RB3){overflow++;compteur++;valeur=clavier[2][2];__delay_ms(20);}//Affiche 9
            if(!RB2){overflow++;compteur++;valeur=clavier[3][2];__delay_ms(20);}//Affiche #
            //commande_LCD(0x01);__delay_ms(15);write_LCD(valeur);__delay_ms(10);
            LATB = 0b10111111;
        }  
        
        //colonne 4
        if(!RB6)
        {
            if(!RB0){overflow++;compteur++;valeur=clavier[0][3];__delay_ms(20);}//Affiche A
            if(!RB1){overflow++;compteur++;valeur=clavier[1][3];__delay_ms(20);}//Affiche B
            if(!RB3){overflow++;compteur++;valeur=clavier[2][3];__delay_ms(20);}//Affiche C
            if(!RB2){overflow++;compteur++;valeur=clavier[3][3];__delay_ms(20);}//Affiche D
            LATB = 0b11101111;
        }
}