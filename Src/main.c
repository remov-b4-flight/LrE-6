/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/**
 * @author jenoki
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include "midi.h"
#include "usbd_hid.h"
#include "led.h"
#include "i2c-lcd.h"
#include "bitcount.h"
#include "key_define.h"
#include "usbd_midi_if.h"
#if WROOM_ENABLE
#include "wroom.h"
#endif
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
ADC_HandleTypeDef hadc;

I2C_HandleTypeDef hi2c1;
DMA_HandleTypeDef hdma_i2c1_tx;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim14;
TIM_HandleTypeDef htim16;
DMA_HandleTypeDef hdma_tim3_ch1_trig;

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_tx;
DMA_HandleTypeDef hdma_usart1_rx;

/* USER CODE BEGIN PV */
TIM_HandleTypeDef htim3;

bool		isKeyPressed;
KEYSCAN     keystat;
uint8_t		keyline;
bool		isKeyRelaseSent;

int32_t     lcd_timer;
bool		lcd_timer_enable;
bool        lcd_off_flag;
bool		lcd_1stflag;
uint8_t		LrE6State;
uint8_t		LrE6Scene;

#ifdef MIDI
bool		isPrev_sw;	//MIDI event previous sent is switch(true) or rotator(false)
#endif
#if WROOM_ENABLE
bool		isWROOMDataExists;
#endif
bool		led_sendpulse;
bool		led_timer_update;

#ifdef MIDI
	extern	KEY_DEFINE keytable[SCENE_COUNT][KEY_DEFINE_COUNT];
	extern	char *scene_name[SCENE_COUNT];
#else //HID
	extern	KEY_DEFINE keytable[];
	KEY_MODIFIER modifiers[KEY_COUNT];
	KEYBOARD_INPUT_REPORT	In_Report;
#endif

extern	uint8_t	LED_Scene[SCENE_COUNT][LED_COUNT];
extern	USBD_HandleTypeDef hUsbDeviceFS;
extern	uint8_t	LEDColor[];
extern	uint8_t	LEDTimer[LED_COUNT];
const	uint8_t	up_arrow[LCD_CGRAM_BYTES] = {0x04,0x0E,0x15,0x04,0x04,0x04,0x04,0x00};

#ifdef MIDI
	uint8_t MIDI_CC_Value[SCENE_COUNT][ROT_COUNT];
	uint8_t prev_ch;
	uint8_t	USBMIDI_Event[4];
	extern USBD_HandleTypeDef *pInstance;
#endif
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM14_Init(void);
static void MX_ADC_Init(void);
static void MX_TIM16_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//Delay process in us unit.
void Delay_us(uint32_t microsec){

	htim14.Init.Period = microsec;
	HAL_TIM_Base_Init(&htim14);
	HAL_TIM_Base_Start(&htim14);
	htim14.Instance->SR = 0;

	while((htim14.Instance->SR & TIM_SR_UIF) == 0)	;	//wait until timer up.

	HAL_TIM_Base_Stop(&htim14);
}

inline void Start_LCDTimer(uint32_t tick){
	lcd_timer = tick;
	lcd_timer_enable = true;
}

#ifdef MIDI
/**
 * @brief alter LED contents by scene
 * @param scene	Scene No
 */
void LED_SetScene(uint8_t scene){
	memcpy(LEDColor,LED_Scene[scene],LED_COUNT);
	SendPulse();
}
#endif

#ifdef MIDI
/**
 *	@brief	Generate MIDI event and Send to host by User interaction.
 */
