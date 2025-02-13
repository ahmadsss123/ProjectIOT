// Device Arduino Nano
// pin lcd: - vcc = 5V
//          - SDA = A4
//          - SCL = A5

// pin GPS NEO 6M : - Tx = D8
//                  - Rx = D7
//                  - vcc = 3.3V
#include <LiquidCrystal_I2C.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>


SoftwareSerial serial_gps(8, 7);
TinyGPSPlus gps;
double latitude, longitude;


const int col = 16;
const int row = 2;
LiquidCrystal_I2C lcd(0x27, col, row);
int tombol1 = 3;
int tombol2 = 4;


int pos = 0;
// String baris1 = "Longitude";
// String baris2 = "0";
// int waktusebelum = 0;


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.clear();


  Serial.begin(9600);
  serial_gps.begin(9600);
  Serial.println("GPS Mulai");


  // pinMode(8, INPUT);
  // pinMode(7, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(serial_gps.available()){
    gps.encode(serial_gps.read());
  }
  if(gps.location.isUpdated()){


    Serial.print("Latitude=");
    Serial.print(gps.location.lat(), 6);
    Serial.print("Longitude=");
    Serial.println(gps.location.lng(), 6);


    delay(2500);

  }

    lcd.setCursor(pos,0);
    lcd.print(gps.location.lat(), 6);
    lcd.setCursor(pos,1);
    lcd.print(gps.location.lng(), 6); 
    lcd.clear();

  // unsigned long waktu = millis();
  // int perbedaan = waktu - waktusebelum;
  // if((perbedaan) >= 100) {
  //   waktusebelum = waktu;
  //   lcd.clear();    
  // }


  

  
  
  // int keadaan1 = digitalRead(tombol1);
  // if (keadaan1 == 0) {
  //   baris1 = "Longitude";
  //   baris2 = "0";  
  // }
  // int keadaan2 = digitalRead(tombol2);
  // if (keadaan2 == 0) {
  //   baris1 = "Latitude";
  //   baris2 = "100";  
  // }

}
