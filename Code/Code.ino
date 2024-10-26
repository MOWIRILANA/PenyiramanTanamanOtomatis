#define Relay 12
#define AOUT_PIN 13

void setup() {
  Serial.begin(9600);
  pinMode(Relay, OUTPUT);
  analogSetAttenuation(ADC_11db);
}

void loop() {
  int Nilai = analogRead(AOUT_PIN); // read the analog value from sensor

  Serial.print("Moisture value: ");
  Serial.println(Nilai);
  delay(500);

  if (Nilai <= 2000){
  digitalWrite(Relay, HIGH);
  }
  else{
    digitalWrite(Relay, LOW);
  }
}
