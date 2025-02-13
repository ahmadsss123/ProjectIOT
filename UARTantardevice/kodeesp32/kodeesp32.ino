#include <HardwareSerial.h>

// Create an instance of HardwareSerial (Use UART1 or UART2)
HardwareSerial mySerial(1); // Using UART1

void setup() {
  // Initialize UART communication on custom pins
  mySerial.begin(9600, SERIAL_8N1, 16, 17); // RX=GPIO16, TX=GPIO17
  Serial.begin(115200); // Default UART for debugging
  Serial.println("ESP32 is ready!");
}

void loop() {
  // Check if data is available from Arduino
  mySerial.println("Hello from ESP32!");

  if (mySerial.available()) {
    String received = mySerial.readString();
    Serial.println("Received: " + received);
  }

  delay(1000);
}



// #include <HardwareSerial.h>


// HardwareSerial Myserial(1);


// void setup() {
//   // put your setup code here, to run once:
//   Myserial.begin(9600, SERIAL_8N1, 16, 17);
//   Serial.begin(115200);
//   Serial.println("ESP32 Custom UART Example");
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   Myserial.println("Hello from UART1!");
//   if(Myserial.available()){
//     String receive = Myserial.readString();
//     Serial.println("Data transfer: " + receive);
//   }


//   delay(1000);
// }
