#include "Receiver.hpp"

Receiver::Receiver(Controller* controller, QObject *parent) : QObject(parent)
{
	controller_ = controller;

	connect(controller_, SIGNAL(flap()), this, SLOT(doFlap()));
}
