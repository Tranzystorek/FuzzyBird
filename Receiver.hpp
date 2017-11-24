#ifndef RECEIVER_HPP
#define RECEIVER_HPP

#include <QObject>
#include "Controller.hpp"

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(Controller*, QObject* parent = nullptr);

    void setController(Controller*);

private:
    Controller* controller_;

signals:
    void sendData();

public slots:
    virtual void doFlap() = 0;
};

#endif // RECEIVER_HPP
