/*
 * delay.c
 *
 *  Created on: Jan 27, 2022
 *      Author: atay
 */

#include "delay.h"

void delay_init()
{
	__HAL_RCC_TIM5_CLK_ENABLE();  // TIM5 ENABLE YAPILDI. RCC->APB1ENR |= 1<<3;

	TIM5->PSC  =  16-1 ;          //16M/16-1 1000Mh
	TIM5->ARR  =  0xffff;


	TIM5->CR1  |= 1<<0;           //enable timer
	while(!(TIM5->SR &(1<<0)));   //UIF bagragı 1 oldu mu diye bak
}
void delay_us(int time)
{
	TIM5->CNT = 0;
	while((TIM5->CNT) < time);

}
void delay_ms(int time)
{
	for (int i=0; i<time; i++){

		delay_us(1000);
	}

}
