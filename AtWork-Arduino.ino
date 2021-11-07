long duration;
int distance;
int distance1;
int distance2;
int distance3;
int distance4;
int distance5;

const int trig1 = 31;
const int echo1 = 30;
const int trig2 = 35;
const int echo2 = 34;
const int trig3 = 39;
const int echo3 = 38;
const int trig4 = 43;
const int echo4 = 42;
const int trig5 = 47;
 const int echo5 = 46;

void setup()
{
    pinMode(trig1, OUTPUT);
    pinMode(echo1, INPUT); 
    pinMode(trig2, OUTPUT);
    pinMode(echo2, INPUT); 
    pinMode(trig3, OUTPUT);
    pinMode(echo3, INPUT); 
    pinMode(trig4, OUTPUT);
    pinMode(echo4, INPUT); 
    pinMode(trig5, OUTPUT);
    pinMode(echo5, INPUT); 
    Serial.begin(9600);    // Starts the serial communication
}
void loop()
{
    distance1 = calculateDistance(trig1,echo1);
    distance2 = calculateDistance(trig2,echo2);
    distance3 = calculateDistance(trig3,echo3);
    distance4 = calculateDistance(trig4,echo4);
    distance5 = calculateDistance(trig5,echo5);

    Serial.print("SRF #1: ");
    Serial.print(distance1);
    Serial.print("cm, SRF #2: ");
    Serial.print(distance2);
    Serial.print("cm, SRF #3: ");
    Serial.print(distance3);
    Serial.print("cm, SRF #4: ");
    Serial.print(distance4);
    Serial.print("cm, SRF #5: ");
    Serial.print(distance5);
    Serial.print("cm");
    Serial.println();
    delay(100);
}
int calculateDistance(byte trig, byte echo)
{

    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
    distance = duration * 0.034 / 2;
    return distance;
}
