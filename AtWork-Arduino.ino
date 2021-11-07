/*    
   * Ultrasonic Sensor HC-SR05/4 and Arduino
    * by Hanie Kiani
*  https://electropeak.com/learn
    */
long duration;
    int distance;
    
    const int trig1 = 31;
    const int echo1 = 30;
    const int trig2 = 33;
    const int echo2 = 32;
    const int trig3 = 35;
    const int echo3 = 34;
    const int trig4 = 37;
    const int echo4 = 36;
    const int trig4 = 39
    const int echo4 = 38;
   
    
    void setup() {
    pinMode(trig, OUTPUT); // Sets the trigPin as an Output
    pinMode(echo, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
    }
    void loop() {
       distance = calculateDistance();
Serial.println(distance); 

    }
    int calculateDistance(byte trig, echo){ 
  
  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
