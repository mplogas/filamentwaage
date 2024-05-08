#ifndef CONFIGURATION_H
#define CONFIGURATION_H


#include "secrets.h"
#include <Preferences.h>

class Configuration
{
    private:
        void intializeConfiguration();
        Preferences preferences;
    public:
        Configuration();
        //Configuration(AsyncWebServer &server);
        struct Settings
        {
            unsigned long displayTimeout;
            long loadcellCalibration;
            unsigned long loadcellKnownWeight;
            unsigned long loadcellMeasurementIntervall;
            uint8_t loadcellMeasurementSampling;
            unsigned long rfidDecay;
        };
        void initHttp();
        Settings getConfiguration();
        void setConfiguration(Settings configuration);
        void resetConfiguration();
};
#endif // CONFIGURATION_H