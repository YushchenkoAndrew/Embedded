char a='A',b='B';
bool c[8];
byte i=0;

void ABCDEF(char f)
{
  c[i-4]=1;
  if (f >= 'D' && f <= 'G') c[i-3]=1;
}
char next(char a)
{
  byte r=a+1;
  a=r;
  return a;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  byte k=8;
   if (a >= 'A' && a<='F')
   a=next(a);

  while (k != 0)
  {
    c[i]=bool(a & k);
    k=k>>1;
    i++;
  }
 if (a >= 'A' && a<='F')
   ABCDEF(a);
  k=8;
  if (b >= 'A' && b<='F')
   b=next(b);
   
    while (k != 0)
  {
    c[i]=bool(b & k);
    k=k>>1;
    i++;
  }
  if (b >= 'A' && b<='F')
  ABCDEF(b);
  for(auto j:c)
  {
  Serial.print(j);
  digitalWrite(13,j);
  delay(3000);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
}
