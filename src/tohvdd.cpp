#include "tohvdd.h"
#include <QDebug>

tohVDD::tohVDD(QObject *parent) :
    QObject(parent)
{
    _enabled = false;
}

void tohVDD::toggle()
{
    int fd;

    //fd = open("/sys/devices/platform/reg-userspace-consumer.0/state", O_WRONLY);

    if (!(fd < 0))
    {
        if (write (fd, _enabled ? "0" : "1", 1) != 1)
            qDebug() << "Vdd set failed\n";
        else
        {
            qDebug() << "Vdd set OK\n";
            _enabled = true;
        }

        close(fd);
    }
    else
        qDebug() << "Vdd failed to open. Did you start i2ctool as root?\n";
}
