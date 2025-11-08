#include <Servo.h>

// --- Pin Configuration ---
const int pirPin = 2;     // PIR motion sensor pin
const int servoPin = 9;   // Servo motor control pin
const int trigPin = 10;   // Ultrasonic trigger pin
const int echoPin = 11;   // Ultrasonic echo pin
const int buzzerPin = 3;  // Buzzer pin

Servo trashLidServo;  // Servo object for controlling the lid

// --- Timings (milliseconds) ---
const unsigned long lidOpenTime = 3000;  // Total lid open duration
const unsigned long warningTime = 2500;  // Warning time before closing

// --- State Variables ---
bool lidIsOpen = false;
bool triggeredByUltrasonic = false;
bool triggeredByPIR = false;
unsigned long lastMotionTime = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  trashLidServo.attach(servoPin);
  trashLidServo.write(0);  // Start with lid closed

  Serial.begin(9600);
  Serial.println("System Initialized. Waiting for motion...");
}

void loop() {
  // --- Sensor Readings ---
  long distance = measureDistance();   // Measure distance from ultrasonic sensor
  int pirState = digitalRead(pirPin);  // Check motion detection

  // --- ULTRASONIC Trigger ---
  // Open lid if object detected within 15 cm
  if (distance > 0 && distance < 15 && !lidIsOpen) {
    Serial.println("Object detected by ULTRASONIC sensor! Opening lid...");
    openLid(true);
  }

  // --- PIR Trigger ---
  // Open lid if PIR detects motion and object is nearby (<30 cm)
  if (distance < 30 && pirState == HIGH && !lidIsOpen) {
    Serial.println("Motion detected by PIR sensor! Opening lid...");
    openLid(false);
  }

  // --- Warning and Auto-Close ---
  if (lidIsOpen && (millis() - lastMotionTime > warningTime)) {
    warnBeforeClose();
    if (millis() - lastMotionTime > lidOpenTime) {
      closeLid();
    }
  }

  delay(100);  // Small delay for stability
}

// ------------------- Functions -------------------

// Open the lid — specify if triggered by ultrasonic or PIR
void openLid(bool byUltrasonic) {
  trashLidServo.write(90);  // Rotate servo to open position
  lidIsOpen = true;
  triggeredByUltrasonic = byUltrasonic;
  triggeredByPIR = !byUltrasonic;
  lastMotionTime = millis();  // Record time for closure timing
}

// Sound buzzer as a warning before closing
void warnBeforeClose() {
  Serial.println("Warning: Lid will close soon!");
  digitalWrite(buzzerPin, HIGH);
  delay(500);
  digitalWrite(buzzerPin, LOW);
}

// Close the lid and indicate which sensor triggered it
void closeLid() {
  trashLidServo.write(0);  // Close lid

  if (triggeredByPIR)
    Serial.println("Closing lid (opened by PIR sensor).");
  else if (triggeredByUltrasonic)
    Serial.println("Closing lid (opened by Ultrasonic sensor).");
  else
    Serial.println("Closing lid (trigger source unknown).");

  lidIsOpen = false;
  triggeredByPIR = false;
  triggeredByUltrasonic = false;
}

// Measure distance using ultrasonic sensor
long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);  // Timeout 30ms
  if (duration == 0) return -1;                   // No valid reading
  return duration * 0.034 / 2;                    // Convert to cm
}
