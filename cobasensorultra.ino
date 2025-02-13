const int trig1 = 5;
const int trig2 = 3;
const int echo1 = 6;
const int echo2 = 9;
const int ledijo = 2;
const int ledmerah = 7;



void setup() {
  // put your setup code here, to run once:
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
  pinMode(ledijo, OUTPUT);
  pinMode(ledmerah, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  long duration1, distance1;
  duration1 = pulseIn(echo1, HIGH);
  distance1 = (duration1 * 0.0343)/2;
  Serial.println("distance1: ");
  Serial.println(distance1);
  if (distance1 < 10) {
    digitalWrite(ledijo, HIGH);
  } else {
    digitalWrite(ledijo, LOW);
  }
  duration1 = pulseIn(echo1, LOW);



  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  long duration2, distance2;
  duration2 = pulseIn(echo2, HIGH);
  distance2 = (duration2 * 0.0343)/2;
  Serial.println("distance2: ");
  Serial.println(distance2);
  if (distance2 < 20) {
    digitalWrite(ledmerah, HIGH);
  } else {
    digitalWrite(ledmerah, LOW);
  }
  duration2 = pulseIn(echo2, LOW);
}
