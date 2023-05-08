#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)
// https://wokwi.com/projects/363070419462614017

#define RED 2
#define YELLOW 1
#define GREEN 0

int main(void)
{
    BIT_SET(DDRB,RED);
    BIT_SET(DDRB,YELLOW);
    BIT_SET(DDRB,GREEN);
    while(1) {
        BIT_SET(PORTB, RED);
        BIT_CLEAR(PORTB, YELLOW);
        BIT_CLEAR(PORTB, GREEN);
		_delay_ms(15000);
        BIT_CLEAR(PORTB, RED);
        BIT_SET(PORTB, YELLOW);
        BIT_CLEAR(PORTB, GREEN);
		_delay_ms(3000);
        BIT_CLEAR(PORTB, RED);
        BIT_CLEAR(PORTB, YELLOW);
        BIT_SET(PORTB, GREEN);
		_delay_ms(15000);

    }
	return 0;
}