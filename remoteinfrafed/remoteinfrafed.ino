#include<IRremote.h>

const int pinIR = 7;
IRrecv recv(pinIR);
decode_results hasil;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  recv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(recv.decode(&hasil)) {
    Serial.println(hasil.value);
    recv.resume();
  }
}
