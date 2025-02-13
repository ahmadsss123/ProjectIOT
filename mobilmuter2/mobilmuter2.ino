const int kiri1 = 11;
const int kiri2 = 10;
const int kanan1 = 6;
const int kanan2 = 5;


void setup() {
  // put your setup code here, to run once:
  pinMode(kiri1, OUTPUT);
  pinMode(kiri2, OUTPUT);
  pinMode(kanan1, OUTPUT);
  pinMode(kanan2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(kiri1, 0);
  analogWrite(kiri2, 160);       
  analogWrite(kanan1, 90);
  analogWrite(kanan2, 0);
  // delay(500);
  // analogWrite(kanan1, 0);
  // analogWrite(kanan2, 0);
  // delay(200);
  // analogWrite(kanan1, 90);
  // analogWrite(kanan2, 0);
  // delay(500);
  // analogWrite(kanan1, 0);
  // analogWrite(kanan2, 0);
  // delay(200); 
}
