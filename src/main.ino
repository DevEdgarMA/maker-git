#define pinLedRojo    11
#define pinLedVerde   10
#define pinLedAzul     9
#define pinButton      2
#define pinPotenciometro  A0

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
  int valorPot = analogRead(pinPotenciometro);    // 0 - 1023
  int valor = map(valorPot, 0, 1023, 0, 255);

  analogWrite(pinLeds[contLed], valor);
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