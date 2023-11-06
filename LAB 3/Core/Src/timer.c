#include "main.h"
#include "input_reading.h"
#include "Led.h"

#define GREEN 3
#define RED 5
#define YELLOW 2
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
static int Mode = 0;
int debounce;
static int debounce1;
static int debounce2;
static int debounce3;
static int SecondCount;
static int RED1 = RED;
static int GREEN1 = GREEN;
static int YELLOW1 = YELLOW;
static int TempRED1 = RED;
static int TempGREEN1 = GREEN;
static int TempYELLOW1 = YELLOW;


void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim)
{
	if (Intitalizer == 0){
		TotalTime2 = TotalTime2*TicktoSecond;
		TotalTime = TotalTime*TicktoSecond;
		R = RED1*TicktoSecond;
		G = GREEN1*TicktoSecond;
		Y = YELLOW1*TicktoSecond;
		R1 = RED1;
		G1 = GREEN1;
		Y1 = YELLOW1;
		R2 = RED1;
		G2 = GREEN1;
		Y2 = YELLOW1;
		DisplayCycleTime = TicktoSecond / 2;
		DisplayCycleTime1 = DisplayCycleTime;
		Intitalizer = 1;
		debounce = TicktoSecond/2;
		debounce1 = debounce;
		debounce2 = debounce;
		debounce3 = debounce;
		SecondCount = TicktoSecond/2;
	}

	if ( HAL_GPIO_ReadPin (OUT13_GPIO_Port , OUT13_Pin) == GPIO_PIN_RESET && debounce1>= debounce){
		if (Mode == 0){
			HAL_GPIO_WritePin ( OUT0_GPIO_Port , OUT0_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT1_GPIO_Port , OUT1_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT2_GPIO_Port , OUT2_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT3_GPIO_Port , OUT3_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT4_GPIO_Port , OUT4_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT5_GPIO_Port , OUT5_Pin ,GPIO_PIN_SET);
			flipflop = 0;
			flipflop1 = 0;
			Mode++;
			LEDfirstSetNum = RED1;
			LEDSecondSetNum = Mode;
		}
		else if (Mode == 1){
			HAL_GPIO_WritePin ( OUT0_GPIO_Port , OUT0_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT1_GPIO_Port , OUT1_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT2_GPIO_Port , OUT2_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT3_GPIO_Port , OUT3_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT4_GPIO_Port , OUT4_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT5_GPIO_Port , OUT5_Pin ,GPIO_PIN_SET);
			flipflop = 0;
			flipflop1 = 0;
			Mode++;
			LEDfirstSetNum = YELLOW1;
			LEDSecondSetNum = Mode;
		}
		else if (Mode == 2){
			HAL_GPIO_WritePin ( OUT0_GPIO_Port , OUT0_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT1_GPIO_Port , OUT1_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT2_GPIO_Port , OUT2_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT3_GPIO_Port , OUT3_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT4_GPIO_Port , OUT4_Pin ,GPIO_PIN_SET);
			HAL_GPIO_WritePin ( OUT5_GPIO_Port , OUT5_Pin ,GPIO_PIN_SET);
			flipflop = 0;
			flipflop1 = 0;
			Mode++;
			LEDfirstSetNum = GREEN1;
			LEDSecondSetNum = Mode;
		}
		else{
			TotalTime = (RED1 + GREEN1 + YELLOW1)*TicktoSecond;
			TotalTime2 = TotalTime;
			R1 = RED1;
			G1 = GREEN1;
			Y1 = YELLOW1;
			R2 = RED1;
			G2 = GREEN1;
			Y2 = YELLOW1;
			LEDindex = 0;
			LEDindex1 = 0;
			LEDfirstSetNum = 0;
			LEDSecondSetNum = 0;
			DisplayCycleTime1 = DisplayCycleTime;
			TempRED1 = RED1;
			TempYELLOW1 = YELLOW1;
			TempGREEN1 = GREEN1;
			Mode = 0;
		}
		debounce1 = 0;
	}
	debounce1++;
	switch(Mode){
		case 0:
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
							R1 = RED1;
						}
						break ;
					case 1:
						LEDfirstSetNum = G1;
						G1--;
						if (G1 == 0){
							LEDindex = 2;
							G1 = GREEN1;
						}
						break ;
					case 2:
						LEDfirstSetNum = Y1;
						Y1--;
						if (Y1 == 0){
							LEDindex = 0;
							Y1 = YELLOW1;
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
							G2 = GREEN1;
						}
						break ;
					case 1:
						LEDSecondSetNum = Y2;
						Y2--;
						if (Y2 == 0){
							LEDindex1 = 2;
							Y2 = YELLOW1;
						}
						break ;
					case 2:
						LEDSecondSetNum = R2;
						R2--;
						if (R2 == 0){
							LEDindex1 = 0;
							R2 = RED1;
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
			break;
		case 1:
			SecondCount--;
			if (SecondCount <= 0){
				HAL_GPIO_TogglePin(OUT0_GPIO_Port,OUT0_Pin);
				HAL_GPIO_TogglePin(OUT3_GPIO_Port,OUT3_Pin);
				SecondCount = TicktoSecond/2;
			}
			if ( HAL_GPIO_ReadPin (OUT14_GPIO_Port , OUT14_Pin) == GPIO_PIN_RESET && debounce2>= debounce){
				TempRED1++;
				LEDfirstSetNum = TempRED1;
				debounce2 = 0;
			}
			if ( HAL_GPIO_ReadPin (OUT15_GPIO_Port , OUT15_Pin) == GPIO_PIN_RESET && debounce3>= debounce){
				RED1 = TempRED1;
				LEDfirstSetNum = RED1;
				debounce3 = 0;
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
			debounce3++;
			debounce2++;
			DisplayCycleTime1--;
			break;
		case 2:
			SecondCount--;
			if (SecondCount <= 0){
				HAL_GPIO_TogglePin(OUT1_GPIO_Port,OUT1_Pin);
				HAL_GPIO_TogglePin(OUT4_GPIO_Port,OUT4_Pin);
				SecondCount = TicktoSecond/2;
			}

			if ( HAL_GPIO_ReadPin (OUT14_GPIO_Port , OUT14_Pin) == GPIO_PIN_RESET && debounce2>= debounce){
				TempYELLOW1++;
				LEDfirstSetNum = TempYELLOW1;
				debounce2 = 0;
			}
			if ( HAL_GPIO_ReadPin (OUT15_GPIO_Port , OUT15_Pin) == GPIO_PIN_RESET && debounce3>= debounce){
				YELLOW1 = TempYELLOW1;
				LEDfirstSetNum = YELLOW1;
				debounce3 = 0;
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
			debounce3++;
			debounce2++;
			DisplayCycleTime1--;
			break;
		case 3:
			SecondCount--;
			if (SecondCount <= 0){
				HAL_GPIO_TogglePin(OUT2_GPIO_Port,OUT2_Pin);
				HAL_GPIO_TogglePin(OUT5_GPIO_Port,OUT5_Pin);
				SecondCount = TicktoSecond/2;
			}

			if ( HAL_GPIO_ReadPin (OUT14_GPIO_Port , OUT14_Pin) == GPIO_PIN_RESET && debounce2>= debounce){
				TempGREEN1++;
				LEDfirstSetNum = TempGREEN1;
				debounce2 = 0;
			}
			if ( HAL_GPIO_ReadPin (OUT15_GPIO_Port , OUT15_Pin) == GPIO_PIN_RESET && debounce3>= debounce){
				GREEN1 = TempGREEN1;
				LEDfirstSetNum = GREEN1;
				debounce3 = 0;
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
			debounce3++;
			debounce2++;
			DisplayCycleTime1--;
			break;
	}
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



