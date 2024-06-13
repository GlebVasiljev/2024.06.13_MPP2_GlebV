/*
 * 2024.06.13_MPP2_GlebV.c
 *
 * Created: 13/06/2024 10:16:43
 * Author : Student
 */ 
#include "main.h"
#define USART_Buffer_lenght 5



uint8_t symbol = 63;
uint8_t data;
uint8_t data_arr[5] = {0x0A, 0x0B, 0x0C, 0x0E, 0x0F};
uint8_t data_buffer[USART_Buffer_lenght];

volatile uint16_t adc_value = 0;
volatile float voltage = 0.0;

static uint8_t temperatur = 0;
static uint8_t counter = 0;
float calculate_termistor_res()
{
	return voltage / 0.00025; // 0.00025 = 2,5 V / 10kR 
}

float calculate_temp()
{
	
	return pow(( 1/298 + 1/3950 * log10(calculate_termistor_res() / 10000)), -1) - 273;
}

void display_controll()
{	
	PORTB = 0x00;
	int right_diplay_value = temperatur % 10;
	int left_display_value =  temperatur / 10;
	// PB 0 - right display
	PORTB = 0x01;
	PORTD = right_diplay_value << 4;
	asm("nop");
	asm("nop");
	asm("nop");
	
	PORTB = 0x00;
	// PB 1 - left display
	PORTB = 0x02;
	PORTD = right_diplay_value << 4;
	asm("nop");
	asm("nop");
	asm("nop");
	
	PORTB = 0x00;
} 

int main(void)
{
    DDRD = 0b11110111;
    DDRB = 0b00000011;
    DDRC = 0b00000000;
	
    PORTB = 0x03;
	
    My_Init_TIM0();
    My_Init_TIM1();
    My_TIM_Start(TIM0,TIM0_PRESCALER_FACTOR_1024);
    My_TIM_Start(TIM1,TIM1_PRESCALER_FACTOR_1024);
    
	My_Init_ADC();
	My_ADC_Read(0);
    My_Init_USART();
	
	
	sei();
    while (1) 
    {
		
    }
}

ISR(TIMER0_COMPA_vect)
{	
	
	
	
}

ISR(TIMER1_COMPA_vect)
{
	//display_controll();
	PORTD = counter << 4;
	counter++;
	if( counter == 10)
	{
		counter = 0;
	}
}

// write temperature data 
ISR(ADC_vect)

{
	adc_value = (ADCH << 8) | ADCL;
	voltage = My_ADC_convert_to_voltage(adc_value);
}

ISR(USART_RX_vect)
{
	//data = My_USART0_ReciveByte();
	if(My_USART0_ReciveString(data_buffer, USART_Buffer_lenght) == 1)
	{
		switch(Process_command(data_buffer))
		{
			case 0:
			//Error
			break;
			
			case 1:
			//Read T0 data
			My_ADC_Read(0);
			//Write T0 data to clock
			
			break;
			
			case 2:
			//Read T1 data
			My_ADC_Read(1);
			//Write T1 data to clock
			break;
			
			case 3:
			//Read T2 data
			My_ADC_Read(2);
			//Write T2 data to clock
			break;
		}
		
	}

	My_USART0_TransmitByte(symbol);
	PORTB ^= (1 << PORTB5);
}