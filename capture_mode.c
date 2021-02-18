/*
 * File:   capture_mode.c
 * Author: Mohamed Hamdi
 * please visit my youtube channel:https://www.youtube.com/channel/UCzt_0MFbJiT93KSR74pW6Jw
 */

#include <xc.h>
#include "config.h"
#include <stdio.h>
#define _XTAL_FREQ 4000000

void main(void)
{
    //making portD output pins
    TRISD = 0x00;
    //making portB output pins
    TRISB = 0x00;
    //Set the intial state for ccp1 and timer
    PORTD = 0x00;
    PORTB = 0x00;
    //configuration for timer to operate in counter mode
    TMR1 = 0;
    T1CKPS0 = 0;
    T1CKPS1 = 0;
    TMR1CS = 1;
    T1OSCEN = 1;
    T1SYNC = 0;
    TMR1ON = 1;

    //configuration for ccp1 module to operate in capture mode
    CCP1M0 = 1;
    CCP1M1 = 0;
    CCP1M2 = 1;
    CCP1M3 = 0;
    CCP1IE = 1;
    PEIE = 1;
    GIE = 1;
    while (1)
    {

        // DO What you want
    }
    return;
}
void __interrupt() ISR()
{
    if (CCP1IF)
    {
        PORTB = CCPR1;
        CCP1IF = 0;
    }
}