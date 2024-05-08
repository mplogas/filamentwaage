#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view.h"
#include <ESPAsyncWebServer.h>


class Controller {
  public:
    void getIndex(AsyncWebServerRequest *request);
    void postIndex(AsyncWebServerRequest *request);
    void getDevice(AsyncWebServerRequest *request);
    void postDevice(AsyncWebServerRequest *request);
    void getWifi(AsyncWebServerRequest *request);
    void postWifi(AsyncWebServerRequest *request);
    void getMqtt(AsyncWebServerRequest *request);
    void postMqtt(AsyncWebServerRequest *request);
};

#endif