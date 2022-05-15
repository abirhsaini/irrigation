#include <DHT.h>

#define DHTTYPE DHT11
#define DHT11_PIN 7
DHT dht(DHT11_PIN ,DHTTYPE);

const int LevelPin= 1; // Déclaration de la broche du capteur level

int liquid_level;//level

int LDRPin = A5; // select the input pin for LDR

int LDRValue = 0; // variable to store the value coming from the sensor ldr


int SENSEHumidity= 0; // Soil Sensor input at Analog PIN A0

int valueHumidity= 0;

void setup() {
   Serial.begin(9600);
    pinMode(LevelPin, INPUT);
    pinMode(13,OUTPUT); //signale a l arduino que la connexion 10 doit pouvoir envoyer du courant
    dht.begin();
}
void loop() {
float temperature=dht.readTemperature();
float humidity=dht.readHumidity();
Serial.println("temp");
Serial.println("-----------------------------");
Serial.print("Temperature = ");
Serial.println(temperature);
Serial.println("");
Serial.println("HUMIDITY SENSOR"); 
Serial.println("-----------------------------");
Serial.print("Humidity = ");
Serial.println(humidity);
Serial.println("");
delay(1000);
//// level
liquid_level= analogRead(LevelPin); // Lecture de la valeur analogique du capteur
Serial.println("LEVEL SENSOR");
Serial.println("-----------------------------");
Serial.println(liquid_level);// Affichage de la valeur dans le moniteur série
delay(3000);
//// lumiere
delay(6000);
Serial.println("LIGHT SENSOR");
Serial.println("-----------------------------");
LDRValue = analogRead(A5); // read the value from the sensor
Serial.println(LDRValue); //prints the values coming from the sensor on the screen
//// humidité
delay(9000);
Serial.println("SOIL SENSOR");
Serial.println("-----------------------------");
valueHumidity= analogRead(SENSEHumidity); 
Serial.println(valueHumidity);
  if(valueHumidity>556)  { 
    if ((temperature>2) &&  (temperature<10)) {
      if (LDRValue>100) {
          if (liquid_level>=70) {
                digitalWrite(13,HIGH); // demande  l'ardui de mettre la connexion 13 à 5V
                delay (1000); 
                digitalWrite(13,LOW); // demande  l'ardui de mettre la connexion 13 à 0V
            }
          else 
          {
                digitalWrite(13,LOW); // demande  l'ardui de mettre la connexion 13 à 0V
                Serial.println(liquid_level);
                Serial.println("Attention veuillez verifier source d'eau");
                Serial.println("");
        }       
      }
    }
    if ((temperature>10) &&  (temperature<30)) { 
      if (liquid_level>=70) {
        digitalWrite(13,HIGH); // demande  l'ardui de mettre la connexion 13 à 5V
        delay (2000); 
        digitalWrite(13,LOW); // demande  l'ardui de mettre la connexion 13 à 0V
      }
      else 
      {
           digitalWrite(13,LOW); // demande  l'ardui de mettre la connexion 13 à 0V
                Serial.println(liquid_level);
                Serial.println("Attention veuillez verifier source d'eau");
                Serial.println(""); 
        }        
    }
      if (temperature>30){
       if (liquid_level>=70) {
           digitalWrite(13,HIGH); // demande  l'ardui de mettre la connexion 13 à 5V
           delay (5000); 
           digitalWrite(13,LOW); // demande  l'ardui de mettre la connexion 13 à 0
       }
       else
       {
           digitalWrite(13,LOW); // demande  l'ardui de mettre la connexion 13 à 0V
                Serial.println(liquid_level);
                Serial.println("Attention veuillez verifier source d'eau");
                Serial.println(""); 
    }
   }
  }
 if(valueHumidity<556)  { 
    Serial.println("l'humidité est assuré");
    Serial.println("");
    digitalWrite(13,LOW); 
    }
 }