bool EmulateMIDI(){
	char lcd_string2[10];

    if (isKeyPressed) {
        uint8_t		bitpos = ntz32(keystat.wd);
        uint32_t	rkey = (keystat.wd & MOD_SW_BIT_MASK);
        bool 		isKeyReport = false;

        if ( bitpos < KEY_PER_SCENE ) { //Matrix switches
        	uint8_t	ch = MIDI_CCCH_SW_BASE + (LrE6Scene * KEY_PER_SCENE) + bitpos;
            uint8_t axis = ((bitpos < 10) || (KEY_COUNT <= bitpos))? LED_IDX_SELECTOR : (bitpos - 10);	//Limit LED boundary
            if (bitpos == SCENE_BIT) { //[SCENE] switch?
            	//Move to next Scene.
        		LrE6Scene++;
        		if(LrE6Scene >= SCENE_COUNT){
        			LrE6Scene = LrE6_SCENE0;
        		}
        		LED_SetScene(LrE6Scene);
        		strcpy(lcd_string2, scene_name[LrE6Scene]);
        		isKeyPressed = false;
        		isKeyReport = false;
        	}else{
        		sprintf(lcd_string2, ((ch > 99)? "C%3d=%3d":"Ch%02d=%3d"), ch, MIDI_CC_ON);
                isKeyReport = true;
        	}

            //Print Message to LCD & LED
            if (keytable[LrE6Scene][bitpos].message != NULL) {
        		LCD_Locate(0, LCD_LINE0);
            	LCD_Print(keytable[LrE6Scene][bitpos].message);
        		LCD_Locate(0, LCD_LINE1);
        		LCD_Print(lcd_string2);

            	lcd_off_flag = false;
        		lcd_timer_enable = true;
            	lcd_timer = LCD_TIMER_DEFAULT;
            	LCD_SetBackLight(LCD_BL_ON);
            }
            LED_SetPulse(axis, keytable[LrE6Scene][bitpos].color, keytable[LrE6Scene][bitpos].duration);

            if (isKeyReport == true) {
				//Set 'Control change'(Switch ON)
				USBMIDI_Event[MIDI_EV_IDX_HEADER] = MIDI_CC_HEADER;
				USBMIDI_Event[MIDI_EV_IDX_STATUS] = MIDI_CC_STATUS;
				USBMIDI_Event[MIDI_EV_IDX_CHANNEL] = ch;
				USBMIDI_Event[MIDI_EV_IDX_VALUE] = MIDI_CC_ON;
				prev_ch = USBMIDI_Event[MIDI_EV_IDX_CHANNEL];
				isPrev_sw = true;
            }
        }else if( KEY_PER_SCENE <= bitpos && bitpos < KEY_COUNT + (2 * ROT_COUNT) )   { //rotator
        	uint8_t axis = (bitpos - KEY_COUNT) / 2;
        	uint8_t val = MIDI_CC_Value[LrE6Scene][axis];
        	uint8_t ch = MIDI_CCCH_ROT_BASE + (ROT_PER_SCENE * LrE6Scene) + axis;

            USBMIDI_Event[MIDI_EV_IDX_HEADER] = MIDI_CC_HEADER;
            USBMIDI_Event[MIDI_EV_IDX_STATUS] = MIDI_CC_STATUS;
            USBMIDI_Event[MIDI_EV_IDX_CHANNEL] = ch;
            USBMIDI_Event[MIDI_EV_IDX_VALUE] = val;
            isPrev_sw = false;

            //Print Message to LCD & LED
            if (keytable[LrE6Scene][bitpos].message != NULL) {
                sprintf(lcd_string2, ((ch > 99)? "C%3d=%3d":"Ch%2d=%3d"), ch, val);
        		LCD_Locate(0, LCD_LINE0);
            	LCD_Print(keytable[LrE6Scene][bitpos].message);
        		LCD_Locate(0, LCD_LINE1);
            	LCD_Print(lcd_string2);

            	lcd_off_flag = false;
        		lcd_timer_enable = true;
            	lcd_timer = LCD_TIMER_DEFAULT;
            	LCD_SetBackLight(LCD_BL_ON);
            }

            LED_SetPulse(axis,keytable[LrE6Scene][bitpos].color, keytable[LrE6Scene][bitpos].duration);
            isKeyReport = true;

        }else if(isPrev_sw == true && rkey == 0) {// Switch is released
			//Set 'Control Change'(Switch OFF)
            USBMIDI_Event[MIDI_EV_IDX_HEADER] = MIDI_CC_HEADER;
            USBMIDI_Event[MIDI_EV_IDX_STATUS] = MIDI_CC_STATUS;
            USBMIDI_Event[MIDI_EV_IDX_CHANNEL] = prev_ch;
            USBMIDI_Event[MIDI_EV_IDX_VALUE] = MIDI_CC_OFF;
			isKeyReport = true;
			isPrev_sw = false;
        }

        if(isKeyReport == true){
			//Send MIDI event via USB
		    USBD_LL_Transmit (pInstance, MIDI_IN_EP, USBMIDI_Event, MIDI_EVENT_LENGTH);
			isKeyReport = false;
        }

        /* Clear the switch pressed flag */
        isKeyPressed = false;
        return true;
    } else
        return false;
}
#else //HID
/**
 *	@brief	Generate HID packet and Send to host by User interaction.
 */
