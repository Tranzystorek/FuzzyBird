#include "Game.hpp"

GameLogic::Game::Game(Controller* controller) : Receiver(controller)
{

}

void GameLogic::Game::update()
{

}

void GameLogic::Game::doFlap()
{

}

const QList<GameLogic::Pipe> &GameLogic::Game::getPipes() const
{
    return pipes_;
}
