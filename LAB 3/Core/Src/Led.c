/*
 * Led.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Admin
 */
#include "main.h"




void display7SEGFirstSet(int num){
	HAL_GPIO_WritePin ( OUT6_GPIO_Port , OUT6_Pin,GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( OUT7_GPIO_Port , OUT7_Pin,GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( OUT8_GPIO_Port , OUT8_Pin,GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( OUT9_GPIO_Port , OUT9_Pin,GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( OUT10_GPIO_Port , OUT10_Pin,GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( OUT11_GPIO_Port , OUT11_Pin,GPIO_PIN_SET )  ;
	HAL_GPIO_WritePin ( OUT12_GPIO_Port , OUT12_Pin,GPIO_PIN_SET ) ;

	if(num == 0){
		HAL_GPIO_TogglePin ( OUT6_GPIO_Port , OUT6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT7_GPIO_Port , OUT7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT8_GPIO_Port , OUT8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT9_GPIO_Port , OUT9_Pin ) ;
		HAL_GPIO_TogglePin ( OUT10_GPIO_Port , OUT10_Pin ) ;
		HAL_GPIO_TogglePin ( OUT11_GPIO_Port , OUT11_Pin ) ;
	}
	else if (num == 1){
		HAL_GPIO_TogglePin ( OUT7_GPIO_Port , OUT7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT8_GPIO_Port , OUT8_Pin ) ;
	}
	else if (num == 2){
		HAL_GPIO_TogglePin ( OUT6_GPIO_Port , OUT6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT7_GPIO_Port , OUT7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT9_GPIO_Port , OUT9_Pin ) ;
		HAL_GPIO_TogglePin ( OUT10_GPIO_Port , OUT10_Pin ) ;
		HAL_GPIO_TogglePin ( OUT12_GPIO_Port , OUT12_Pin ) ;
	}
	else if (num == 3){
		HAL_GPIO_TogglePin ( OUT6_GPIO_Port , OUT6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT7_GPIO_Port , OUT7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT8_GPIO_Port , OUT8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT9_GPIO_Port , OUT9_Pin ) ;
		HAL_GPIO_TogglePin ( OUT12_GPIO_Port , OUT12_Pin ) ;
	}
	else if (num == 4){
		HAL_GPIO_TogglePin ( OUT7_GPIO_Port , OUT7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT8_GPIO_Port , OUT8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT11_GPIO_Port , OUT11_Pin ) ;
		HAL_GPIO_TogglePin ( OUT12_GPIO_Port , OUT12_Pin ) ;
	}
	else if (num == 5){
		HAL_GPIO_TogglePin ( OUT6_GPIO_Port , OUT6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT8_GPIO_Port , OUT8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT9_GPIO_Port , OUT9_Pin ) ;
		HAL_GPIO_TogglePin ( OUT11_GPIO_Port , OUT11_Pin ) ;
		HAL_GPIO_TogglePin ( OUT12_GPIO_Port , OUT12_Pin ) ;
	}
	else if (num == 6){
		HAL_GPIO_TogglePin ( OUT6_GPIO_Port , OUT6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT8_GPIO_Port , OUT8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT9_GPIO_Port , OUT9_Pin ) ;
		HAL_GPIO_TogglePin ( OUT10_GPIO_Port , OUT10_Pin ) ;
		HAL_GPIO_TogglePin ( OUT11_GPIO_Port , OUT11_Pin ) ;
		HAL_GPIO_TogglePin ( OUT12_GPIO_Port , OUT12_Pin ) ;
	}
	else if (num == 7){
		HAL_GPIO_TogglePin ( OUT6_GPIO_Port , OUT6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT7_GPIO_Port , OUT7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT8_GPIO_Port , OUT8_Pin ) ;
	}
	else if (num == 8){
		HAL_GPIO_TogglePin ( OUT6_GPIO_Port , OUT6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT7_GPIO_Port , OUT7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT8_GPIO_Port , OUT8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT9_GPIO_Port , OUT9_Pin ) ;
		HAL_GPIO_TogglePin ( OUT10_GPIO_Port , OUT10_Pin ) ;
		HAL_GPIO_TogglePin ( OUT11_GPIO_Port , OUT11_Pin ) ;
		HAL_GPIO_TogglePin ( OUT12_GPIO_Port , OUT12_Pin ) ;
	}
	else if (num == 9){
		HAL_GPIO_TogglePin ( OUT6_GPIO_Port , OUT6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT7_GPIO_Port , OUT7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT8_GPIO_Port , OUT8_Pin ) ;
		//HAL_GPIO_TogglePin ( OUT10_GPIO_Port , OUT10_Pin ) ;
		HAL_GPIO_TogglePin ( OUT11_GPIO_Port , OUT11_Pin ) ;
		HAL_GPIO_TogglePin ( OUT12_GPIO_Port , OUT12_Pin ) ;
	}
}

void display7SEGSecondSet(int num){
	HAL_GPIO_WritePin ( OUT2_3_GPIO_Port , OUT2_3_Pin,GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( OUT2_4_GPIO_Port , OUT2_4_Pin,GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( OUT2_5_GPIO_Port , OUT2_5_Pin,GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( OUT2_6_GPIO_Port , OUT2_6_Pin,GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( OUT2_7_GPIO_Port , OUT2_7_Pin,GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( OUT2_8_GPIO_Port , OUT2_8_Pin,GPIO_PIN_SET )  ;
	HAL_GPIO_WritePin ( OUT2_9_GPIO_Port , OUT2_9_Pin,GPIO_PIN_SET ) ;

	if(num == 0){
		HAL_GPIO_TogglePin ( OUT2_3_GPIO_Port , OUT2_3_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_4_GPIO_Port , OUT2_4_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_5_GPIO_Port , OUT2_5_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_6_GPIO_Port , OUT2_6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_7_GPIO_Port , OUT2_7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_8_GPIO_Port , OUT2_8_Pin ) ;
	}
	else if (num == 1){
		HAL_GPIO_TogglePin ( OUT2_4_GPIO_Port , OUT2_4_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_5_GPIO_Port , OUT2_5_Pin ) ;
	}
	else if (num == 2){
		HAL_GPIO_TogglePin ( OUT2_3_GPIO_Port , OUT2_3_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_4_GPIO_Port , OUT2_4_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_6_GPIO_Port , OUT2_6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_7_GPIO_Port , OUT2_7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_9_GPIO_Port , OUT2_9_Pin ) ;
	}
	else if (num == 3){
		HAL_GPIO_TogglePin ( OUT2_3_GPIO_Port , OUT2_3_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_4_GPIO_Port , OUT2_4_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_5_GPIO_Port , OUT2_5_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_6_GPIO_Port , OUT2_6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_9_GPIO_Port , OUT2_9_Pin ) ;
	}
	else if (num == 4){
		HAL_GPIO_TogglePin ( OUT2_4_GPIO_Port , OUT2_4_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_5_GPIO_Port , OUT2_5_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_8_GPIO_Port , OUT2_8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_9_GPIO_Port , OUT2_9_Pin ) ;
	}
	else if (num == 5){
		HAL_GPIO_TogglePin ( OUT2_3_GPIO_Port , OUT2_3_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_5_GPIO_Port , OUT2_5_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_6_GPIO_Port , OUT2_6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_8_GPIO_Port , OUT2_8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_9_GPIO_Port , OUT2_9_Pin ) ;
	}
	else if (num == 6){
		HAL_GPIO_TogglePin ( OUT2_3_GPIO_Port , OUT2_3_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_5_GPIO_Port , OUT2_5_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_6_GPIO_Port , OUT2_6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_7_GPIO_Port , OUT2_7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_8_GPIO_Port , OUT2_8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_9_GPIO_Port , OUT2_9_Pin ) ;
	}
	else if (num == 7){
		HAL_GPIO_TogglePin ( OUT2_3_GPIO_Port , OUT2_3_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_4_GPIO_Port , OUT2_4_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_5_GPIO_Port , OUT2_5_Pin ) ;
	}
	else if (num == 8){
		HAL_GPIO_TogglePin ( OUT2_3_GPIO_Port , OUT2_3_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_4_GPIO_Port , OUT2_4_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_5_GPIO_Port , OUT2_5_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_6_GPIO_Port , OUT2_6_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_7_GPIO_Port , OUT2_7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_8_GPIO_Port , OUT2_8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_9_GPIO_Port , OUT2_9_Pin ) ;
	}
	else if (num == 9){
		HAL_GPIO_TogglePin ( OUT2_3_GPIO_Port , OUT2_3_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_4_GPIO_Port , OUT2_4_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_5_GPIO_Port , OUT2_5_Pin ) ;
		//HAL_GPIO_TogglePin ( OUT2_7_GPIO_Port , OUT2_7_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_8_GPIO_Port , OUT2_8_Pin ) ;
		HAL_GPIO_TogglePin ( OUT2_9_GPIO_Port , OUT2_9_Pin ) ;
	}
}

void update7SEGFirstSet ( int index,int first,int second) {
switch ( index ) {
	case 0:
// Display the first 7 SEG with led_buffer [0]
		display7SEGFirstSet(first);
		break ;
	case 1:
// Display the second 7 SEG with led_buffer [1]
		display7SEGFirstSet(second);
		break ;
	default :
		break ;
	}
}

void update7SEGSecondSet ( int index,int first,int second) {
switch ( index ) {
	case 0:
// Display the first 7 SEG with led_buffer [0]
		display7SEGSecondSet(first);
		break ;
	case 1:
// Display the second 7 SEG with led_buffer [1]
		display7SEGSecondSet(second);
		break ;
	default :
		break ;
	}
}

