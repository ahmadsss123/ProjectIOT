const int kiri1 = 11;
const int kiri2 = 10;
const int kanan1 = 6;
const int kanan2 = 5;
const int trig = 9;
const int echo = 3;




void setup() {
  // put your setup code here, to run once:
  pinMode(kiri1, OUTPUT);
  pinMode(kiri2, OUTPUT);
  pinMode(kanan1, OUTPUT);
  pinMode(kanan2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(kiri1, 0);
  analogWrite(kiri2, 120);       
  analogWrite(kanan1, 120);
  analogWrite(kanan2, 0);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration1, distance1;
  duration1 = pulseIn(echo, HIGH);
  distance1 = (duration1 * 0.0343)/2;
  Serial.println(distance1);
  if (distance1 < 30) {
    analogWrite(kiri1, 140);
    analogWrite(kiri2, 0); 
    delay(300);
    analogWrite(kiri1, 0);
    analogWrite(kiri2, 120); 
  }
  delay(100);
}
