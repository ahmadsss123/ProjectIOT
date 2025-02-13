#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Define the UUIDs for the BLE Service and Characteristic
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

BLECharacteristic *pCharacteristic;
const int pot = 34; 

void setup() {
  Serial.begin(115200);
  pinMode(pot, INPUT);

  // Initialize the BLE device
  BLEDevice::init("ESP32-SingleService");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_NOTIFY
                                       );

  // Set an initial value for the characteristic
  pCharacteristic->setValue("Hello from ESP32");

  // Start the service
  pService->start();

  // Start advertising the BLE server
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection...");
}

void loop() {
  // Logic to handle BLE communication or other tasks can go here
  
}