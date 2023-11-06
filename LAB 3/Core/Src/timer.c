#include "main.h"
#include "input_reading.h"
#include "Led.h"

#define GREEN 10
#define RED 15
#define YELLOW 5
#define Tick 10
int TicktoSecond = 1000/Tick;
int TotalTime = GREEN + RED+ YELLOW;
static int TotalTime2 = GREEN + RED + YELLOW;
static int Intitalizer = 0;
int R,G,Y;
int R1,G1,Y1,R2,G2,Y2;
int LEDindex = 0;
static int LEDindex1 = 0;
static int LEDfirstSetNum = 0;
int LEDSecondSetNum = 0;
int DisplayCycleTime;
static int DisplayCycleTime1;
static int flipflop = 0;
static int flipflop1 = 0;

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim)
{
	if (Intitalizer == 0){
		TotalTime2 = TotalTime2*TicktoSecond;
		TotalTime = TotalTime*TicktoSecond;
		R = RED*TicktoSecond;
		G = GREEN*TicktoSecond;
		Y = YELLOW*TicktoSecond;
		R1 = RED;
		G1 = GREEN;
		Y1 = YELLOW;
		R2 = RED;
		G2 = GREEN;
		Y2 = YELLOW;
		DisplayCycleTime = TicktoSecond / 4;
		DisplayCycleTime1 = DisplayCycleTime;
		Intitalizer = 1;
	}



	if( TotalTime2 <= TotalTime && TotalTime2 > TotalTime - R) {
		HAL_GPIO_WritePin ( OUT0_GPIO_Port , OUT0_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin ( OUT1_GPIO_Port , OUT1_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin ( OUT2_GPIO_Port , OUT2_Pin ,GPIO_PIN_SET);

	}
	else if (TotalTime2 <= TotalTime - R && TotalTime2 > TotalTime - R - G){
		HAL_GPIO_WritePin ( OUT0_GPIO_Port , OUT0_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin ( OUT1_GPIO_Port , OUT1_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin ( OUT2_GPIO_Port , OUT2_Pin ,GPIO_PIN_RESET);
	}
	else if (TotalTime2 <= TotalTime - R - G && TotalTime2 > 0){
		HAL_GPIO_WritePin ( OUT0_GPIO_Port , OUT0_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin ( OUT1_GPIO_Port , OUT1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin ( OUT2_GPIO_Port , OUT2_Pin ,GPIO_PIN_SET);
	}
	if (TotalTime2 % TicktoSecond == 0){

		switch (LEDindex) {
			case 0:
				LEDfirstSetNum = R1;
				R1--;
				if (R1 == 0){
					LEDindex = 1;
					R1 = RED;
				}
				break ;
			case 1:
				LEDfirstSetNum = G1;
				G1--;
				if (G1 == 0){
					LEDindex = 2;
					G1 = GREEN;
				}
				break ;
			case 2:
				LEDfirstSetNum = Y1;
				Y1--;
				if (Y1 == 0){
					LEDindex = 0;
					Y1 = YELLOW;
				}
				break ;
			default :
				break ;
			}
		switch (LEDindex1) {
			case 0:
				LEDSecondSetNum = G2;
				G2--;
				if (G2 == 0){
					LEDindex1 = 1;
					G2 = GREEN;
				}
				break ;
			case 1:
				LEDSecondSetNum = Y2;
				Y2--;
				if (Y2 == 0){
					LEDindex1 = 2;
					Y2 = YELLOW;
				}
				break ;
			case 2:
				LEDSecondSetNum = R2;
				R2--;
				if (R2 == 0){
					LEDindex1 = 0;
					R2 = RED;
				}
				break ;
			default :
				break ;
			}

		}


	if( TotalTime2 <= TotalTime && TotalTime2 > TotalTime - G) {
		HAL_GPIO_WritePin ( OUT3_GPIO_Port , OUT3_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin ( OUT4_GPIO_Port , OUT4_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin ( OUT5_GPIO_Port , OUT5_Pin ,GPIO_PIN_RESET);
	}
	else if (TotalTime2 <= TotalTime - G && TotalTime2 > TotalTime - Y - G){
		HAL_GPIO_WritePin ( OUT3_GPIO_Port , OUT3_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin ( OUT4_GPIO_Port , OUT4_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin ( OUT5_GPIO_Port , OUT5_Pin ,GPIO_PIN_SET);
	}
	else if (TotalTime2 <= TotalTime - Y - G && TotalTime2 > 0){
		HAL_GPIO_WritePin ( OUT3_GPIO_Port , OUT3_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin ( OUT4_GPIO_Port , OUT4_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin ( OUT5_GPIO_Port , OUT5_Pin ,GPIO_PIN_SET);
	}

	if (DisplayCycleTime1 <= 0){
		switch(flipflop){
			case 0:
				HAL_GPIO_WritePin ( OUT2_12_GPIO_Port , OUT2_12_Pin ,GPIO_PIN_RESET);
				HAL_GPIO_WritePin ( OUT2_13_GPIO_Port , OUT2_13_Pin ,GPIO_PIN_SET);
				update7SEGFirstSet(0,LEDfirstSetNum/10,LEDfirstSetNum%10);
				flipflop = 1;
				break;
			case 1:
				HAL_GPIO_WritePin ( OUT2_12_GPIO_Port , OUT2_12_Pin ,GPIO_PIN_SET);
				HAL_GPIO_WritePin ( OUT2_13_GPIO_Port , OUT2_13_Pin ,GPIO_PIN_RESET);
				update7SEGFirstSet(1,LEDfirstSetNum/10,LEDfirstSetNum%10);
				flipflop = 0;
				break;
			default :
				break ;

		}
		switch(flipflop1){
			case 0:
				HAL_GPIO_WritePin ( OUT2_14_GPIO_Port , OUT2_14_Pin ,GPIO_PIN_RESET);
				HAL_GPIO_WritePin ( OUT2_15_GPIO_Port , OUT2_15_Pin ,GPIO_PIN_SET);
				update7SEGSecondSet(0,LEDSecondSetNum/10,LEDSecondSetNum%10);
				flipflop1 = 1;
				break;
			case 1:
				HAL_GPIO_WritePin ( OUT2_14_GPIO_Port , OUT2_14_Pin ,GPIO_PIN_SET);
				HAL_GPIO_WritePin ( OUT2_15_GPIO_Port , OUT2_15_Pin ,GPIO_PIN_RESET);
				update7SEGSecondSet(1,LEDSecondSetNum/10,LEDSecondSetNum%10);
				flipflop1 = 0;
				break;
			default :
				break ;

		}
		DisplayCycleTime1 = DisplayCycleTime;
	}

	if (TotalTime2 <= 0){
		TotalTime2 = TotalTime;
	}

	DisplayCycleTime1--;
	TotalTime2--;

	if( htim -> Instance == TIM2 ) {
		button_reading();
	}
}

//void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
//{

	//if( htim -> Instance == TIM2 ) {
		//button_reading() ;
	//}
//}



