#define pinLedRojo    11
#define pinLedVerde   10
#define pinLedAzul     9

void setup () {
  pinMode(pinLedRojo, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedAzul, OUTPUT);
}

void loop () {
  for (int i=0; i<=255; i++) {
    analogWrite(pinLedRojo, i);
    delay(5);
  }
  for (int i=255; i>=0; i--) {
    analogWrite(pinLedRojo, i);
    delay(5);
  }
}