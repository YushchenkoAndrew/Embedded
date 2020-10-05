void setup() {
  Serial.begin(9600);
}

int turn(String str)
{
  int num = 0;
  for(int i = 0; i < str.length() - 1; i++)
    {
      num = num * 10 + int(str[i]) - 48;
    }
  return num;
}

int check(int a, int b)
{
  if (a > b)
    {
      Serial.print("Max is a = ");
      return a;
    }
  else
  {
    Serial.print("Max is b = ");
    return b; 
  }
}

void loop() {
  String a, b;
  int a_num, b_num;
  
  Serial.println("Enter 'a' number");
  while (!Serial.available());
  a = Serial.readString();
  a_num = turn(a);
  
  Serial.println("Enter 'b' number");
  while (!Serial.available());
  b = Serial.readString();
  b_num = turn(b);
  
  Serial.println(check(a_num, b_num));
}
