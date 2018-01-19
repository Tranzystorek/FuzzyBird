#ifndef AICONTROLLER_HPP
#define AICONTROLLER_HPP

#include "Controller.hpp"
#include "Engine.hpp"

#include <memory>

class AIController : public Controller
{
public:
    AIController();

    void receiveData(qreal, qreal, qreal, qreal) override;

private:

    std::unique_ptr<flogic::Engine> eng_;
    qreal altmin_;
};

#endif // AICONTROLLER_HPP
