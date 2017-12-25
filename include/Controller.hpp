#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
signals:
    void flap();

public slots:
    virtual void receiveData(qreal) = 0;
};

#endif // CONTROLLER_H
