#include <senses_weizen_private_server.h>

const char *ssid = "ssid";
const char *passw = "password";

String response; 
float t;

senses_weizen_private_server myiot;

void setup() {
  Serial.begin(9600);
  bool conn = myiot.begin(ssid, passw);

  if(conn){
      Serial.println("Connected.");
    }else{
      Serial.println("re-connect again.");
  }
}

void loop() {
  
  response = "";
  
  t = random(40,50); /* Random temp. */
  Serial.println("Random t=" + String(t));
  response = myiot.sendTemperature(t);
  Serial.println(response);
  
  delay(3000);
}
