#include <msp430.h>				


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= BIT0 | BIT6;					// configure P1.0 as output
	P1REN |= BIT3;                          // Enable Pull Up on SW2 (P1.3)
	volatile unsigned int i;		// volatile to prevent optimization
	while(1)
	{
		if(P1IN & BIT3)
		{
		    P1OUT |= BIT0;
		    P1OUT &= ~BIT6;
		}
		else
		{
		    P1OUT |= BIT6;
		    P1OUT &= ~BIT0;
		}
	}
}
