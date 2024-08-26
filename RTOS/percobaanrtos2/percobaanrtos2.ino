#include <Arduino_FreeRTOS.h>
 // define tasks
 void TaskBlink( void *pvParameters );
 void TaskAnalogRead( void *pvParameters );
 void TaskDigitalRead( void *pvParameters );

 void setup() {

 // initialize serial communication at 9600 bits per second:
 Serial.begin(9600);

 while (!Serial) {
 ; // wait for serial port to connect.
 }
 // Now set up tasks to run independently.
 xTaskCreate(
 TaskBlink
 , "Blink" // A name just for humans
 , 128 // stack size
 , NULL
 , 2 // Priority, with 3 being the highest, 0 being the lowest.
 , NULL );

 xTaskCreate(
 TaskAnalogRead
 , "AnalogRead"
 , 128
 , NULL
 , 1 // Priority
 , NULL );

 xTaskCreate(
 TaskDigitalRead
 , "DigitalRead"
 , 128 // Stack size
 , NULL
 , 1 // Priority
 , NULL );

 // Now the task scheduler is automatically started.
 }

 void loop()
 {
 // Empty. Things are done in Tasks.
 }

 /*--------------------------------------------------*/
 /*---------------------- Tasks ---------------------*/
 /*--------------------------------------------------*/

 void TaskBlink(void *pvParameters) // This is a task.
 {
 (void) pvParameters;

 /*
 Blink Turns on an LED on for one second, then off for one
second, repeatedly.
 */

 // initialize digital pin 8 as an output.
 pinMode(8, OUTPUT);

 for (;;) // A Task shall never return or exit.
 {
 digitalWrite(8, HIGH); // turn the LED on
 vTaskDelay( 1000 / portTICK_PERIOD_MS ); // one second
 digitalWrite(8, LOW); // turn the LED off
 vTaskDelay( 1000 / portTICK_PERIOD_MS ); // one second
 }
 }

 void TaskAnalogRead(void *pvParameters) // This is a task.
 {
 (void) pvParameters;

 /*
 AnalogReadSerial
 Reads an analog input on pin A0, prints the result to the serial
monitor.
 Graphical representation is available using serial plotter
(Tools > Serial Plotter menu)
 */
 for (;;)
 {
 // read the input on analog pin 0:
 int sensorValue = analogRead(A0);
 // print out the value you read:
 Serial.println(sensorValue);
 // one tick delay (15ms) in between reads for stability
 vTaskDelay(1);
 }
 }

 void TaskDigitalRead(void *pvParameters) // This is a task.
 {
 (void) pvParameters;
 /*
 DigitalRead
 Turns on and off a light emitting diode(LED) connected to
 digital pin 13 (onboard/built in), when pressing a pushbutton
 attached to pin 2.*/
 pinMode(2, INPUT);
 pinMode(13, OUTPUT);

 for (;;)
 {
 if (digitalRead(2) == HIGH) {
 // turn LED on:
 digitalWrite(13, HIGH);
 } else {
 // turn LED off:
 digitalWrite(13, LOW);
 }
 }
}