#ifndef KEYBOARDCONTROLLER_HPP
#define KEYBOARDCONTROLLER_HPP

#include "Controller.hpp"

class KeyboardController : public Controller
{
public:
    KeyboardController();

    void receiveData() override;
};

#endif // KEYBOARDCONTROLLER_HPP
