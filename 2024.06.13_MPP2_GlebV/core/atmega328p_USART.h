/*
 * atmega328p_USART.h
 *
 * Created: 13/06/2024 12:08:26
 *  Author: Student
 */ 
#include "avr/io.h"
#include <string.h>

#ifndef ATMEGA328P_USART_H_
#define ATMEGA328P_USART_H_


void My_Init_USART();
void My_USART0_TransmitByte(uint8_t symbol);
uint8_t My_USART0_ReciveByte();
uint8_t My_USART0_ReviveString(uint8_t *data_arr, uint8_t lenght);
uint8_t Process_command(uint8_t *data_arr);


#endif /* ATMEGA328P_USART_H_ */