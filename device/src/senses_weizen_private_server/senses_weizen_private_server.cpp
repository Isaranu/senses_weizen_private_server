#include "senses_weizen_private_server.h"

#define host "SERVER-IP-ADDRESS"
#define port <PORT>

#define LAG_TIME 100

bool senses_weizen_private_server::begin(const char *ssid, const char *passw){
  _ssid = ssid;
  _passw = passw;

  int _cnt = 0;

  WiFi.begin(_ssid, _passw);
  Serial.print("senses_weizen_private_server connecting at " + String(host) + " and port " + String(port));

  while(WiFi.status() != WL_CONNECTED){
    delay(300);
    Serial.print(".");
    _cnt++;
  }

  if(WiFi.status() == WL_CONNECTED){
    _conn = true;
    Serial.println("Connected !");
  }else{
    _conn = false;
    Serial.println("Connection Timeout.");
  }

  return _conn;
}

String senses_weizen_private_server::sendTemperature(float t){

    _t = String(t);

    WiFiClient client;
    if(client.connect(host, port)){

      _str = "t:";
      _str += _t;

      client.print(_str);

      /*
      delay(LAG_TIME);
      while(client.available()){
        _res = client.readStringUntil('\r');
      }
      */

      return "data sent";
    }else{
      //Nothing..
    }
}
