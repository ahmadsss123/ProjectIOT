#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

// Define RX and TX pins for SoftwareSerial
const int rxPin = 10; // Pin 10 as RX
const int txPin = 11; // Pin 11 as TX

const int col = 16;
const int row = 2;
LiquidCrystal_I2C lcd(0x27, col, row);

// Create a SoftwareSerial instance
SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  // Initialize the hardware serial for debugging
  Serial.begin(9600);
  Serial.println("Arduino Nano is ready!");

  // Initialize SoftwareSerial for communication with ESP32
  mySerial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  // Send a message to the ESP32
  mySerial.println("Hello from Arduino Nano!");

  // Check if data is received from ESP32
  if (mySerial.available()) {
    String received = mySerial.readString();
    Serial.println("Received from ESP32: " + received);
    lcd.setCursor(0, 0);
    lcd.print("Received from ESP32: " + received);
  }

  delay(1000);
}




// #include <SoftwareSerial.h>
// #include <LiquidCrystal_I2C.h>


// SoftwareSerial komunikasidevice(3, 4);


// const int col = 16;
// const int row = 2;
// LiquidCrystal_I2C lcd(0x27, col, row);


// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   Serial.print("Komunikasi dimulai");


//   lcd.init();
//   lcd.backlight();
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Hahahaha");
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   komunikasidevice.println("Hello dari arduino nano");
//   if(komunikasidevice.available()){
//     String receive = komunikasidevice.readString();
//     Serial.println("Data dari ESP32: " + receive);
//   }
//   delay(500);
// }
