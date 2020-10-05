int phase1 = 2;
int phase2 = 3;
int phase3 = 4;
int led = 13;

unsigned long stepLength = 30000;
int minStepLength = 1000;
int steps =5 ;

void setup() {
  pinMode(led, OUTPUT);  
  pinMode(phase1, OUTPUT);
  pinMode(phase2, OUTPUT);
  pinMode(phase3, OUTPUT);
  digitalWrite(led, LOW); 
  Serial.begin(9600);
}

void loop() {
  switchStep(1);
  switchStep(2); 
  switchStep(3);
  
  if(stepLength > minStepLength)
  {
    stepLength = stepLength - steps;
  } else {
    // set the minimum pulse length
    stepLength=minStepLength;
  }
  Serial.println(stepLength);
  if (stepLength < 39950) {
    digitalWrite(led, HIGH);   // second gear
    steps = 500;
    Serial.println("*");
  }
   
  if (stepLength < 20000) {
    digitalWrite(led, LOW);      // third gear
    steps = 50;
  }

  if (stepLength < 2000) {
    digitalWrite(led, HIGH);      // fourth gear
    steps = 1;
  }
}


void switchStep(int stage)
{
  switch(stage)
  {
  case 1:
    digitalWrite(phase1, HIGH);
    digitalWrite(phase2, LOW);
    digitalWrite(phase3, LOW);
    myDelay(stepLength);
    break;
    
  case 2:
    digitalWrite(phase1, LOW);
    digitalWrite(phase2, HIGH);
    digitalWrite(phase3, LOW);
    myDelay(stepLength);
    break;
    
  default:
    digitalWrite(phase1, LOW);
    digitalWrite(phase2, LOW);
    digitalWrite(phase3, HIGH);
    myDelay(stepLength);
    break;
  }  


}

void myDelay(unsigned long p) {
if (p > 16380) {
  delay (p/1000);
  } else {
  delayMicroseconds(p);
  }
} 
