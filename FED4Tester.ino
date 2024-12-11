#include <Servo.h>

// Pin Definitions
#define SERVO_PIN 5 // PWM capable pin
#define TOUCH_DETECT_PIN 6
#define OUTPUT_PIN1 10
#define OUTPUT_PIN2 11
#define OUTPUT_PIN3 12
#define LED_PIN LED_BUILTIN
#define DELAY_TIME 10000

// Create servo object
Servo myServo;

void setup()
{
  Serial.begin(9600); // Initialize serial communication
  Serial.println("FED4 Tester Starting...");

  // Initialize servo
  myServo.attach(SERVO_PIN);

  // Initialize other outputs
  pinMode(OUTPUT_PIN1, INPUT);
  pinMode(OUTPUT_PIN2, INPUT);
  pinMode(OUTPUT_PIN3, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(TOUCH_DETECT_PIN, INPUT);
  delay(5000);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  Serial.println("Moving servo to 180 degrees");
  myServo.write(180);
  delay(600);

  Serial.println("Moving servo to 0 degrees");
  myServo.write(0);
  delay(600);

  // Create entropy through varying timing
  for (int i = 0; i < 50; i++)
  { // Run 50 cycles
    // Generate different random delays for true entropy
    unsigned long delay1 = random(1, DELAY_TIME);
    unsigned long delay2 = random(1, DELAY_TIME);
    unsigned long delay3 = random(1, DELAY_TIME);

    // Set all pins to OUTPUT LOW with different timing
    pinMode(OUTPUT_PIN1, OUTPUT);
    digitalWrite(OUTPUT_PIN1, LOW);
    delayMicroseconds(delay1);
    pinMode(OUTPUT_PIN1, INPUT);

    pinMode(OUTPUT_PIN2, OUTPUT);
    digitalWrite(OUTPUT_PIN2, LOW);
    delayMicroseconds(delay2);
    pinMode(OUTPUT_PIN2, INPUT);

    pinMode(OUTPUT_PIN3, OUTPUT);
    digitalWrite(OUTPUT_PIN3, LOW);
    delayMicroseconds(delay3);
    pinMode(OUTPUT_PIN3, INPUT);
  }

  digitalWrite(LED_PIN, LOW);
}
