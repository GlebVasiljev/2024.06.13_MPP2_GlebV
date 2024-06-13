/*
 * ADC.h
 *
 * Created: 13/06/2024 13:49:20
 *  Author: Student
 */ 
#include "avr/io.h"
#include "avr/interrupt.h"
#ifndef ADC_H_
#define ADC_H_

void My_Init_ADC();
void My_ADC_Read(uint8_t adc_channel);
float My_ADC_convert_to_temp(uint16_t adc_value);


#endif /* ADC_H_ */