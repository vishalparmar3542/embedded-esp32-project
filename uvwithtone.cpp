const int trigPin1 = 13;
const int echoPin1 = 12;
const int trigPin2 = 14;
const int echoPin2 = 27;
const int trigPin3 = 15;
const int echoPin3 = 4;
const int trigPin4 = 5;
const int echoPin4 = 18;
const int trigPin5 = 19;
const int echoPin5 = 21;


//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration1;
long duration2;
long duration3;
long duration4;
long duration5;
float distanceCm1;
float distanceCm2;
float distanceCm3;
float distanceCm4;
float distanceCm5;

float height=170;

const int buzzer = 22;
void setup() {
Serial.begin(9600); // Starts the serial communication
pinMode(trigPin1, OUTPUT); // Sets the trigPin1 as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin1 as an Input
pinMode(trigPin2, OUTPUT); // Sets the trigPin1 as an Output
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT); 
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT); 
pinMode(echoPin4, INPUT);
pinMode(trigPin5, OUTPUT); 
pinMode(echoPin5, INPUT);
pinMode(echoPin5, INPUT);
 pinMode(buzzer, OUTPUT);
}
void loop() {
// Clears the trigPin1
digitalWrite(trigPin1, LOW);

delayMicroseconds(2);             
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);

duration1 = pulseIn(echoPin1, HIGH);

distanceCm1 = duration1 * SOUND_VELOCITY/2;

Serial.print("device1 distance :");
Serial.println(distanceCm1);


digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distanceCm2 = duration2 * SOUND_VELOCITY/2;
Serial.print("device2 distance :");
Serial.println(distanceCm2);

digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
duration3 = pulseIn(echoPin3, HIGH);
distanceCm3 = duration3 * SOUND_VELOCITY/2;
Serial.print("device3 distance :");
Serial.println(distanceCm3);
digitalWrite(trigPin4, LOW);
delayMicroseconds(2);
digitalWrite(trigPin4, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin4, LOW);
duration4 = pulseIn(echoPin4, HIGH);
distanceCm4 = duration4 * SOUND_VELOCITY/2;
Serial.print("device4 distance :");
Serial.println(distanceCm4);

digitalWrite(trigPin5, LOW);
delayMicroseconds(2);
digitalWrite(trigPin5, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin5, LOW);
duration5 = pulseIn(echoPin5, HIGH);
distanceCm5 = duration5 * SOUND_VELOCITY/2;
Serial.print("device5 distance :");
Serial.println(distanceCm5);

    //for checking distance 
    if(distanceCm1<=200 || distanceCm2<=200 || distanceCm3<=200 || distanceCm4<=200 )
    {
       Serial.println("\n Some one is around be careful ! ");
    }

    if(distanceCm5<=(height-5) && distanceCm5>=(height-30))
    {
      Serial.println("\n up Stairs ahead ");
    }else if(distanceCm5>=(height+5) && distanceCm5<=(height+20) )
    {
      Serial.println("\n down Stairs ahead ");
    }else if(distanceCm5>=(height+5))
    {
       tone(buzzer, 1000); // Send 1KHz sound signal...
               delay(1000);        // ...for 1 sec
            noTone(buzzer);
      Serial.println("\n khdaa ahead");
    }

delay(3000);
Serial.println("_________");
}
