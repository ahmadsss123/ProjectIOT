int led = 9;
int redup = 1;
int nyala = 5; 

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led, nyala);
  if (redup == 1){
    nyala += 5;
  }
  delay(100);
  Serial.print(nyala);
}
