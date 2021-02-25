/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>
#include "dispchars.h"
#include "drawingfx.h"
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
SPI_HandleTypeDef hspi2;
DMA_HandleTypeDef hdma_spi2_tx;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim7;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM7_Init(void);
static void MX_SPI2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void delay_us(uint16_t us);
//void HAL_TIM_PWM_PulseFinishedHalfCpltCallback(TIM_HandleTypeDef *htim3)
//{
// HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
//}
uint32_t counterVal;
//static const uint8_t EEPROM_WRITE = 0xaa;


int i1=0;
char clkcnt;
uint16_t spiChr[]= {0xaaaa,0xeeee,0xaaaa,0xeeee,0xaaaa,0xeeee,0xaaaa,0xeeee,0xaaaa,0xeeee,0xaaaa,0xeeee};
uint16_t blankchr = 0x0;
char dispbuf[10][10];
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim3)
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim3)
{
	counterVal++;
	if(i1>59){
		i1=0;
		clkcnt++;
	//	dispbuf[clkcnt][clkcnt] = arr2[clkcnt];
	}

	 if (clkcnt >9)
		clkcnt = 0;

//	if(counterVal == 3){
//		//HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
//		//GPIOB->BSRR = (uint32_t)GPIO_PIN_2;
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
//	}
//	else if(counterVal == 9){
//		//HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
//	}
//	else if(counterVal == 6){
//		//HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
//	}
//	else if(counterVal == 32){
//			//HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8);
//		}
//	else if (counterVal>=48&& counterVal <= 49)
//		{
//		//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8,GPIO_PIN_SET);
//		}
//	else if (counterVal>=50&& counterVal <= 69)
//	{
//		//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8,GPIO_PIN_RESET);
//
//
//		HAL_SPI_Transmit(&hspi2, &d_buf[counterVal-50][1],14,0);
//		//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8,GPIO_PIN_RESET);
//	}
//	else if (counterVal>=70&& counterVal <= 99){
//		//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8,GPIO_PIN_RESET);
//	}

	 if(counterVal >=1 && counterVal <= 768){
		//HAL_SPI_Transmit(&hspi2, &d_buf1[counterVal-220][1],14,0);
		//HAL_SPI_Transmit(&hspi2, &bitmapArray[counterVal-220][0],7,0);
		//HAL_SPI_Transmit(&hspi2, &myPhoto[counterVal-220][0],13,0);
		//if(clkcnt % 2)
	//HAL_SPI_Transmit(&hspi2, &myPhoto1[counterVal-1][0],13,0); //This one works
//		 HAL_SPI_Transmit(&hspi2, &myPhoto1[counterVal-1][0],13,0); //This one works




		 hspi2.State       = HAL_SPI_STATE_BUSY_TX;
		   hspi2.ErrorCode   = HAL_SPI_ERROR_NONE;
		   hspi2.pTxBuffPtr  = (uint8_t *)&myPhoto1[counterVal-1][0];
		   hspi2.TxXferSize  = 36;
		   hspi2.TxXferCount = 36;
		// _HAL_SPI_DISABLE(hspi2);
		     SPI_1LINE_TX(&hspi2);
		    __HAL_SPI_ENABLE(&hspi2);
		  while (hspi2.TxXferCount > 0U)
		     {
		       /* Wait until TXE flag is set to send data */
		       if (__HAL_SPI_GET_FLAG(&hspi2, SPI_FLAG_TXE))
		       {
		         if (hspi2.TxXferCount > 1U)
		         {
		           /* write on the data register in packing mode */
		           hspi2.Instance->DR = *((uint16_t *)hspi2.pTxBuffPtr);
		           hspi2.pTxBuffPtr += sizeof(uint16_t);
		           hspi2.TxXferCount -= 2U;
//		           if(hspi2.TxXferCount == 13)
//		        	   hspi2.TxXferCount = 26;

		         }
		         else
		         {
		           *((__IO uint8_t *)&hspi2.Instance->DR) = (*hspi2.pTxBuffPtr);
		           hspi2.pTxBuffPtr++;
		           hspi2.TxXferCount--;
		         }
		       }

		     }

		//  hspi2.State       = HAL_SPI_STATE_BUSY_TX;
		 // 		   hspi2.ErrorCode   = HAL_SPI_ERROR_NONE;

//
//		  		   hspi2.pTxBuffPtr  = (uint8_t *)&myPhoto1[counterVal-1][0];
//		  		   hspi2.TxXferSize  = 13;
//		  		   hspi2.TxXferCount = 13;
//		  		// _HAL_SPI_DISABLE(hspi2);
//		  		     SPI_1LINE_TX(&hspi2);
//		  		    __HAL_SPI_ENABLE(&hspi2);
//		  		  while (hspi2.TxXferCount > 0U)
//		  		     {
//		  		       /* Wait until TXE flag is set to send data */
//		  		       if (__HAL_SPI_GET_FLAG(&hspi2, SPI_FLAG_TXE))
//		  		       {
//		  		         if (hspi2.TxXferCount > 1U)
//		  		         {
//		  		           /* write on the data register in packing mode */
//		  		           hspi2.Instance->DR = *((uint16_t *)hspi2.pTxBuffPtr);
//		  		           hspi2.pTxBuffPtr += sizeof(uint16_t);
//		  		           hspi2.TxXferCount -= 2U;
//		  		         }
//		  		         else
//		  		         {
//		  		           *((__IO uint8_t *)&hspi2.Instance->DR) = (*hspi2.pTxBuffPtr);
//		  		           hspi2.pTxBuffPtr++;
//		  		           hspi2.TxXferCount--;
//		  		         }
//		  		       }
//
//		  		     }


	}// DISP END
	 else if(counterVal >=769+3 && counterVal <= 769+3){
		 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
	 }
	 else if(counterVal >=769+9 && counterVal <= 769+9){
	 		 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
	 		// for(int k=30;k>0;k--){

	 			 //HAL_Delay(100);
	 			//  }
	 	 }

	//else if(counterVal >=440 && counterVal <= 459){
				//HAL_SPI_Transmit(&hspi2, &d_buf[counterVal-400][0],sizeof(d_buf[0][0])+2,10);
				//HAL_SPI_Transmit(&hspi2, &d_buf[counterVal-440][0],15,1);
	//	HAL_SPI_Transmit(&hspi2, &d_buf[counterVal-440][1],14,0);

	//		}
//	else if(counterVal >=500 && counterVal <= 632){
//				//	HAL_SPI_Transmit(&hspi2, &d_buf[counterVal-460][0],sizeof(d_buf[0][0])+2,10);
//		//HAL_SPI_Transmit(&hspi2, &d_buf1[counterVal-460][1],14,0);
//		HAL_SPI_Transmit(&hspi2, &myPhoto[counterVal-500][0],13,0);
//				}
		//HAL_SPI_Transmit(&hspi2, &d_buf[counterVal-500][1],1,2);
		//HAL_SPI_Transmit_IT(&hspi2, &d_buf[counterVal-400][1],sizeof(d_buf[0][1]));
		//HAL_SPI_Transmit_DMA(&hspi2, &d_buf[counterVal-400], 1);//(&hspi2, d_buf, 8,0);
		//HAL_SPI_Transmit(&hspi2, d_buf[1][1], 7,0);


	else if(counterVal == 807){
			//HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
		counterVal = 0;
		i1++;
		}


// HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
// delay_us(5);
// HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
// delay_us(2);
//  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
//  delay_us(2);
//    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
// HAL_TIM_ReadCapturedValue(TIM_HandleTypeDef *htim, uint32_t Channel);
 //counterVal = HAL_TIM_ReadCapturedValue(htim3, TIM_CHANNEL_1);
// if (__HAL_TIM_GET_FLAG(htim3, TIM_FLAG_CC2) != RESET)
//  {
//    if (__HAL_TIM_GET_IT_SOURCE(htim3, TIM_IT_CC2) != RESET)
//    {
//      __HAL_TIM_CLEAR_IT(htim3, TIM_IT_CC2);
//      htim3->Channel = HAL_TIM_ACTIVE_CHANNEL_2;
//      /* Input capture event */
//      if ((htim3->Instance->CCMR1 & TIM_CCMR1_CC2S) != 0x00U)
//      {
//#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
//        htim->IC_CaptureCallback(htim);
//#else
//        HAL_TIM_IC_CaptureCallback(htim3);
//#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
//      }
//      /* Output compare event */
//      else
//      {
//#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
//        htim->OC_DelayElapsedCallback(htim);
//        htim->PWM_PulseFinishedCallback(htim);
//#else
//        HAL_TIM_OC_DelayElapsedCallback(htim3);
//        HAL_TIM_PWM_PulseFinishedCallback(htim3);
//#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
//      }
//      htim3->Channel = HAL_TIM_ACTIVE_CHANNEL_CLEARED;
//    }
//  }
}

