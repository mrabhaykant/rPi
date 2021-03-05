The stack size should be above 256. 512 is a good stack sizeif you have printf function for debugging.
```
void taskDemo2(void * arg){                       // create a task definiton
printf("This is Task2\r\n");                      // prints the information just after task entry
while(1){                                         // creates a infinite loop
	for(int tD2_i=0;tD2_i<10;tD2_i++){              
		printf("This is Task2\t\t%d\r\n",tD2_i);      // prints the task information
		vTaskDelay(100);                              // this function creates a delay 
	}
}
vTaskDelete(NULL);                                // if everything above works then the code never reaches this point
}

void taskDemo3(void * arg){
printf("This is Task3\r\n");
while(1){
	for(int tD2_i=0;tD2_i<10;tD2_i++){
		printf("This is Task3\t%d\r\n",tD2_i);
		vTaskDelay(200);
	}
}
vTaskDelete(NULL);
}

void app_main(){
.
. [other task's]
.
xTaskCreate(taskDemo2,"task2",512+512,NULL,1,NULL);       // This is a task creation function. The priority of user defined task should not be greater than 14.
                                                          // priority '1' is not used by any other system task.
xTaskCreate(taskDemo3,"task3",512+512,NULL,1,NULL);
}
```
 
