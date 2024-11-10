#define Relay 26
#define AOUT_PIN 32
#define led 2

// Deklarasi Blynk
#define BLYNK_TEMPLATE_ID "Masukkan Template ID yang tersedia di blynk"
#define BLYNK_TEMPLATE_NAME "Masukkan Template Name yang tersedia di blynk"
#define BLYNK_AUTH_TOKEN "Matukkan token kalian yang tersedia di blynk"
#include <BlynkSimpleESP32.h>

//Deklarasi WiFi
char ssid[]="Masukan nama WiFi kalian";
char pass[]="Masukkan password WiFi kalian";s

int Nilai;
void setup() {
  Serial.begin(9600);
  pinMode(Relay, OUTPUT);
  pinMode(led, OUTPUT);
  analogSetAttenuation(ADC_11db);
   // Setting WiFi
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi Connected");

  // // Setting Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Blynk Connected");
  delay(500);
}

void loop() {
  
  Nilai = analogRead(AOUT_PIN); 
  Serial.print("Moisture value: ");
  Blynk.run();
  Blynk.virtualWrite(V0, Nilai);
  Serial.println(Nilai);
  delay(500);

  if (Nilai <= 2500){
  digitalWrite(Relay, HIGH);
  digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(Relay, LOW);
    digitalWrite(led, LOW);
  }
}
