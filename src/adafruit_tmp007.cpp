#include "adafruit_tmp007.h"

Adafruit_TMP007::Adafruit_TMP007(unsigned char addr)
{
    i2c_addr = addr;
}

Adafruit_TMP007::~Adafruit_TMP007()
{

}

bool Adafruit_TMP007::init()
{   
    unsigned short config = TMP007_CFG_MODEON | TMP007_CFG_ALERTEN | TMP007_CFG_TRANSC | TMP007_CFG_2SAMPLE;


    qDebug() << "init started";
    char config_addr[] = { TMP007_CONFIG };
    char config_table[2];
    config_table[0] = config & 0xff;
    config_table[1] = (config >> 8) & 0xff;


    unsigned short statmask = TMP007_STAT_ALERTEN | TMP007_STAT_CRTEN;

    char statmask_addr[] = { TMP007_STATMASK };
    char statmask_table[2];

    statmask_table[0] = statmask & 0xff;
    statmask_table[1] = (statmask >> 8) & 0xff;

    qDebug() << "write one";
    writeBytes(i2c_addr, config_addr, 1);
    writeBytes(i2c_addr, config_table, 2);

    qDebug() << "write two";
    writeBytes(i2c_addr, statmask_addr, 1);
    writeBytes(i2c_addr, statmask_table, 2);


    // enable conversion ready alert

    QByteArray did;
    //did = read16(TMP007_DEVID);
    did = writeThenRead(i2c_addr, TMP007_DEVID, 1);

    qDebug() << did.toHex();

    //if (did != 0x78) return false;
    return true;
}

double Adafruit_TMP007::readObjTempC() {
  int16_t raw = read16(TMP007_TOBJ);
  // invalid
  if (raw & 0x1) return -1;
  raw >>=2;

  double Tobj = raw;
  Tobj *= 0.03125; // convert to celsius
    if(TMP007_DEBUG == 1)
    {
        qDebug() << "Tobj = " << Tobj << " C";
    }
   return Tobj;
}

double Adafruit_TMP007::readDieTempC() {
    double Tdie = readRawDieTemperature();
    Tdie *= 0.03125; // convert to celsius
    if(TMP007_DEBUG == 1)
    {
       qDebug() << "Tdie = " << Tdie << " C";
    }
   return Tdie;
}

int16_t Adafruit_TMP007::readRawDieTemperature() {
    int16_t raw = read16(TMP007_TDIE);

    if(TMP007_DEBUG == 1)
    {
      qDebug() << "Raw Tambient: 0x" << raw;

      float v = raw/4;
      v *= 0.03125;
      qDebug() << " (" <<  v << " *C)";
    }
      raw >>= 2;
      return raw;
}

int16_t Adafruit_TMP007::readRawVoltage() {
    int16_t raw;

    raw = read16(TMP007_VOBJ);

    if(TMP007_DEBUG == 1)
    {
        qDebug() << "Raw voltage: 0x" << raw;
        float v = raw;
        v *= 156.25;
        v /= 1000;
        qDebug() << " (" << v << " uV)";
    }
    return raw;
}

unsigned short Adafruit_TMP007::read16(unsigned char a)
{
    QByteArray bArray;
    bArray = writeThenRead(i2c_addr, a, 2);

    qreal temp = (double)(bArray.at(0) | ( bArray.at(1) << 8 )) / 16.0;

    qDebug() << temp;

    qDebug() << bArray;
    qDebug() << bArray.toInt();
    qDebug() << bArray.toHex();
    return bArray.toShort();
}


