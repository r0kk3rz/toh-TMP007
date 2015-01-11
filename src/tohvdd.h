#ifndef TOHVDD_H
#define TOHVDD_H

#include <QObject>

class tohVDD : public QObject
{
    Q_OBJECT
public:
    explicit tohVDD(QObject *parent = 0);

    void toggle();

signals:

public slots:

private:
    bool _enabled;

};

#endif // TOHVDD_H
