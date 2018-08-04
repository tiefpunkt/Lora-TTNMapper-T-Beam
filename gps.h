#ifndef __GPS_H__
#define __GPS_H__

#include <TinyGPS++.h>
#include <HardwareSerial.h>

#define PMTK_SET_NMEA_UPDATE_05HZ  "$PMTK220,2000*1C"
#define PMTK_SET_NMEA_UPDATE_1HZ  "$PMTK220,1000*1F"
#define PMTK_SET_NMEA_OUTPUT_RMCGGA "$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28"
#define GPS_TX 12
#define GPS_RX 15

class gps
{
    public:
        void init();
        bool checkGpsFix();
        void buildPacket(uint8_t txBuffer[9]);

    private:
        void encode();

        uint32_t LatitudeBinary, LongitudeBinary;
        uint16_t altitudeGps;
        uint8_t hdopGps;
        char t[32]; // used to sprintf for Serial output
        TinyGPSPlus tGps;
};

#endif