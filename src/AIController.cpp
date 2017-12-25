#include "AIController.hpp"

AIController::AIController()
{

}

void AIController::receiveData(qreal diff)
{
    //TODO add actual fuzzy controller
    if(diff < 0)
        emit flap();
}