bool EmulateKeyboard(void) {
    uint32_t rkey;
    uint8_t bitpos;
    bool isKeyReport;

    if (isKeyPressed) {
        bitpos = ntz32(keystat.wd);
        rkey = (keystat.wd & MOD_SW_BIT_MASK);
        if ( bitpos < KEY_COUNT + (2 * ROT_COUNT) ){
#if 0
        	if(modifiers[bitpos].element[0] != HID_NONM) SendModifiers(bitpos);
#endif

        	In_Report.modifier = keytable[bitpos].modifier;
            In_Report.keys[HID_RPT_KEY_IDX] = keytable[bitpos].keycode;
            if (keytable[bitpos].message != NULL) {
        		LCD_Locate(0,0);
            	lcd_off_flag = false;
        		lcd_timer_enable = true;
            	lcd_timer = LCD_TIMER_DEFAULT;
            	LCD_SetBackLight(LCD_BL_ON);
            	LCD_Print(keytable[bitpos].message);
            }
            LED_SetPulse(LED_IDX_SELECTOR,LED_COLOR_YELLOW,25);

            isKeyReport = true;
		}else if (rkey == 0) {// Keys are released
			In_Report.modifier = In_Report.keys[HID_RPT_KEY_IDX] = HID_NONE;
			isKeyReport = true;
        }else
        	isKeyReport = false;

        if (isKeyReport) {
        	USBD_HID_HandleTypeDef *hhid = hUsbDeviceFS.pClassData;
        	while ( hhid->state != HID_IDLE ){
        		Delay_us(100);
        	}
			USBD_HID_SendReport(&hUsbDeviceFS,(uint8_t *)&In_Report,sizeof(KEYBOARD_INPUT_REPORT) );
			isKeyReport = false;
        }

        /* Clear the switch pressed flag */
        isKeyPressed = false;
        return true;
    } else
        return false;
}
#endif
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
  keyline = L0;
  lcd_off_flag = false;
  lcd_timer_enable = false;
  lcd_timer = LCD_TIMER_DEFAULT;
  lcd_1stflag = true;

  LrE6State = LRE6_RESET;
  LrE6Scene	= LrE6_SCENE0;

#ifdef MIDI
  isPrev_sw = false;
#endif

  isKeyRelaseSent = true;
  led_sendpulse = false;
#if WROOM_ENABLE
  isWROOMDataExists = false;
#endif
#if 0
  ExpandModifiers();
#endif
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_TIM3_Init();
  MX_TIM1_Init();
  MX_TIM14_Init();
  MX_ADC_Init();
  MX_TIM16_Init();
  MX_USART1_UART_Init();
#ifdef MIDI
  MX_USB_MIDI_INIT();
#else //HID
  MX_USB_DEVICE_Init();
#endif
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(L0_GPIO_Port,L0_Pin,GPIO_PIN_SET);	//Initialize Switch matrix.
  HAL_TIM_Base_Start_IT(&htim1);

#if WROOM_ENABLE
  //WROOM Hardware Reset
  HAL_GPIO_WritePin(WL_EN_GPIO_Port,WL_EN_Pin,GPIO_PIN_SET);	//Enable Wifi module
  WROOM_Reset(true);
  HAL_Delay(1);
  WROOM_Reset(false);
#endif

  LED_Initialize();	//Set all LEDs 'OFF'

  //Initialize LCD
  HAL_Delay(LCD_PWRUP_WAIT_MS);		//Wait for LCD module power up.
  LCD_Initialize();
  LCD_SetCGRAM(5,up_arrow);			//Set user defined 'up aroow' character.
  LCD_SetDDADR(0);

#if WROOM_ENABLE
  //WROOM boot-up sequence
  WROOM_Initialize();
  WROOM_SetState(WROOM_INIT);
#endif

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  const uint16_t ts_cal110 = *TEMP110_CAL_ADDR;
  const uint16_t ts_cal30 = *TEMP30_CAL_ADDR;
  const float k = (110.0 - 30.0) / (ts_cal110 - ts_cal30);

  char lcdmsg[12];

  //lcd_timer = LCD_TIMER_DEFAULT;
  Start_LCDTimer(LCD_TIMER_DEFAULT);
  lcd_off_flag = false;
  //lcd_timer_enable = true;
  LrE6State = LRE6_USB_NOLINK;
#ifdef MIDI
  LED_SetScene(LrE6Scene);
