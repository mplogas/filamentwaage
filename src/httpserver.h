#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "controller.h"
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class HttpServer {
  private:
    AsyncWebServer server;
    Controller &controller;
  public:
    HttpServer(int port, Controller &controller);
    void init();
};

#endif