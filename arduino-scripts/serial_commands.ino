/*
Считываем с последовательного порта символьные команды "on" и "off"
При включении ("on") - загорается светодиод на 13 пине, при выключении - отключается.
*/
  int led = 13;
  
  void setup()
  {
    Serial.begin(115200); // открыть серийный порт на скорости 115200 бит/с
    pinMode(led, OUTPUT);
  }
  
  void loop()
  {
     
     while(Serial.available() > 0) {
      String ttydata = Serial.readString(); // ttyData - информация с серийного порта
      if (ttydata.substring(0,2) == "on") {
        Serial.println("ON");
        digitalWrite(led, HIGH);
      } else if (ttydata.substring(0,3) == "off") {
         Serial.println("OFF");
         digitalWrite(led, LOW);
      } else {
        Serial.println("error command");
     }
  }
}