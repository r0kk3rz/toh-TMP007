#ifndef ADAFRUIT_TMP007_H
#define ADAFRUIT_TMP007_H

#include <QObject>
#include "driverBase.h"

namespace {
    const unsigned char TMP007_VOBJ = 0x00;
    const unsigned char TMP007_TDIE = 0x01;
    const unsigned char TMP007_CONFIG = 0x02;
    const unsigned char TMP007_TOBJ = 0x03;
    const unsigned char TMP007_STATUS = 0x04;
    const unsigned char TMP007_STATMASK = 0x05;
    const unsigned short TMP007_CFG_RESET = 0x8000;
    const unsigned short TMP007_CFG_MODEON = 0x1000;
    const unsigned short TMP007_CFG_1SAMPLE = 0x0000;
    const unsigned short TMP007_CFG_2SAMPLE = 0x0200;
    const unsigned short TMP007_CFG_4SAMPLE = 0x0400;
    const unsigned short TMP007_CFG_8SAMPLE = 0x0600;
    const unsigned short TMP007_CFG_16SAMPLE = 0x0800;
    const unsigned short TMP007_CFG_ALERTEN = 0x0100;
    const unsigned short TMP007_CFG_ALERTF = 0x0080;
    const unsigned short TMP007_CFG_TRANSC = 0x0040;
    const unsigned short TMP007_STAT_ALERTEN = 0x8000;
    const unsigned short TMP007_STAT_CRTEN = 0x4000;
    const unsigned char TMP007_I2CADDR = 0x40;
    const unsigned char TMP007_DEVID = 0x1F;

    const unsigned int TMP007_DEBUG = 1;
}

class Adafruit_TMP007 : public DriverBase
{
    Q_OBJECT

    public:
        explicit Adafruit_TMP007(unsigned char addr = TMP007_I2CADDR);
        ~Adafruit_TMP007();

        bool init();

    public slots:
        double readDieTempC();
        double readObjTempC();

    private:
        unsigned char i2c_addr;

        int16_t readRawDieTemperature();
        int16_t readRawVoltage();

        unsigned short read16(unsigned char a);
};

#endif // ADAFRUIT_TMP007_H
