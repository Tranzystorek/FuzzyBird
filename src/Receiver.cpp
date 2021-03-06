#include "Receiver.hpp"

Receiver::Receiver(Controller* controller, QObject* parent) : QObject(parent)
{
    controller_ = controller;

    connect(controller_, SIGNAL(flap()), this, SLOT(doFlap()));
    connect(this, SIGNAL(sendData(qreal, qreal, qreal, qreal)), controller_, SLOT(receiveData(qreal, qreal, qreal, qreal)));
}

void Receiver::setController(Controller* controller)
{
    disconnect(controller_, SIGNAL(flap()), this, SLOT(doFlap()));
    disconnect(this, SIGNAL(sendData(qreal, qreal, qreal, qreal)), controller_, SLOT(receiveData(qreal, qreal, qreal, qreal)));

    controller_ = controller;

    connect(controller_, SIGNAL(flap()), this, SLOT(doFlap()));
    connect(this, SIGNAL(sendData(qreal, qreal, qreal, qreal)), controller_, SLOT(receiveData(qreal, qreal, qreal, qreal)));
}
