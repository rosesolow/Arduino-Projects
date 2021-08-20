/* Copy Cat
simple game where three LED lights light up at a random patterna and the player
must copy the pattern by pushing the corresponding buttons. Every time the 
player gets the pattern right a point is added to the score and the  next
light pattern has an added character.
*/

int score = 0; //player's score initialized to 0
int maxim = 3; //max number of lights in pattern

//LED pins
int led1 = 13; 
int led2 = 12;
int led3 = 11;

//button pins
int button1 = 2;
int button2 = 1;
int button3 = 0;

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
  String lightPattern = ""; //random light up pattern
  
  int var = 0;
  //create pattern
  while(var < maxim){
    int light = round(random(1,4)); //what light to turn on
    lightPattern = lightPattern + String(light); //remember the pattern
    if (light == 1) {
      digitalWrite(led1, HIGH);   // turn the LED1 on
      delay(1000); 
      digitalWrite(led1, LOW);   // turn the LED1 off
    }
    if (light == 2) {
      digitalWrite(led2, HIGH);   // turn the LED2 on
      delay(1000); 
      digitalWrite(led2, LOW);   // turn the LED2 off
    }
    if (light == 3) {
      digitalWrite(led3, HIGH);   // turn the LED3 on
      delay(1000); 
      digitalWrite(led3, LOW);   // turn the LED3 off
    }
    delay(1000); //delay for 1 s
    var++;
  }
  
  String buttonPattern = ""; //the button pattern
  
  Serial.print("button pattern : ");
  
  int pushes = 0;
  //check if player inputted pattern correctly
  while (pushes < maxim) {
    if (analogRead(button1) > 900) {
      buttonPattern = buttonPattern + "1";
      pushes++;
      Serial.print("1"); //print button pattern
      delay(500);
    }
    if (analogRead(button2) > 900) {
      buttonPattern = buttonPattern + "2";
      pushes++;
      Serial.print("2");//print button pattern
      delay(500);
    }
    if (analogRead(button3) > 900) {
      buttonPattern = buttonPattern + "3";
      pushes++;
      Serial.print("3");//print button pattern
      delay(500);
    }
  }
  
  if (buttonPattern == lightPattern) {
    score++;
    maxim++;
  }
  
  //print patterns and score
  Serial.println("");
  Serial.print("light pattern : ");
  Serial.println(lightPattern);
  Serial.print("score : ");
  Serial.println(score);
  
}