// Comment the next line to use ABP authentication on TTN. Leave it as it is to use recommended OTAA
//#define OTAA

#ifndef LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED
#define LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED

#ifndef OTAA
// UPDATE WITH YOUR TTN KEYS AND ADDR.
// Settings for ABP device
static PROGMEM u1_t NWKSKEY[16] = { 0x08, 0xAC, 0x23, 0xB4, 0x22, 0x80, 0xF6, 0x9F, 0xE8, 0xB7, 0x15, 0x2F, 0x96, 0x55, 0xC2, 0x68 }; // LoRaWAN NwkSKey, network session key 
static u1_t PROGMEM APPSKEY[16] = { 0xE7, 0x8E, 0x60, 0xE5, 0xE2, 0xF7, 0x58, 0x1D, 0x0A, 0x3B, 0x16, 0x06, 0xFE, 0x05, 0x1E, 0x88 }; // LoRaWAN AppSKey, application session key 
static const u4_t DEVADDR = 0x26011983 ; // LoRaWAN end-device address (DevAddr)
#else
// Settings from OTAA device
static const u1_t PROGMEM DEVEUI[8]={ 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 } ; // Device EUI, hex, lsb
static const u1_t PROGMEM APPEUI[8]={ 0xCD, 0x8E, 0x01, 0xD0, 0x7E, 0xD5, 0xB3, 0x70 }; // Application EUI, hex, lsb
static const u1_t PROGMEM APPKEY[16] = { 0x9C, 0x66, 0xFD, 0x3D, 0xCD, 0x5F, 0xAC, 0x3C, 0xFC, 0x30, 0x4A, 0x32, 0x37, 0x54, 0xCC, 0x26 }; // App Key, hex, msb

void os_getDevEui (u1_t* buf) { memcpy_P(buf, DEVEUI, 8);}
void os_getArtEui (u1_t* buf) { memcpy_P(buf, APPEUI, 8);}
void os_getDevKey (u1_t* buf) {  memcpy_P(buf, APPKEY, 16);}
#endif

#endif //LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED
