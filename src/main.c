/*
 * File:   main.c
 * Author: forshaw
 *
 * Created on September 3, 2021, 11:45 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

/*
 *
 */
int main(int argc, char** argv) {

    DDRB = 0b11111111;
    PORTB = 0b00000000;
    PORTB = 0b00100000;


    return 0;
}