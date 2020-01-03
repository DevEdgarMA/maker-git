#define pinLedRojo    11
#define pinLedVerde   10
#define pinLedAzul     9
#define pinButton      2

int pinLeds[] = {
  pinLedRojo,
  pinLedVerde,
  pinLedAzul
};

int contLed;

void setup () {
  pinMode(pinLedRojo, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedAzul, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pinButton), rotarLed, FALLING);

  off();
}

void loop () {
  for (int i=0; i<=255; i++) {
    analogWrite(pinLeds[contLed], i);
    delay(5);
  }
  for (int i=255; i>=0; i--) {
    analogWrite(pinLeds[contLed], i);
    delay(5);
  }
  attachInterrupt(digitalPinToInterrupt(pinButton), rotarLed, FALLING);
}

void rotarLed () {
  detachInterrupt(digitalPinToInterrupt(pinButton));
  contLed++;
  if (contLed > 2)
    contLed = 0;
}

void off () {
  analogWrite(pinLedRojo, 0);
  analogWrite(pinLedVerde, 0);
  analogWrite(pinLedAzul, 0);
}