/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F47Q10
        Driver Version    :  2.00
*/

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"

/***Include persos***/
#include "LCD.h"

void configuration(void);
void lecture_mat(void);


int overflow = 0; int pass = 1; int colonne = 0;

/************Variables_Matrice**********/
char clavier[4][4] =   {{'1', '2', '3', 'A'},
                        {'4', '5', '6', 'B'},
                        {'7', '8', '9', 'C'},
                        {'*', '0', '#', 'D'}};
char valeur;
int compteur=0, appui, simultane, new_value;
    
void main(void)
{
    SYSTEM_Initialize();// Initialize the device

    configuration();
    while (1)
    {   
//        pos_LCD(0,15);
//        write_LCD('K');__delay_ms(2000);
//        pos_LCD(1,8);
//        write_LCD('K');__delay_ms(2000);
        
        lecture_mat();
        
        pos_LCD(1,8);write_LCD(valeur);__delay_ms(100);
        new_value = valeur;
        //clear_LCD();
        
        if (compteur>=2) 
        {//clear_LCD();commande_LCD(0x01);__delay_ms(50);
        valeur = 'S';compteur=0;}
        
        else if(new_value == valeur)
        {
            //commande_LCD(0x01);__delay_ms(50);
            valeur = 'R';__delay_ms(10);compteur=0;
        }
        
        //if(compteur!=2){write_LCD(valeur);}
        //write_LCD(0xFF); 
        //if (overflow > 1){commande_LCD(0x01);overflow=0;}//Mettre a 1 pour clear
    }
}

void configuration(void)
{
    /*Config des pins*/
    /*Re-Routage du module*/
    SSP1CLKPPS = 0x13; //RC3->MSSP1:SCL1;
    RC3PPS = 0x0F; //RC3->MSSP1:SCL1;
    RC4PPS = 0x10; //RC4->MSSP1:SDA1;
    SSP1DATPPS = 0x14; //RC4->MSSP1:SDA1; 

    /*Initialisation I2C*/
    I2C1_Initialize(); 
    // Démarrage
    commande_LCD(0x2C);
    __delay_ms(100);
    commande_LCD(0x2C);
    __delay_ms(100);
    commande_LCD(0x2C);
    __delay_ms(100);
    commande_LCD(0x2C);
    __delay_ms(100);
    // ecran curseur clignotant, etc...
    commande_LCD(0x0F);
    __delay_ms(1000);
    // effacer l'écran
    commande_LCD(0x01);    
}

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