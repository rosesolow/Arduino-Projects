
/* Whack a Mole

Simple game where LEDs light up at random and a player has to hit the corresponding
button to gain a point. Three LEDS and three buttons are used in this example.

*/

int score = 0; //player's score initialized to 0

//LED pins
int led1 = 13; 
int led2 = 12;
int led3 = 11;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the LED pins as outputs
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  
  //print score
  Serial.begin(9600); 
  Serial.println(score); 
}

// the loop routine runs over and over again forever:
void loop() {
  int time = random(0,2000); //random time that the LEDs will be off (the pause)
  int mole = random(11,14); //random LED that will turn on
  int sensorValue = 0; //which input pin to read
  
  int var = 0;
  //turn mole off for pause time
  while(var < time){
    digitalWrite(mole, LOW);   // turn the LED off
    delay(1); //delay for 1 millisecond
    var++;
  }
  
  var = 0;
  //turn mole on for fixed time and read if proper button is being pushed
  while(var < 500){
    digitalWrite(mole, HIGH);   // turn the LED on
    
    //depending on which LED is the mole read the corresponding button
    if (mole == 13)
    {
       sensorValue = analogRead(A2); 
    }
    if (mole == 12)
    {
       sensorValue = analogRead(A1);
    }
    if (mole == 11)
    {
       sensorValue = analogRead(A0);
    }
    
    //if the correct button is being pushed add to the score and set var 
    //so that it will exit loop on next iteration    
    if (sensorValue > 900)
    {
      score++;
      var = 500;
    }
    
    Serial.println(score); //print new score
    delay(1); //delay for one millisecond
    var++;
  }
  digitalWrite(mole, LOW); //turn mole off
}