int led = 13;
int sensorApi = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(sensorApi, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  int data = digitalRead(sensorApi);
  delay(1000);
  Serial.print(data);
  digitalWrite(led, LOW);
  delay(1000);
}
