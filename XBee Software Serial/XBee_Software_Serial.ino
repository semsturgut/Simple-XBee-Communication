#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 3

SoftwareSerial Xbee =  SoftwareSerial(rxPin, txPin);

int rnd_num;
int count = 0;
char chr_get;
char str_set[20];
char* str_get[10];

void setup() {
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 Xbee.begin(9600);
 Serial.begin(9600);
 Serial.println("Starting XBee Comunication");
}

void loop() {
  if (Xbee.available()){
    while (Xbee.available()) {
      if (count > 19){
        str_set[count] = '\0';
        break;
      }
      chr_get = Xbee.read();
      str_set[count] = chr_get;
      count++;
      Serial.print(chr_get);
    }
  }
  Serial.println(str_set);
//rnd = random(1000);
//xbee.print("Selam :");
//xbee.println(rnd);
//Serial.print(xbee.read());
  delay(1000);
}
