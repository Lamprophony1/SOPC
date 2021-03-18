// Include libs
#include <Arduino_FreeRTOS.h>
#define Pulsador 7
#define Led 13
int interrup=0;
int estado = HIGH;
// Initialize tasks
void Task_Print1(void *param);
void Task_Print2(void *param);

// Initialize tasks handlers
TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;

void setup() {
 
  Serial.begin(9600);
  pinMode(Pulsador, INPUT);
  pinMode(Led, OUTPUT);
  
  
  xTaskCreate(Task_Print1, "Tasks1", 100, NULL, 1, &Task_Handle1);
  xTaskCreate(Task_Print2, "Tasks2", 100, NULL, 1, &Task_Handle2);

}

void loop() {}

void Task_Print1(void *param){
  (void) param;

  // Infinite loop
  while(1){
    if(digitalRead(Pulsador)== HIGH && interrup == 0){
    if(estado==LOW){
    estado = HIGH;
    }
    else{
      estado = LOW;
    }
    interrup=1;
    }
    if(digitalRead(Pulsador)== LOW){
      interrup=0;
    }
    digitalWrite(Led, estado);
    /vTaskDelay(1000/portTICK_PERIOD_MS);/
  }
  }


void Task_Print2(void *param){
  (void) param;

  // Infinite loop
  while(1){
    Serial.println("Task2");
    vTaskDelay(1000/portTICK_PERIOD_MS); // The Arduino will print to serial monitor each 1sec
  }
}
