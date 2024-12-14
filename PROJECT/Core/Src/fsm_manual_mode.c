/*
 * fsm_manual_mode.c
 *
 *  Created on: Dec 2, 2024
 *      Author: ADMIN
 */


/*
 * fsm_manual.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
#include "fsm_manual_mode.h"
#include "global.h"
#include "led_display.h"
#include "input_processing.h"
#include "fsm_automatic.h"
int counter_manual = 0;
void change_fsm(void){
	if(ProcessButton2()){
		counterMode = 1;
		statusx = AUTO_RED;
		statusy = AUTO_GREEN;
		InitLED();
		number_clock1 = Time_red/10;
		counter_x = Time_red;
		number_clock2 = Time_green/10;
		counter_y = Time_green;
	}
}
void fsm_manual_run(void){
	switch(statusx){
	case MANUAL_REDX_GREENY:
		//TODO
		DisplayREDX();
		DisplayGREENY();
		change_fsm();
		WalkingX();
		StopY();
		if (counterMode == 2){
			statusx = MANUAL_REDX_YELLOWY;
			InitLED();
			counter_manual = 50;
		}
		break;
	case MANUAL_REDX_YELLOWY:
		DisplayREDX();
		DisplayYELLOWY();
		change_fsm();
		if (counterMode == 3){
			statusx = MANUAL_GREENX_REDY;
			InitLED();
		}
		if(counter_manual == 0){
			statusx = MANUAL_GREENX_REDY;
			counterMode = 3;
			InitLED();
		}
		break;
	case MANUAL_GREENX_REDY:
		DisplayGREENX();
		DisplayREDY();
		change_fsm();
		StopX();
		WalkingY();
		if (counterMode == 4){
			statusx = MANUAL_YELLOWX_REDY;
			InitLED();
			counter_manual = 50;
		}
		break;
	case MANUAL_YELLOWX_REDY:
		DisplayYELLOWX();
		DisplayREDY();
		change_fsm();
		if (counterMode == 1){
			statusx = MANUAL_REDX_GREENY;
			InitLED();
		}
		if(counter_manual == 0){
			statusx = MANUAL_REDX_GREENY;
			counterMode = 1;
			InitLED();
		}
		break;
	default:
		break;
	}
	if(counter_manual > 0){
		counter_manual--;
	}
}

