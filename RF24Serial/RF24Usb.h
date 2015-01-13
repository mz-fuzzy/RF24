#ifndef __RF24Dongle_H
#define __RF24Dongle_H

#include "RF24.h"

//#ifndef ARDUINO
//#define PROGMEM
//#endif

// USB protocol version
#define USB_PROTOCOL_VERSION 1

#define USB_CMD_VERSIONCHECK 250

#define MAX_PARAMS_TYPE 3
#define MAX_BUFF 64
#define MAX_PARAMS 4

#define IPAR 0
#define OPAR 1

#ifndef RF24_DEVICE_CEPIN
    #define RF24_DEVICE_CEPIN 4
#endif

#ifndef RF24_DEVICE_CSPIN
    #define RF24_DEVICE_CSPIN 5
#endif


typedef enum
{
    RF24_none=0,
    RF24_bool,
    RF24_uint8,
    RF24_uint16,
    RF24_uint32,
    RF24_uint64,
    RF24_buff,
} ERF24ParamType;

typedef enum
{
    RF24_begin = 0,
    RF24_startListening,
    RF24_stopListening,
    RF24_available,
    RF24_availablePipe,
    RF24_read,
    RF24_write, /* blocking  */
    RF24_writeMulticast,
    RF24_openWritingPipe,
    RF24_openWritingPipe40,
    RF24_openReadingPipe,

    RF24_openReadingPipe40,
    RF24_printDetails,
    RF24_rxFifoFull,
    RF24_powerDown,
    RF24_powerUp,
    RF24_writeFast, /* blocking */
    RF24_writeFastMulticast, /* blocking */
    RF24_writeBlocking, /* blocking */
    RF24_txStandBy, /* blocking */
    RF24_txStandByTimeout, /* blocking */

    RF24_writeAckPayload,
    RF24_enableDynamicAck,
    RF24_isAckPayloadAvailable,
    RF24_whatHappened,
    RF24_startFastWrite,
    RF24_startWrite,
    RF24_reUseTX,
    RF24_flush_tx,
    RF24_testCarrier,
    RF24_testRPD,

    RF24_isValid,
    RF24_maskIRQ,
    RF24_setAddressWidth,
    RF24_closeReadingPipe,
    RF24_setRetries,
    RF24_setChannel,
    RF24_setPayloadSize,
    RF24_getPayloadSize,
    RF24_getDynamicPayloadSize,
    RF24_enableAckPayload,

    RF24_enableDynamicPayloads,
    RF24_isPVariant,
    RF24_setAutoAck,
    RF24_setAutoAckPipe,
    RF24_setPALevel,
    RF24_getPALevel,
    RF24_setDataRate,
    RF24_getDataRate,
    RF24_setCRCLength,
    RF24_getCRCLength,
    RF24_disableCRC,
    RF24_getFailureDetected,
    RF24_setFailureDetected,
} ERF24Command;


extern const ERF24ParamType RF24Commands[][2][MAX_PARAMS];

class RF24Usb: public RF24
{
public:
    RF24Usb(void): RF24(RF24_DEVICE_CEPIN, RF24_DEVICE_CSPIN) {};
    int parse(int paramtype, const uint8_t *p);
    int store(int paramtype, uint8_t *p, uint8_t *ln);
    int executeCommand(void);

protected:
    ERF24Command command;
    bool p_bool[2][MAX_PARAMS_TYPE];
    uint8_t p_uint8[2][MAX_PARAMS_TYPE];
    uint16_t p_uint16[2][MAX_PARAMS_TYPE];
    uint32_t p_uint32[2][MAX_PARAMS_TYPE];
    uint64_t p_uint64[2][MAX_PARAMS_TYPE];
    uint8_t p_buf[2][MAX_BUFF];
    uint8_t p_buf_ln[2];
};

#endif


