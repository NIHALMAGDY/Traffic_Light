/*
 * Traffic_Light.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Lenovo
 */
#include<avr/io.h>
#include<avr/delay.h>
#define F_CPU 8000000
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
void main(void) {
	DDRA = 0b11111111;
	DDRC = 0b11111111;
	DDRB = 0b11111111;

	u8 i, j;
	u8 seg[10] = { 0b00000011, 0b10011111, 0b00100101, 0b00001101, 0b10011001,
			0b01001001, 0b01000001, 0b00011101, 0b00000001, 0b00001001 };
	for (i = 0; i <= 1; i++) {
		PORTB = 0b00000001;
		PORTA = seg[0];
		PORTC = seg[i];
		for (j = 0; j <= 9; j++) {
			PORTA = seg[j];
			_delay_ms(1000);
		}
	}

	for (i = 0; i <= 2; i++) {
		PORTB = 0b00000010;
		PORTA = seg[0];
		PORTC = seg[i];
		for (j = 0; j <= 9; j++) {
			PORTA = seg[j];
			_delay_ms(1000);
		}
	}

	for (i = 0; i <= 1; i++) {
		PORTB = 0b00000100;
		PORTA = seg[0];
		PORTC = seg[i];
		for (j = 0; j <= 9; j++) {
			PORTA = seg[j];
			_delay_ms(1000);
		}
	}
}
