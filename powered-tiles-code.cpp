// Include the required libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- Configuration ---

// Set the I2C address of your LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);  // <-- Use your correct I2C address

// Define the pins for monitoring
const int PIEZO_INPUT_PIN = A0; 
const int BATTERY_VOLTAGE_PIN = A1; 
const int LED_PIN = 8; // <-- NEW: Pin for the LED strip/LED

// Voltage divider resistors (R1 = 100k, R2 = 10k)
const float R1 = 100000.0;
const float R2 = 10000.0;
const float ARDUINO_VOLTAGE = 5.0; 

// Threshold for detecting a "step" (adjust this value)
const int STEP_THRESHOLD = 3; 

// --- Global Variables ---
long stepCount = 0;
bool stepDetected = false;

void setup() {
  // Initialize the LCD
  lcd.init(); // Use lcd.begin()
  lcd.backlight();
  
  pinMode(LED_PIN, OUTPUT); // <-- NEW: Set the LED pin as an output
  digitalWrite(LED_PIN, LOW); // <-- NEW: Make sure LED is off at start
  
  // Set up the initial display message
  lcd.setCursor(0, 0); // (column, row)
  lcd.print("Power Tile v1.0");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
}

void loop() {
  // 1. Check for a new step
  int piezoValue = analogRead(PIEZO_INPUT_PIN);
  
  if (piezoValue > STEP_THRESHOLD && !stepDetected) {
    stepCount++;
    stepDetected = true; // Set a flag so we only count this step once
    
    // --- NEW LED BLINK LOGIC ---
    digitalWrite(LED_PIN, HIGH); // Turn LED on
    delay(100);                   // Keep it on for 100ms (a quick flash)
    digitalWrite(LED_PIN, LOW);  // Turn LED off
    // --- END NEW LOGIC ---
  }
  
  // Reset the flag when the pressure is gone
  if (piezoValue < STEP_THRESHOLD) {
    stepDetected = false;
  }

  // 2. Read and calculate battery voltage
  int batteryReading = analogRead(BATTERY_VOLTAGE_PIN);
  float dividerVoltage = (batteryReading / 1024.0) * ARDUINO_VOLTAGE;
  float batteryVoltage = dividerVoltage * ((R1 + R2) / R2);
  float batteryMilliVolts = batteryVoltage * 1000.0; 

  // 3. Display the information on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Steps: ");
  lcd.print(stepCount);

  lcd.setCursor(0, 1);
  lcd.print("Battery: ");
  lcd.print(batteryMilliVolts, 0); 
  lcd.print(" mV");                

  delay(250); 
}
