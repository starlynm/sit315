const int ledPin = 13;
const int analogSensorPin = A0;
const int buttonOnPin = 8;
const int buttonOffPin = 9;

volatile bool toggleLedFlag = false;
volatile bool readSensorFlag = false;
volatile bool ledOnFlag = false;
volatile bool ledOffFlag = false;

bool ledState = false;
bool manualOverride = false;  // prevents timer from changing LED

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonOnPin, INPUT);
  pinMode(buttonOffPin, INPUT);
  Serial.begin(9600);

  // Timer1 Setup
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 15624;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  sei();

  // PCI for D8–D13
  PCICR |= (1 << PCIE0);
  PCMSK0 |= (1 << PCINT0);  // D8
  PCMSK0 |= (1 << PCINT1);  // D9
}

void loop() {
  if (toggleLedFlag) {
    if (!manualOverride) {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
    toggleLedFlag = false;
  }

  if (readSensorFlag) {
    int val = analogRead(analogSensorPin);
    Serial.print("Analog sensor reading (A0): ");
    Serial.println(val);
    readSensorFlag = false;
  }

  if (ledOnFlag) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED turned ON by Button 1 (D8)");
    manualOverride = true;
    ledOnFlag = false;
  }

  if (ledOffFlag) {
    digitalWrite(ledPin, LOW);
    Serial.println("LED turned OFF by Button 2 (D9)");
    manualOverride = true;
    ledOffFlag = false;
  }
}

// Timer1 ISR
ISR(TIMER1_COMPA_vect) {
  toggleLedFlag = true;
  readSensorFlag = true;
}