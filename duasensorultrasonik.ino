const int trigerPertama = 5;
const int trigerKedua = 3;  
const int echoPertama = 6;
const int echoKedua = 9;
const int ledmerah = 7;
const int ledijo = 2;



void setup() {
  // put your setup code here, to run once:
  pinMode(trigerPertama, OUTPUT);
  pinMode(echoPertama, INPUT);
  Serial.begin(9600);
  pinMode(ledijo, OUTPUT);
  pinMode(ledmerah, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigerPertama, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPertama, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPertama, LOW);


  int duration1, distance1;
  duration1 = pulseIn(echoPertama, HIGH);
  distance1 = (duration1 * 0.0343)/2;
  
  if (distance1 < 10) {
    digitalWrite(ledijo, HIGH);
  } else {
    digitalWrite(ledijo, LOW);
  }
  Serial.println("distance1:");
  Serial.println(distance1);
}