void delay_us(uint16_t us){
	__HAL_TIM_SET_COUNTER(&htim7,0);
	//HAL_TIM_Base_Start(&htim7);
	while (/*(uint16_t)*/__HAL_TIM_GET_COUNTER(&htim7) < us);
	//HAL_TIM_Base_Stop(&htim7);
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	//HAL_TIM_
//	AFIO->MAPR = AFIO_MAPR_TIM3_REMAP; // Full TIM3 remap
//
//	TIM3->PSC = 239; // Set prescaler to 24 000 (PSC + 1)
//	TIM3->ARR = 500; // Auto reload value 500
//
//	TIM3->CCR3 = 0;   // Start PWM duty for channel 3
//	TIM3->CCR4 = 500; // Start PWM duty for channel 4
//
//	TIM3->CCMR2 = TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 |
//	              TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1; // PWM mode on channel 3 & 4
//
//	TIM3->CCER = TIM_CCER_CC4E | TIM_CCER_CC3E; // Enable compare on channel 3 & 4
//	TIM3->CR1  = TIM_CR1_CEN; // Enable timer
//
//	TIM3->DIER = TIM_DIER_UIE; // Enable update interrupt (timer level)
//	NVIC_EnableIRQ(TIM3_IRQn); // Enable interrupt from TIM3 (NVIC level)

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM3_Init();
  MX_TIM7_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  //HAL_TIM_Base_Start_IT(&htim3);
 // HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  //HAL_TIM_OC_Start_IT(&htim3, TIM_CHANNEL_2);	// this works
  HAL_TIM_OC_Start_IT(&htim3, TIM_CHANNEL_2);

//for(int dB =0;dB<20; dB++){
//	for(int db1 =0; db1 <20; db1++){
//		d_buf[db1][dB] = arr1[db1];
//	}
//}
  for(int db1 =0; db1 <20; db1++){
  	myPhoto1[db1+747][0] = arra[db1];
  	myPhoto1[db1+747][1] = arrb[db1];
  	myPhoto1[db1+747][2] = arrh[db1];
  	myPhoto1[db1+747][3] = arra[db1];
  	myPhoto1[db1+747][4] = arry[db1];
 	myPhoto1[db1+747][5] = arrspace[db1];
  	myPhoto1[db1+747][6] = arrk[db1];
  	myPhoto1[db1+747][7] = arra[db1];
  	myPhoto1[db1+747][8] = arrn[db1];
  	myPhoto1[db1+747][9] = arrt[db1];
  }
//  for(int db1 =0; db1 <20; db1++){
//	  myPhoto1[db1+747][1] = arr1[db1];
//   }
//  for(int db1 =0; db1 <20; db1++){
//	  myPhoto1[db1+747][2] = arr2[db1];
//   }
//  for(int db1 =0; db1 <20; db1++){
//  	d_buf[db1][3] = arr3[db1];
//   }
//  for(int db1 =0; db1 <20; db1++){
//   	d_buf[db1][4] = arr4[db1];
//    }
//  for(int db1 =0; db1 <20; db1++){
//     	d_buf[db1][5] = arr5[db1];
//      }
//  for(int db1 =0; db1 <20; db1++){
//     	d_buf[db1][6] = arr6[db1];
//      }
//  for(int db1 =0; db1 <20; db1++){
//     	d_buf[db1][7] = arr7[db1];
//      }
//  for(int db1 =0; db1 <20; db1++){
//       	d_buf[db1][8] = arr8[db1];
//        }
//  for(int db1 =0; db1 <20; db1++){
//       	d_buf[db1][9] = arr9[db1];
//        }
//  for(int db1 =0; db1 <20; db1++){
//       	d_buf[db1][10] = arra[db1];
//        }
//  for(int db1 =0; db1 <20; db1++){
//        	d_buf[db1][11] = arrb[db1];
//         }
//  for(int db1 =0; db1 <20; db1++){
//        	d_buf[db1][12] = arrh[db1];
//         }
//  for(int db1 =0; db1 <20; db1++){
//        	d_buf[db1][13] = arra[db1];
//         }
//  for(int db1 =0; db1 <20; db1++){
//          	d_buf[db1][14] = arry[db1];
//           }
//
//  for(int db1 =0; db1 <20; db1++){
//         	myPhoto1[db1+240][1] = arra[db1];
//          }
//  for(int db1 =0; db1 <20; db1++){
//         	myPhoto1[db1+240][2] = arrb[db1];
//          }
//  for(int db1 =0; db1 <20; db1++){
//         	myPhoto1[db1+240][3] = arrh[db1];
//          }
//  for(int db1 =0; db1 <20; db1++){
//         	myPhoto1[db1+240][4] = arra[db1];
//          }
//  for(int db1 =0; db1 <20; db1++){
//         	myPhoto1[db1+240][5] = arry[db1];
//          }
  for(int db1 =0; db1 <13; db1++){
	  for(int db2=0; db2 <133 ; db2++)
         	myPhoto1[db2+270][db1] = myPhoto[db2][db1];
          }
//  for(int db1 =0; db1 <30; db1++){
// 	  for(int db2=0; db2 <640 ; db2++)
//          	myPhoto1[db2+10][db1] = me[db2][db1];
//           }
//  for(int db1 =13; db1 <26; db1++){
// 	  for(int db2=0; db2 <133 ; db2++)
//          	myPhoto1[db2+270][db1] = myPhoto[db2][db1];
//           }
//  d_buf[0][0]=0x08;
//  d_buf[1][1]=0x08;
//  d_buf[2][2]=0x08;
//  d_buf[3][3]=0x08;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int i,j;
  int8_t temp,temp1;
  for(i = 30;i<35;i++){
 			myPhoto1[10][i] |= 0xff;	// ROW
 	  }
 	  for(i = 0;i<39;i++){
 	  			myPhoto1[i][30] |= 0x40;	// column
 	  	  }
 	  for(i = 0;i<39;i++){
 	  	  			myPhoto1[i][34] |= 0x40;	// column
 	  	  	  }
 	  for(i = 30;i<35;i++){
 	 			myPhoto1[39][i] |= 0xff;	// ROW
 	 	  }
// 	  boxy(10, 10, 5, 50);
// 	 boxy(15, 300, 5, 50);
//	  boxy(0, 200, 5, 50);
//	  boxy(1, 100, 5, 50);
  while (1)
  {
//if(clkcnt%2){
	  /*
	   * Bars Down and then clear
	   */
//	  for(i = 14; i < 30; i++){
//		  for(j = 0; j < 200;j++){
//			  boxy(i, j,5, 300);
//			 // boxy_inv(i, j,5,10);
//			  //HAL_Delay(30);
//		  }
//
//	  }
//	  for(i = 14; i < 30; i++){
//	  		  for(j = 0; j <200;j++){
//	  			  boxy_inv(i, j,5,300);
//	  			  //HAL_Delay(60);
//	  		  }
//
//	  	  }
	  for(i = 0; i < (30/2) ; i++){
	  	 		//	myPhoto1[x+y][i] |= 0xff;	// ROW

	  	  for(j = 8;j<(8+280);j++){
	  			myPhoto1[j][i] = (uint8_t)floor(j*sin(j)*0.25);//0x40;	// column left
	  		  }
	  }

//	  for(int k=30;k>0;k--){
//	  for(int i=641;i<741;i++){
//
//	    	for(int j=0;j<7;j++){
//	    		//temp = k+j;
//	    		//temp1 = j;
//
//	    	myPhoto1[i][k+j-7] = bitmapArray[i-641][j];//>>(k-j-1-1);
//	    	}
//	    }
//	 HAL_Delay(100);
//	  }

//HAL_Delay(1000);
//for(temp = 0; temp <30;temp++){
//	for(i=641;i<741;i++)
//	myPhoto1[i][temp]=bitmapArray[i-641][temp]<<temp;
//}

    /* USER CODE END WHILE */

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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_1LINE;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi2.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */
 // sConfigOC.Pulse = 166;
  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 1653;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_OC_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 167;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_LOW;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_INACTIVE;
  sConfigOC.Pulse = 55;//40+10+5+25;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  if (HAL_TIM_OC_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

//  sConfigOC.OCMode = TIM_OCMODE_PWM1;
//    sConfigOC.Pulse = 1407;
//    sConfigOC.OCPolarity = TIM_OCPOLARITY_LOW;
//    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
//    if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
//    {
//      Error_Handler();
//    }
  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief TIM7 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM7_Init(void)
{

  /* USER CODE BEGIN TIM7_Init 0 */

  /* USER CODE END TIM7_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM7_Init 1 */

  /* USER CODE END TIM7_Init 1 */
  htim7.Instance = TIM7;
  htim7.Init.Prescaler = 80-1;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = 0xffff-1;
  htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM7_Init 2 */

  /* USER CODE END TIM7_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);

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
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, AUDIO_RST_Pin|LD_G_Pin|XL_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD_R_Pin|M3V3_REG_ON_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OTG_FS_PowerSwitchOn_GPIO_Port, OTG_FS_PowerSwitchOn_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OTG_FS_VBUS_GPIO_Port, OTG_FS_VBUS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GYRO_CS_GPIO_Port, GYRO_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SAI1_MCK_Pin SAI1_FS_Pin SAI1_SCK_Pin SAI1_SD_Pin
                           AUDIO_DIN_Pin */
  GPIO_InitStruct.Pin = SAI1_MCK_Pin|SAI1_FS_Pin|SAI1_SCK_Pin|SAI1_SD_Pin
                          |AUDIO_DIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF13_SAI1;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : AUDIO_RST_Pin */
  GPIO_InitStruct.Pin = AUDIO_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(AUDIO_RST_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : MFX_IRQ_OUT_Pin OTG_FS_OverCurrent_Pin */
  GPIO_InitStruct.Pin = MFX_IRQ_OUT_Pin|OTG_FS_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 MAG_INT_Pin MAG_DRDY_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_0|MAG_INT_Pin|MAG_DRDY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : VLCD_Pin SEG22_Pin SEG1_Pin SEG9_Pin
                           SEG13_Pin */
  GPIO_InitStruct.Pin = VLCD_Pin|SEG22_Pin|SEG1_Pin|SEG9_Pin
                          |SEG13_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF11_LCD;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : JOY_CENTER_Pin JOY_LEFT_Pin JOY_RIGHT_Pin JOY_UP_Pin
                           JOY_DOWN_Pin */
  GPIO_InitStruct.Pin = JOY_CENTER_Pin|JOY_LEFT_Pin|JOY_RIGHT_Pin|JOY_UP_Pin
                          |JOY_DOWN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : MFX_WAKEUP_Pin */
  GPIO_InitStruct.Pin = MFX_WAKEUP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MFX_WAKEUP_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG23_Pin SEG0_Pin COM0_Pin COM1_Pin
                           COM2_Pin SEG10_Pin */
  GPIO_InitStruct.Pin = SEG23_Pin|SEG0_Pin|COM0_Pin|COM1_Pin
                          |COM2_Pin|SEG10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF11_LCD;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG21_Pin SEG2_Pin SEG20_Pin SEG3_Pin
                           SEG19_Pin SEG11_Pin COM3_Pin */
  GPIO_InitStruct.Pin = SEG21_Pin|SEG2_Pin|SEG20_Pin|SEG3_Pin
                          |SEG19_Pin|SEG11_Pin|COM3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF11_LCD;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : LD_R_Pin */
  GPIO_InitStruct.Pin = LD_R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(LD_R_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD_G_Pin */
  GPIO_InitStruct.Pin = LD_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(LD_G_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : AUDIO_CLK_Pin */
  GPIO_InitStruct.Pin = AUDIO_CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF13_SAI1;
  HAL_GPIO_Init(AUDIO_CLK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : QSPI_CLK_Pin QSPI_CS_Pin QSPI_D0_Pin QSPI_D1_Pin
                           QSPI_D2_Pin QSPI_D3_Pin */
  GPIO_InitStruct.Pin = QSPI_CLK_Pin|QSPI_CS_Pin|QSPI_D0_Pin|QSPI_D1_Pin
                          |QSPI_D2_Pin|QSPI_D3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF10_QUADSPI;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : MFX_I2C_SLC_Pin MFX_I2C_SDA_Pin */
  GPIO_InitStruct.Pin = MFX_I2C_SLC_Pin|MFX_I2C_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG18_Pin SEG5_Pin SEG17_Pin SEG6_Pin
                           SEG16_Pin SEG7_Pin SEG15_Pin SEG8_Pin */
  GPIO_InitStruct.Pin = SEG18_Pin|SEG5_Pin|SEG17_Pin|SEG6_Pin
                          |SEG16_Pin|SEG7_Pin|SEG15_Pin|SEG8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF11_LCD;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : OTG_FS_PowerSwitchOn_Pin OTG_FS_VBUS_Pin */
  GPIO_InitStruct.Pin = OTG_FS_PowerSwitchOn_Pin|OTG_FS_VBUS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : OTG_FS_DM_Pin OTG_FS_DP_Pin */
  GPIO_InitStruct.Pin = OTG_FS_DM_Pin|OTG_FS_DP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : EXT_RST_Pin GYRO_INT1_Pin */
  GPIO_InitStruct.Pin = EXT_RST_Pin|GYRO_INT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : USART_TX_Pin USART_RX_Pin */
  GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : GYRO_CS_Pin */
  GPIO_InitStruct.Pin = GYRO_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GYRO_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : M3V3_REG_ON_Pin */
  GPIO_InitStruct.Pin = M3V3_REG_ON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(M3V3_REG_ON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : I2C1_SCL_Pin I2C1_SDA_Pin */
  GPIO_InitStruct.Pin = I2C1_SCL_Pin|I2C1_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : GYRO_INT2_Pin */
  GPIO_InitStruct.Pin = GYRO_INT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GYRO_INT2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : XL_CS_Pin */
  GPIO_InitStruct.Pin = XL_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(XL_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : XL_INT_Pin */
  GPIO_InitStruct.Pin = XL_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(XL_INT_GPIO_Port, &GPIO_InitStruct);

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
