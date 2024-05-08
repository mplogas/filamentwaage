#include "device.h"

Device::Device(Display &display, Scale &scale, RFID &rfid) : display(display), scale(scale), rfid(rfid)
{
}

void Device::init(Configuration::Settings &settings)
{
    config = settings;
    initDevice();
}



void Device::initDevice()
{
    display.init();
    display.setScreenTimeOut(config.displayTimeout);
    scale.init(config.loadcellCalibration, config.loadcellMeasurementIntervall);
    measurement.ts = millis();
    rfid.init();
}