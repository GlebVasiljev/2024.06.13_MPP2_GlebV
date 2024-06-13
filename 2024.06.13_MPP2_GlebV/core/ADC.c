/*
 * ADC.c
 *
 * Created: 13/06/2024 13:23:52
 *  Author: Student
 */ 
#include "ADC.h"
void My_Init_ADC()
{	
	//set default ADC read port 0 and Left adj
	ADMUX |= ( 0 << REFS0);
	ADMUX &= ~( 1 << REFS1);
	//ADMUX |= ( 1 << ADLAR);
	
	//set presclailer to 128 and ADC interrupt
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	ADCSRA |= (1 << ADEN) | (1 << ADIE);
	
	
}

void My_ADC_Read(uint8_t adc_channel)
{	
	
	ADMUX = (ADMUX & 0xF8) | adc_channel;
	// start conversation
	ADCSRA |= (1 << ADSC);
	ADCSRA &= ~(0 << ADIF);
}

float My_ADC_convert_to_voltage(uint16_t adc_value)
{
	return (adc_value * 5 ) / 1024.0 ;
}