#include "configuration.h"
Configuration::Configuration()
{
    intializeConfiguration();
}

// Configuration::Configuration(AsyncWebServer &server) : server(server)
// {
//     intializeConfiguration();
// }

void Configuration::intializeConfiguration()
{
    preferences.begin("smartmass", false);
    bool intialized = preferences.getBool("initialized",false);
    preferences.end();

    if (!intialized)
    {
        resetConfiguration();
    }
}

Configuration::Settings Configuration::getConfiguration()
{
    Configuration::Settings configuration;
    preferences.begin("smartmass", true);
    configuration.displayTimeout = preferences.getULong("displayTimeout", DISPLAY_TIMEOUT);
    configuration.loadcellCalibration = preferences.getLong("loadcellCalibration", LOADCELL_CALIBRATION);
    configuration.loadcellKnownWeight = preferences.getULong("loadcellKnownWeight", LOADCELL_KNOWN_WEIGHT);
    configuration.loadcellMeasurementIntervall = preferences.getULong("loadcellMeasurementIntervall", LOADCELL_MEASUREMENT_INTERVAL);
    configuration.loadcellMeasurementSampling = preferences.getUChar("loadcellMeasurementSampling", LOADCELL_MEASUREMENT_SAMPLING);
    configuration.rfidDecay = preferences.getULong("rfidDecay", RFID_DECAY);
    preferences.end();
    return configuration;
}

//resetConfiguration
void Configuration::resetConfiguration() {
    preferences.begin("smartmass", false);
        preferences.putULong("displayTimeout", DISPLAY_TIMEOUT);
        preferences.putLong("loadcellCalibration", LOADCELL_CALIBRATION);
        preferences.putULong("loadcellKnownWeight", LOADCELL_KNOWN_WEIGHT);
        preferences.putULong("loadcellMeasurementIntervall", LOADCELL_MEASUREMENT_INTERVAL);
        preferences.putUChar("loadcellMeasurementSampling", LOADCELL_MEASUREMENT_SAMPLING);
        preferences.putULong("rfidDecay", RFID_DECAY);
        preferences.putBool("initialized", true);
    preferences.end();
}

