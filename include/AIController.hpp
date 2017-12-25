#ifndef AICONTROLLER_HPP
#define AICONTROLLER_HPP

#include "Controller.hpp"


class AIController : public Controller
{
public:
    AIController();

    void receiveData(qreal) override;
};

#endif // AICONTROLLER_HPP
