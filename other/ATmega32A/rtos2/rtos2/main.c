/*
 * rtos2.c
 *
 * Created: 12/11/2020 5:43:28 PM
 * Author : abhay
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"


void vApplicationIdleHook( void );
TaskHandle_t myTask1Handle = NULL;
TaskHandle_t myTask2Handle = NULL;
TaskHandle_t myTask3Handle = NULL;
void myTask1 (void *p){
	
	while(1){
		//int count = 0;
		DDRA = 0xff;	// Output port D
		PORTA = 0x01;	// Lower Nibble high o/p
		vTaskDelay(500);
		PORTA = 0x00;	// Lower Nibble high o/p
		vTaskDelay(1000);
	}
}
void myTask2 (void *p){
	
	while(1){
		//int count = 0;
		DDRA = 0xff;	// Output port D
		PORTA = 0x02;	// Lower Nibble high o/p
		vTaskDelay(2000);
		PORTA = 0x00;	// Lower Nibble high o/p
		vTaskDelay(1000);
	}
}
void myTask3 (void *p){
	
	while(1){
		//int count = 0;
		DDRA = 0xff;	// Output port D
		PORTA = 0x04;	// Lower Nibble high o/p
		vTaskDelay(10000);
		PORTA = 0x00;	// Lower Nibble high o/p
		vTaskDelay(1000);
	}
}

int main(void)
{
	
	xTaskCreate(myTask1, "task1", configMINIMAL_STACK_SIZE, (void*) 0, (tskIDLE_PRIORITY), &myTask1Handle);
	xTaskCreate(myTask2, "task2", configMINIMAL_STACK_SIZE, (void*) 0, (tskIDLE_PRIORITY + 1), &myTask2Handle);
	xTaskCreate(myTask3, "task3", configMINIMAL_STACK_SIZE, (void*) 0, (tskIDLE_PRIORITY + 1), &myTask3Handle);
	vTaskStartScheduler();
    /* Replace with your application code */
    while (1) 
    {
    }
}

void vApplicationIdleHook( void )
{
	vCoRoutineSchedule();
}