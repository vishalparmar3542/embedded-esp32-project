
const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 11;
const int echoPin2 = 12;
const int trigPin3 = 4;
const int echoPin3 = 5;                                                                                                               x
const int trigPin4 = 6;
const int echoPin4 = 7;
const int trigPin5 = 8;
const int echoPin5 = 9;


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

bool front=false,left=false,right=false,back=false;
String down="plane"; 

float height=170;
String data="Deafult text";
const int buzzer = 10;
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

// checking surounding area
    if(distanceCm2<=150 )
    {
       Serial.println("\n Some thing is in front");
       for(int i=1;i<10;i++)
       {
       tone(buzzer, 200*i);
       delay(20);
       noTone(buzzer);
       delay(20);
       
       }
                 
            
       front=true;
    }else
    {
      front=false;
      
    }
    if(distanceCm3<=150 )
    {
       Serial.println("\n Some thing in in left! ");
       left=true;
        tone(buzzer,1000);
       delay(100);
       noTone(buzzer);
       delay(10);
       tone(buzzer,1000);
       delay(100);
       noTone(buzzer);
    }else{
      left=false;
    }
    if(distanceCm4<=150 )
    {
       Serial.println("\n Some thing is in right! ");
       right=true;
    }else{
      right=false;
        tone(buzzer,1000);
       delay(100);
       noTone(buzzer);
       delay(10);
       tone(buzzer,1000);
       delay(100);
       noTone(buzzer);
       delay(10);
       tone(buzzer,1000);
       delay(100);
       noTone(buzzer);
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
       tone(buzzer, 2000); // Send 1KHz sound signal...
               delay(2000);        // ...for 1 sec
            noTone(buzzer);
      Serial.println("\n pit ahead");
      down="pit";
    }else if( distanceCm1<=(height-30)){
         down="wall";
    }else{
      down="plane";
    }

///we have to send front,left,right,back,and down 
Serial.println("___");


   Serial.println("down:"+down+" front:"+front+" Left:"+left+" right:"+right+" back:"+back); 
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



  

}
