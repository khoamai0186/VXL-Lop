/*
 * fsm_automatic.c
 *
 *  Created on: Oct 4, 2022
 *      Author: USER
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		HAL_GPIO_WritePin(LED_RED_Port, LED_RED_Pin, 1);
		HAL_GPIO_WritePin(LED_YELLOW_Port, LED_YELLOW_Pin, 1);
		HAL_GPIO_WritePin(LED_GREEN_Port, LED_GREEN_Pin, 1);
		status = AUTO_RED;
		setTimer1(500);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED_Port, LED_RED_Pin, 0);
		HAL_GPIO_WritePin(LED_YELLOW_Port, LED_YELLOW_Pin, 1);
		HAL_GPIO_WritePin(LED_GREEN_Port, LED_GREEN_Pin, 1);
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(300);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED_Port, LED_RED_Pin, 1);
		HAL_GPIO_WritePin(LED_YELLOW_Port, LED_YELLOW_Pin, 1);
		HAL_GPIO_WritePin(LED_GREEN_Port, LED_GREEN_Pin, 0);
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(200);
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(LED_RED_Port, LED_RED_Pin, 1);
		HAL_GPIO_WritePin(LED_YELLOW_Port, LED_YELLOW_Pin, 0);
		HAL_GPIO_WritePin(LED_GREEN_Port, LED_GREEN_Pin, 1);
		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(500);
		}
		break;
	default:
		break;
	}
}
