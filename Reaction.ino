int button = 8;
int LED = 9;
int LEDDelay;
double StartTimer;
double EndTimer;
double SingleTimer;
double TotalTimer;
double AverageTimer;
int counter;

void setup(){
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(LED, OUTPUT);
  TotalTimer = 0;
  counter = 1;
  Serial.println("The program will start shortly...");
  delay(2500);
  Serial.println("Ready");
  delay(1000);
  Serial.println("Set");
  delay(1000);
  Serial.println("Go");
  delay(500);
}

void loop(){
  LEDDelay = random(2000, 6000);
  StartTimer = 0;
  EndTimer= 0;
  SingleTimer = 0;
  delay(LEDDelay);
  StartTimer = millis();
  digitalWrite(LED, HIGH);
  while(digitalRead(button)!=HIGH){
    if(digitalRead(button)==HIGH){
      EndTimer = millis();
      digitalWrite(LED, LOW);
      SingleTimer = EndTimer - StartTimer;
      TotalTimer = TotalTimer + SingleTimer;
      AverageTimer = TotalTimer/counter;
      counter++;
      Serial.print("Your current reaction time was: \t");
      Serial.println(SingleTimer/1000);
      Serial.println("\n");
      break;
      }
  }
  if(counter %  5 == 0){
    Serial.print("\tYour average reaction time is: \t");
    Serial.println( AverageTimer/1000);
    Serial.println("\n"); 
  }
}
