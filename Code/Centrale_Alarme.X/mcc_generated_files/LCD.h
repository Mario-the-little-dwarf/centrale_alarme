
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#define LCD_ADDRESS 0x3E 
  

void commande_LCD(uint8_t value);
void write_LCD(uint8_t value);
void pos_LCD(int ligne, int colonne);
void clear_LCD(void);