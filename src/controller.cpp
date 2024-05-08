#include "controller.h"

void Controller::getIndex(AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "GET Index");
}

void Controller::postIndex(AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "POST Index");
}

void Controller::getDevice(AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "GET Device");
}

void Controller::postDevice(AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "POST Device");
}

void Controller::getWifi(AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "GET Wifi");
}

void Controller::postWifi(AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "POST Wifi");
}

void Controller::getMqtt(AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "GET Mqtt");
}

void Controller::postMqtt(AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "POST Mqtt");
}