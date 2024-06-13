/*
 * atmega328p_TIM.h
 *
 * Created: 13/06/2024 12:06:49
 *  Author: Student
 */ 
#include "avr/io.h"

#ifndef ATMEGA328P_TIM_H_
#define ATMEGA328P_TIM_H_

#define TIM0_DEACTIVE				0x00
#define TIM0_PRESCALER_FACTOR_1		0x01
#define TIM0_PRESCALER_FACTOR_8		0x02
#define TIM0_PRESCALER_FACTOR_64	0x03
#define TIM0_PRESCALER_FACTOR_256	0x04
#define TIM0_PRESCALER_FACTOR_1024	0x05

#define TIM1_DEACTIVE				0x00
#define TIM1_PRESCALER_FACTOR_1		0x01
#define TIM1_PRESCALER_FACTOR_8		0x02
#define TIM1_PRESCALER_FACTOR_64	0x03
#define TIM1_PRESCALER_FACTOR_256	0x04
#define TIM1_PRESCALER_FACTOR_1024	0x05

#define TIM2_DEACTIVE				0x00
#define TIM2_PRESCALER_FACTOR_1		0x01
#define TIM2_PRESCALER_FACTOR_8		0x02
#define TIM2_PRESCALER_FACTOR_64	0x03
#define TIM2_PRESCALER_FACTOR_256	0x04
#define TIM2_PRESCALER_FACTOR_1024	0x05

enum{
	TIM0 = 0,
	TIM1,
	TIM2
};




void My_Init_TIM0();
void My_Init_TIM1();
void My_Init_TIM2();
void My_TIM_Start(uint8_t tim_name, uint8_t prescailer_value);
void My_TIM_Stop (uint8_t tim_name);





#endif /* ATMEGA328P_TIM_H_ */