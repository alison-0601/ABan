/*  
    Arduino with PIR motion sensor
    For complete project details, visit: http://RandomNerdTutorials.com/pirsensor
    Modified by Rui Santos based on PIR sensor by Limor Fried
*/
 
int led = 13;                // the pin that the LED is atteched to
int sensor = 8;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
int sensor2 = 2;  //
int val2 = 0; //
int state2 = LOW;
int led2 = 12;

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
  pinMode(sensor2, INPUT);
  pinMode(led2, OUTPUT); 
}
////////////////////////////////////////////
void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) {
      //Serial.println("detected,motion"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        //Serial.println("stopped,motion");
        state = LOW;       // update variable state to LOW
    }
  }
  if(state==HIGH)
  {
    //Serial.println("on,motion");
  }
  //
  val2 = digitalRead(sensor2);   // read sensor value
  if (val2 == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led2, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state2 == LOW) {
      //Serial.println("detected,motion"); 
      state2 = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led2, LOW); // turn LED OFF
      delay(100);             // delay 200 milliseconds 
      
      if (state2 == HIGH){
        //Serial.println("stopped,motion");
        state2 = LOW;       // update variable state to LOW
    }
  }
  if(state2==HIGH ||state==HIGH)
  {
    Serial.println("on,motion");
  }
  
  if(state == LOW && state2 == LOW)
  {
    Serial.println("stopped,motion");
  }
  }
  
