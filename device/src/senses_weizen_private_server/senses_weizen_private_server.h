#ifndef senses_weizen_private_server_h
#define senses_weizen_private_server_h

#include "Arduino.h"
#include "WiFi.h"

class senses_weizen_private_server{

  public:
    bool begin(const char *ssid, const char *passw);
    String sendTemperature(float t);

  private:
    const char *_ssid, *_passw, *_libversion;
    String _str, _res, _t;
    bool _conn;
};

#endif