#endif

  while (1) {
	if (LrE6State == LRE6_USB_LINKUP) {
		//USB device configured by host
		LED_Set_Quick(LED_IDX_SELECTOR,LED_COLOR_RED);
		LCD_SetBackLight(LCD_BL_ON);
		LCD_Print(LrE6_PRODUCT);
		sprintf(lcdmsg,"%2x.%02x",USBD_DEVICE_VER_MAJ,USBD_DEVICE_VER_MIN);
		LCD_Locate(3, LCD_LINE1);
		LCD_Print(lcdmsg);
		LrE6State = LRE6_USB_LINKED;

	} else if (LrE6State == LRE6_USB_LINKED) {
#ifdef MIDI //HID
		//Operate as MIDI Instruments.
		EmulateMIDI();
#else //MIDI
		//Operates as USB Keyboards.
		EmulateKeyboard();
#endif

	} else if(LrE6State == LRE6_USB_LINK_LOST) {
		LED_TestPattern();
		lcd_1stflag = false;
		lcd_timer_enable = true;
		LrE6State = LRE6_USB_NOLINK;

	} else if(LrE6State == LRE6_USB_NOLINK) {
		//USB Not initially configured.
		if (lcd_off_flag) {
			if (lcd_1stflag) {
				LrE6State = LRE6_USB_LINK_LOST;
			} else {
				LCD_SetBackLight(LCD_BL_ON);

				HAL_ADC_Start(&hadc);
				//get value from ADC and display it...
				while (HAL_ADC_PollForConversion(&hadc,100) != HAL_OK)	;

				uint32_t inner_sensor_val = HAL_ADC_GetValue(&hadc);
				int16_t m = inner_sensor_val - ts_cal30;
				float t = (k * (float)m) + 30.0;

				int tempf = (t * 100);
				int8_t temp_i = tempf / 100;
				int8_t temp_s = tempf % 100;

				sprintf(lcdmsg,"%02d.%02dC\xdf",temp_i,temp_s);
				//sprintf(lcdmsg,"%04X",inner_sensor_val);

				LCD_Locate(0, LCD_LINE0);
				LCD_Print(lcdmsg);

				//Restart LCD timer.
				lcd_off_flag = false;
				lcd_timer = LCD_TIMER_UPDATE;
				lcd_timer_enable = true;

				//Rotate LED colors
				uint8_t	tempcolor = LEDColor[5];
				LEDColor[5] = LEDColor[4];
				LEDColor[4] = LEDColor[3];
				LEDColor[3] = LEDColor[2];
				LEDColor[2] = LEDColor[1];
				LEDColor[1] = LEDColor[0];
				LEDColor[0] = tempcolor;

				led_sendpulse = true;
			}
		}// lcdflag
	}// LrE6State

	if(lcd_off_flag){
		LED_Set(LED_IDX_SELECTOR,LED_COLOR_OFF);

		lcd_off_flag = false;
		LCD_SetBackLight(LCD_BL_OFF);
		LCD_Clear();
	}

	//LED Timer
	if (led_timer_update){ //4x4ms = 16ms interval
		for (uint8_t i = LED_IDX_SELECTOR; i < LED_COUNT ; i++){
			if (LEDTimer[i] != LED_TIMER_CONSTANT) {
				if (--LEDTimer[i] == 0) {
					LED_SetPulse(i,LED_Scene[LrE6Scene][i],LED_TIMER_CONSTANT);
				}
		 	}
		}
		led_timer_update = false;
	}

	//Flashing LEDs
	if (led_sendpulse) {
		SendPulse();
		led_sendpulse = false;
	}
#if WROOM_ENABLE
	//Process WROOM receiving data.
	if (isWROOMDataExists){
		WROOM_Dispatch();
		isWROOMDataExists = false;
	}
#endif
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14
                              |RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB|RCC_PERIPHCLK_USART1
                              |RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;

  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC_Init(void)
{

  /* USER CODE BEGIN ADC_Init 0 */

  /* USER CODE END ADC_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC_Init 1 */

  /* USER CODE END ADC_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
  */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = DISABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel to be converted. 
  */
  sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC_Init 2 */

  /* USER CODE END ADC_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x0000020B;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter 
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter 
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = TIM_PRESC_1uS;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = TIM_PERIOD_4mS;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

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

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = PWM_PERIOD;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
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
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_LOW;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief TIM14 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM14_Init(void)
{

  /* USER CODE BEGIN TIM14_Init 0 */

  /* USER CODE END TIM14_Init 0 */

  /* USER CODE BEGIN TIM14_Init 1 */

  /* USER CODE END TIM14_Init 1 */
  htim14.Instance = TIM14;
  htim14.Init.Prescaler = TIM_PRESC_1uS;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = TIM_PERIOD_125uS;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM14_Init 2 */

  /* USER CODE END TIM14_Init 2 */

}

/**
  * @brief TIM16 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM16_Init(void)
{

  /* USER CODE BEGIN TIM16_Init 0 */

  /* USER CODE END TIM16_Init 0 */

  /* USER CODE BEGIN TIM16_Init 1 */

  /* USER CODE END TIM16_Init 1 */
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = TIM_PRESC_1uS;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = TIM_PERIOD_10mS;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM16_Init 2 */

  /* USER CODE END TIM16_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_DMADISABLEONERROR_INIT;
  huart1.AdvancedInit.DMADisableonRxError = UART_ADVFEATURE_DMA_DISABLEONRXERROR;
  /* USER CODE BEGIN USART1_Init 3 */
#if WROOM_ENABLE
  MODIFY_REG(huart1.Instance->CR2,0,(LF << UART_CR2_ADDRESS_LSB_POS));
  MODIFY_REG(huart1.Instance->CR1,0,(USART_CR1_CMIE));
#endif
  /* USER CODE END USART1_Init 3 */
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel2_3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel2_3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);
  /* DMA1_Channel4_5_6_7_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel4_5_6_7_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel4_5_6_7_IRQn);

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, L3_Pin|L0_Pin|L1_Pin|L2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, WL_RST_Pin|BL_ON_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENC_4A_Pin ENC_4B_Pin */
  GPIO_InitStruct.Pin = ENC_4A_Pin|ENC_4B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : ENC_5A_Pin ENC_5B_Pin */
  GPIO_InitStruct.Pin = ENC_5A_Pin|ENC_5B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : M0_Pin M1_Pin M2_Pin M3_Pin */
  GPIO_InitStruct.Pin = M0_Pin|M1_Pin|M2_Pin|M3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : ENC_1A_Pin ENC_1B_Pin */
  GPIO_InitStruct.Pin = ENC_1A_Pin|ENC_1B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : L3_Pin L0_Pin L1_Pin L2_Pin */
  GPIO_InitStruct.Pin = L3_Pin|L0_Pin|L1_Pin|L2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : ENC_3A_Pin ENC_3B_Pin ENC_6A_Pin ENC_6B_Pin 
                           ENC_2A_Pin ENC_2B_Pin */
  GPIO_InitStruct.Pin = ENC_3A_Pin|ENC_3B_Pin|ENC_6A_Pin|ENC_6B_Pin 
                          |ENC_2A_Pin|ENC_2B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : WL_RST_Pin BL_ON_Pin */
  GPIO_InitStruct.Pin = WL_RST_Pin|BL_ON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);

  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

}

