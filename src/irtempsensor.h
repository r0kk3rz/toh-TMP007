#ifndef IRTEMPSENSOR_H
#define IRTEMPSENSOR_H

#include <QObject>
#include <QSensorBackend>
#include <QAmbientTemperatureReading>
#include "adafruit_tmp007.h"
#include <QTime>
#include <QTimer>


class IRTempSensor : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float sensorReading READ sensorReading NOTIFY sensorReadingChanged)

public:
    static char const * const id;
    IRTempSensor(QObject * parent = 0);
    const qreal &sensorReading();

public slots:
    void start();

signals:
    void sensorReadingChanged();
    void sensorStopped();

private:
    Adafruit_TMP007 *tmp007;
    QTime timer;
    QTimer * pollTimer;
    qreal _objectReading;

private slots:
    void poll();

};

#endif // IRTEMPSENSOR_H
