int led = 13;
int tombol = 12;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(tombol, INPUT);
  digitalWrite(tombol, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int posisi = digitalRead(tombol);
  if (posisi == 0) {
    digitalWrite(led, HIGH);  
  }
  else {
    digitalWrite(led, LOW);
  }
  Serial.println(posisi);
}