/* USER CODE BEGIN 4 */
#if 0
void ExpandModifiers() {
	uint8_t mod_index;
	memset(modifiers, 0, sizeof(modifiers));
	for (mod_index = 0; mod_index < KEY_COUNT; mod_index++) {
		uint8_t modifier = keytable[mod_index].modifier;
		uint8_t bitcount = bitcount8(modifier);
		if (modifier != HID_NONM && bitcount > 1) {
			uint8_t dst_index = 0;
			uint8_t pattern = 0;
			if (modifier & HID_GUIM) {
				pattern += HID_GUIM;
				modifiers[mod_index].element[dst_index] = pattern;
				dst_index += 1;
			}
			if (modifier & HID_ALTM) {
				pattern += HID_ALTM;
				modifiers[mod_index].element[dst_index] = pattern;
				dst_index += 1;
			}
			if (modifier & HID_SFTM) {
				pattern += HID_SFTM;
				modifiers[mod_index].element[dst_index] = pattern;
				dst_index += 1;
			}
			if (modifier & HID_CTLM) {
				pattern += HID_CTLM;
				modifiers[mod_index].element[dst_index] = pattern;
			}
		}
	}
}
void SendModifierElement(uint8_t mod) {
	In_Report.modifier = mod;
	In_Report.keys[0] =
	In_Report.keys[1] =
	In_Report.keys[2] =
	In_Report.keys[3] = HID_NONE;
    USBD_HID_SendReport(&hUsbDeviceFS,(uint8_t *)&In_Report,sizeof(KEYBOARD_INPUT_REPORT) );
}

void SendModifiers(uint8_t bitpos) {
	uint8_t i;
	for (i = 0; i < 4; i++) {
		uint8_t mod = modifiers[bitpos].element[i];
		if (mod == HID_NONM) break;
		SendModifierElement(mod);
	}
}
#endif

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
