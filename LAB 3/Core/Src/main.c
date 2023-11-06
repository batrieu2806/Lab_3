/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Led.h"
#include "input_processing.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  //
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
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
	extern int timer0_flag;
	setTimer0(10);
  HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(timer0_flag == 1) {
    /* USER CODE END WHILE */
	  fsm_for_input_processing ();
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
		setTimer0(10);
	  }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, OUT0_Pin|OUT1_Pin|OUT2_Pin|OUT3_Pin
                          |OUT4_Pin|OUT5_Pin|OUT6_Pin|OUT7_Pin
                          |OUT8_Pin|OUT9_Pin|OUT10_Pin|OUT11_Pin
                          |OUT12_Pin|OUT13_Pin|OUT14_Pin|OUT15_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, OUT2_12_Pin|OUT2_13_Pin|OUT2_14_Pin|OUT2_15_Pin
                          |OUT2_3_Pin|OUT2_4_Pin|OUT2_5_Pin|OUT2_6_Pin
                          |OUT2_7_Pin|OUT2_8_Pin|OUT2_9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : OUT0_Pin OUT1_Pin OUT2_Pin OUT3_Pin
                           OUT4_Pin OUT5_Pin OUT6_Pin OUT7_Pin
                           OUT8_Pin OUT9_Pin OUT10_Pin OUT11_Pin
                           OUT12_Pin OUT13_Pin OUT14_Pin OUT15_Pin */
  GPIO_InitStruct.Pin = OUT0_Pin|OUT1_Pin|OUT2_Pin|OUT3_Pin
                          |OUT4_Pin|OUT5_Pin|OUT6_Pin|OUT7_Pin
                          |OUT8_Pin|OUT9_Pin|OUT10_Pin|OUT11_Pin
                          |OUT12_Pin|OUT13_Pin|OUT14_Pin|OUT15_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTTON_Pin BUTTON1_Pin BUTTON2_Pin */
  GPIO_InitStruct.Pin = BUTTON_Pin|BUTTON1_Pin|BUTTON2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : OUT2_12_Pin OUT2_13_Pin OUT2_14_Pin OUT2_15_Pin
                           OUT2_3_Pin OUT2_4_Pin OUT2_5_Pin OUT2_6_Pin
                           OUT2_7_Pin OUT2_8_Pin OUT2_9_Pin */
  GPIO_InitStruct.Pin = OUT2_12_Pin|OUT2_13_Pin|OUT2_14_Pin|OUT2_15_Pin
                          |OUT2_3_Pin|OUT2_4_Pin|OUT2_5_Pin|OUT2_6_Pin
                          |OUT2_7_Pin|OUT2_8_Pin|OUT2_9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
