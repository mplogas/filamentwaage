#ifndef DEVICE_H
#define DEVICE_H

#include "configuration.h"
#include "display.h"
#include "scale.h"
#include "rfid.h"

class Device
{
public:
    Device(Display &display, Scale &scale, RFID &rfid);
    void init(Configuration::Settings &configuration);
    void loop();
    void configure(Configuration::Settings &configuration);
    void calibrate();
    void tare();
    void writeTag(TagData &tagData);
    void measureWeight();
private:
    Display display;
    RFID rfid;
    Scale scale;
    Configuration::Settings config;
    void initDevice();
};

#endif // DEVICE_H
