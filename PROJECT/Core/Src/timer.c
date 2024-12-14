/*
 * timer.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Genki
 */
#include "main.h"
#include "timer.h"
#include "input_reading.h"
#include "Scheduler.h"
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim -> Instance == TIM2){
		button_reading();
		SCH_Update();
	}
}
