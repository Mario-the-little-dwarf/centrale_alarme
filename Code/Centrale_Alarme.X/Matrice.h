/* 
 * File:  Matrice.h 
 * Author: 
 * Comments:
 * Revision history: 
 */


#include <xc.h> // include processor files - each processor file is guarded.
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#define LCD_ADDRESS 0x3E 


/************Variables_Matrice**********/
char clavier[4][4] =   {{'1', '2', '3', 'A'},
                        {'4', '5', '6', 'B'},
                        {'7', '8', '9', 'C'},
                        {'*', '0', '#', 'D'}};
char valeur;
int compteur=0, appui, simultane, new_value;

void lecture_mat(void);
/*Cette fonction lit automatiquement les valeurs tapées*/