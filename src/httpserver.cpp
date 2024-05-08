#include "httpserver.h"

HttpServer::HttpServer(int port, Controller &controller) : server(port), controller(controller) {}

void HttpServer::init() {
    // GETs
    server.on("/", HTTP_GET, [this](AsyncWebServerRequest *request)
              { controller.getIndex(request); });
    server.on("/device", HTTP_GET, [this](AsyncWebServerRequest *request)
              { controller.getDevice(request); });
    server.on("/wifi", HTTP_GET, [this](AsyncWebServerRequest *request)
              { controller.getWifi(request); });
    server.on("/mqtt", HTTP_GET, [this](AsyncWebServerRequest *request)
              { controller.getMqtt(request); });

    // POSTs
    server.on("/", HTTP_POST, [this](AsyncWebServerRequest *request)
              { controller.postIndex(request); });
    server.on("/device", HTTP_POST, [this](AsyncWebServerRequest *request)
              { controller.postDevice(request); });
    server.on("/wifi", HTTP_POST, [this](AsyncWebServerRequest *request)
              { controller.postWifi(request); });
    server.on("/mqtt", HTTP_POST, [this](AsyncWebServerRequest *request)
              { controller.postMqtt(request); });

    // error handling
    server.onNotFound([this](AsyncWebServerRequest *request)
                     { request->send(404, "text/plain", "Not found"); });

    server.begin();
}