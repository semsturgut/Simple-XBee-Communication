//Simple read data coming from Xbee and write it to serial screen.
void setup()  {
Serial.begin(9600);
}

void loop() {
Serial.println(Serial.read());
delay(1000);
}
