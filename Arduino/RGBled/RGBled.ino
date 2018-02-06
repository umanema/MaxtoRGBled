#define R 9
#define G 10
#define B 11

#define FADESPEED 5

const char BORDER_CHAR = '\0';
byte serialReadBuffer[3];
int r,g,b = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  while (Serial.available())
  {
    Serial.readBytesUntil(BORDER_CHAR, serialReadBuffer, 3);
    r = serialReadBuffer[0]-1;
    g = serialReadBuffer[1]-1;
    b = serialReadBuffer[2]-1;
  }
  analogWrite(R,r);
  analogWrite(G,g);
  analogWrite(B,b);

}
