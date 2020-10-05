int count = 0;
bool q[4] = {0, 0, 0, 0};

byte sec[3] = {1, 3, 5};  //seconds(on/off) for 2, 3, 4 led
byte vis;

void setup() {
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Enter number --> (bin), which led on");
  while (!Serial.available());
  vis = Serial.read();
  Serial.end();
}

void loop() {
    digitalWrite(4, (q[0] = !q[0]));
  
  if (bool(vis & 1) && count % (sec[0] * 2) == 0)
    digitalWrite(5, (q[1] = !q[1]));
    
  if (bool(vis & 2) && count % (sec[1] * 2) == 0)
    digitalWrite(6, (q[2] = !q[2]));
    
  if (bool(vis & 4) && count % (sec[2] * 2) == 0)
    digitalWrite(7, (q[3] = !q[3]));
    
  if (bool(vis & 8) && ((q[3]) || (count % (sec[2] * 2) == 0)))
    digitalWrite(8, (q[3] = !q[3]));
    
  count += 1;
  delay(500);

}