#include "main.h"
#include "input_reading.h"

#define N0_OF_BUTTONS 3

enum ButtonState { BUTTON_RELEASED,BUTTON_PRESSED,BUTTON_PRESSED_MORE_THAN_1_SECOND } ;
static enum ButtonState buttonState = BUTTON_RELEASED ;
static enum ButtonState buttonState1 = BUTTON_RELEASED ;
static enum ButtonState buttonState2 = BUTTON_RELEASED ;
void fsm_for_input_processing ( void ) {
switch ( buttonState ){
	case BUTTON_RELEASED :
		if( is_button_pressed (0) ) {
			buttonState = BUTTON_PRESSED ;
			HAL_GPIO_WritePin ( OUT13_GPIO_Port , OUT13_Pin ,GPIO_PIN_SET);
		// INCREASE VALUE OF PORT A BY ONE UNIT
		}
	break ;
	case BUTTON_PRESSED :
		if (! is_button_pressed (0) ) {
			HAL_GPIO_WritePin ( OUT13_GPIO_Port , OUT13_Pin ,GPIO_PIN_RESET);
			buttonState = BUTTON_RELEASED ;

		}
		else {
			if( is_button_pressed_1s(0)) {

				buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
			}
		}
	break ;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND :
		if (! is_button_pressed (0) ) {
			HAL_GPIO_WritePin ( OUT13_GPIO_Port , OUT13_Pin ,GPIO_PIN_RESET);
			buttonState = BUTTON_RELEASED ;
		}
	break ;
	}


switch ( buttonState1 ){
	case BUTTON_RELEASED :
		if( is_button_pressed (1) ) {
			buttonState1 = BUTTON_PRESSED ;
			HAL_GPIO_WritePin ( OUT14_GPIO_Port , OUT14_Pin ,GPIO_PIN_SET);
		// INCREASE VALUE OF PORT A BY ONE UNIT
		}
	break ;
	case BUTTON_PRESSED :
		if (! is_button_pressed (1) ) {
			HAL_GPIO_WritePin ( OUT14_GPIO_Port , OUT14_Pin ,GPIO_PIN_RESET);
			buttonState1 = BUTTON_RELEASED ;
		}
		else {
			if( is_button_pressed_1s (1) ) {

				buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
			}
		}
	break ;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND :
		if (! is_button_pressed (1) ) {
			HAL_GPIO_WritePin ( OUT14_GPIO_Port , OUT14_Pin ,GPIO_PIN_RESET);
			buttonState1 = BUTTON_RELEASED ;
		}
	break ;
	}



switch ( buttonState2 ){
	case BUTTON_RELEASED :
		if( is_button_pressed (2) ) {
			buttonState2 = BUTTON_PRESSED ;
			HAL_GPIO_WritePin ( OUT15_GPIO_Port , OUT15_Pin ,GPIO_PIN_SET);
		// INCREASE VALUE OF PORT A BY ONE UNIT
		}
	break ;
	case BUTTON_PRESSED :
		if (! is_button_pressed (2) ) {
			HAL_GPIO_WritePin ( OUT15_GPIO_Port , OUT15_Pin ,GPIO_PIN_RESET);
			buttonState2 = BUTTON_RELEASED ;
		}
		else {
			if( is_button_pressed_1s (2) ) {

				buttonState2 = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
			}
		}
	break ;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND :
		if (! is_button_pressed (2) ) {
			HAL_GPIO_WritePin ( OUT15_GPIO_Port , OUT15_Pin ,GPIO_PIN_RESET);
			buttonState2 = BUTTON_RELEASED ;
		}
	break ;
	}


}

