#include "irtempsensor.h"

char const * const IRTempSensor::id("toh.irtempsensor");

IRTempSensor::IRTempSensor(QObject * parent): QObject(parent)
{


    tmp007 = new Adafruit_TMP007();

    pollTimer = new QTimer();
    pollTimer->setInterval(1000);
    connect(pollTimer, SIGNAL(timeout()), this, SLOT(poll()));
    _objectReading = -1;
}

void IRTempSensor::start()
{
    if(!tmp007->init())
    {
        emit sensorStopped();
    }
    else
    {
        timer.start();
        pollTimer->start();
    }
}

void IRTempSensor::poll()
{
    qreal temp;

    //do some stuff to get the sensor reading
    temp = tmp007->readObjTempC();

    qDebug() << "Object Temperature: " << temp;

    if(temp != _objectReading)
    {
        _objectReading = temp;
        sensorReadingChanged();
    }
}

const qreal &IRTempSensor::sensorReading()
{
    return _objectReading;
}

