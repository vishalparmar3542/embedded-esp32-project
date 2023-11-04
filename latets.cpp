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
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distanceCm2 = duration2 * SOUND_VELOCITY/2;

digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
duration3 = pulseIn(echoPin3, HIGH);
distanceCm3 = duration3 * SOUND_VELOCITY/2;

digitalWrite(trigPin4, LOW);
delayMicroseconds(2);
digitalWrite(trigPin4, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin4, LOW);
duration4 = pulseIn(echoPin4, HIGH);
distanceCm4 = duration4 * SOUND_VELOCITY/2;


digitalWrite(trigPin5, LOW);
delayMicroseconds(2);
digitalWrite(trigPin5, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin5, LOW);
duration5 = pulseIn(echoPin5, HIGH);
distanceCm5 = duration5 * SOUND_VELOCITY/2;

Serial.print("device1 distance :");
Serial.println(distanceCm1);
Serial.print("device2 distance :");
Serial.println(distanceCm2);
Serial.print("device3 distance :");
Serial.println(distanceCm3);
Serial.print("device4 distance :");
Serial.println(distanceCm4);
Serial.print("device5 distance :");
Serial.println(distanceCm5);

    //for checking distance 
bool front=false,left=false,right=false,back=false;

String down="plane";    //  value can be : upstair,downstair,pit,wall,plane

// checking surounding area
    if(distanceCm2<=150 )
    {
       Serial.println("\n Some thing is in front");
       front=true;
    }else
    {
      front=false;
      
    }
    if(distanceCm3<=150 )
    {
       Serial.println("\n Some thing in in left! ");
       left=true;
    }else{
      left=false;
    }
    if(distanceCm4<=150 )
    {
       Serial.println("\n Some thing is in right! ");
       right=true;
    }else{
      right=false;
    }
    if(distanceCm5<=150 )
    {
       Serial.println("\n Some thing is in the back ");
       back=true;
    }else{
      back=false;
    }
    
//Getting vertical value
    if(distanceCm1<=(height-5) && distanceCm1>=(height-30))
    {
      Serial.println("\n up Stairs ahead ");
      down="upstair";
    }else if(distanceCm1>=(height+5) && distanceCm1<=(height+25) )
    {
      Serial.println("\n down Stairs ahead ");
      down="downstair";
    }else if(distanceCm1>=(height+25))
    {
//       tone(buzzer, 1000); // Send 1KHz sound signal...
//               delay(1000);        // ...for 1 sec
//            noTone(buzzer);
      Serial.println("\n khdaa ahead");
      down="pit";
    }else if( distanceCm1<=(height-30)){
         down="wall";
    }else{
      down="plane";
    }

///we have to send front,left,right,back,and down 

   Serial.println("down"+down+" front"+front+" Left"+left+" right"+right+" back"+back); 
Serial.println("_________");
}
