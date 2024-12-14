/*
 * fsm_automatic.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Genki
 */

#include "fsm_automatic.h"
#include "input_processing.h"
#include "main.h"
#include "i2c-lcd.h"
#include "stdio.h"
int DisplayCounter = 0;
int mode2_flag = 0;
int mode3_flag = 0;
int mode4_flag = 0;
int save_counterTimeSet = 0;
int Time_red = 50;
int Time_green = 30;
int Time_yellow = 20;
int counter_x = 0;
int counter_y = 0;
void SetMode(void){
	if(ProcessButton3() == 1){
		if(counterMode == 1){
			char stry[16];
			char strx[16];
			sprintf(stry, "  Manual Mode ");
			sprintf(strx, "          ");
			lcd_goto_XY(1, 0);
			lcd_send_string(strx);
			lcd_goto_XY(2, 0);
			lcd_send_string(stry);
			statusx = MANUAL_REDX_GREENY;
			statusy = MANUAL_REDX_GREENY;
			counterMode = 1;
			InitLED();
		}
		if(counterMode == 2){
			Time_red = counterTimeSet * 10;
			if(Time_red <= Time_green || Time_red <= Time_yellow){
				Time_red = Time_green + Time_yellow;
			}
			else{
				Time_green = Time_red - Time_yellow;
			}
			number_clock1 = Time_red;
			number_clock2 = Time_green;
		}
		if(counterMode == 3){
			Time_green = counterTimeSet * 10;
			if(Time_red <= Time_green){
				Time_red =  Time_yellow + Time_green;
			}
			else{
				Time_yellow = Time_red - Time_green;
			}
			number_clock1 = Time_red;
			number_clock2 = Time_green;
		}
		if(counterMode == 4){
			Time_yellow = counterTimeSet * 10;
			if(Time_red <= Time_yellow){
				Time_red =  Time_yellow + Time_green;
			}
			else{
				Time_green = Time_red - Time_yellow;
			}
			number_clock1 =  Time_red;
			number_clock2 = Time_green;
		}
	}
}
void ChangeModeX(void){
	if(counterMode == 1){
		mode4_flag = 0;
	}
	if(counterMode == 2){
		statusx = MAN_RED;
		InitLED();
	}
	if(counterMode == 3){
		mode2_flag = 0;
		statusx = MAN_GREEN;
		InitLED();
	}
	if(counterMode == 4){
		mode3_flag = 0;
		statusx = MAN_YELLOW;
		InitLED();
	}
}
void ChangeModeY(void){
	if(counterMode == 1){
		mode4_flag = 0;
	}
	if(counterMode == 2){
		statusy = MAN_RED;
		InitLED();
	}
	if(counterMode == 3){
		mode2_flag = 0;
		statusy = MAN_GREEN;
		InitLED();
	}
	if(counterMode == 4){
		mode3_flag = 0;
		statusy = MAN_YELLOW;
		InitLED();
	}
}
void fsm_clock(void) {
	if(statusx == AUTO_RED || statusx == AUTO_GREEN || statusx == AUTO_YELLOW){
		if(number_clock1 > 0){
			number_clock1--;
		}
		if(number_clock2 > 0){
			number_clock2--;
		}
        char stry[16];
        char strx[16];
        sprintf(strx, "Road X: %d    ", number_clock1);
        sprintf(stry, "Road Y: %d    ", number_clock2);
        lcd_goto_XY(1, 0);
        lcd_send_string(strx);
        lcd_goto_XY(2, 0);
        lcd_send_string(stry);
	}
}
void fsm_mode(void) {
	if(statusx == MAN_RED || statusx == MAN_GREEN || statusx == MAN_YELLOW){
        char stry[16];
        char strx[16];
        sprintf(stry, "Time:   %d ", counterTimeSet);
        sprintf(strx, "Mode:   %d ", counterMode);
        lcd_goto_XY(1, 0);
        lcd_send_string(strx);
        lcd_goto_XY(2, 0);
        lcd_send_string(stry);
	}
}
void Walking_LED(void){
	if((statusy == AUTO_YELLOW  && number_clock2 <= 3) || statusx == MANUAL_REDX_YELLOWY){
		WalkingX_Blinking();
	}
	else if(statusx == AUTO_RED || statusx == MANUAL_REDX_GREENY || statusx == MANUAL_REDX_YELLOWY){
		WalkingX();
	}
	if((statusx == AUTO_YELLOW && number_clock1 <= 3) || statusx == MANUAL_YELLOWX_REDY){
		WalkingY_Blinnking();
	}
	else if(statusy == AUTO_RED || statusx == MANUAL_GREENX_REDY || statusx == MANUAL_YELLOWX_REDY){
		WalkingY();
	}
}
void fsm_automatic_runx(){
	switch(statusx){
	case INIT:
		statusx = AUTO_RED;
		counter_x = Time_red;
		number_clock1 = counter_x/10;
		break;
	case AUTO_RED:
		DisplayREDX();
		SetMode();
		ChangeModeX();
		if(counter_x <= 0){
			statusx = AUTO_GREEN;
			counter_x = Time_green;
			number_clock1 = counter_x/10;
		}
		break;
	case AUTO_GREEN:
		DisplayGREENX();
		SetMode();
		StopX();
		ChangeModeX();
		if(counter_x <= 0){
			statusx = AUTO_YELLOW;
			counter_x = Time_yellow;
			number_clock1 = counter_x/10;
		}
		break;
	case AUTO_YELLOW:
		DisplayYELLOWX();
		SetMode();
		ChangeModeX();
		if(counter_x <= 0){
			statusx = AUTO_RED;
			counter_x = Time_red;
			number_clock1 = counter_x/10;
		}
		break;
	default:
		break;
	}
	if(counter_x > 0){
		counter_x--;
	}
}
void fsm_automatic_runy(){
	switch(statusy){
	case INIT:
		DisplayGREENY();
		statusy = AUTO_GREEN;
		counter_y = Time_green;
		number_clock2 = counter_y/10;
		break;
	case AUTO_RED:
		DisplayREDY();
		SetMode();
		ChangeModeY();
		if(counter_y <= 0){
			statusy = AUTO_GREEN;
			counter_y = Time_green;
			number_clock2 = counter_y/10;
		}
		break;
	case AUTO_GREEN:
		DisplayGREENY();
		StopY();
		SetMode();
		ChangeModeY();
		if(counter_y <= 0){
			statusy = AUTO_YELLOW;
			counter_y = Time_yellow;
			number_clock2 = counter_y/10;
		}
		break;
	case AUTO_YELLOW:
		DisplayYELLOWY();
		SetMode();
		ChangeModeY();
		if(counter_y <= 0){
			statusy = AUTO_RED;
			counter_y = Time_red;
			number_clock2 = counter_y/10;
		}
		break;
	default:
		break;
	}
	if(counter_y > 0){
		counter_y--;
	}
}
