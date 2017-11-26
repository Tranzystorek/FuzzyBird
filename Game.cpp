#include "Game.hpp"

#include <QTransform>

#include "Constants.hpp"

GameLogic::Game::Game(Controller* controller)
    : Receiver(controller),
      bird_(Constants::BIRD_START_X, Constants::BIRD_START_Y,
            Constants::BIRD_WIDTH, Constants::BIRD_HEIGHT)
{

}

void GameLogic::Game::start()
{
    mainTimer_.start();
    hoverTimer_.start();
    birdState_ = GameLogic::HOVERING;
}

void GameLogic::Game::update()
{
    qreal dt = mainTimer_.restart() / 1000.;
    QPointF bird_ct = bird_.shape.center();
    qreal bird_y = bird_ct.y();
    qreal bird_r = bird_.rotation;

    if(birdState_ == GameLogic::FALLING)
    {
        //TODO falling logic
        bird_y += dt * Constants::FALLING_SPEED;

        bird_r += dt * Constants::BIRD_CW_ROTATION_SPEED;

        if(bird_r > Constants::CLOCKWISE_ROTATION_DEG)
            bird_r = Constants::CLOCKWISE_ROTATION_DEG;
    }

    else if(birdState_ == GameLogic::FLYING)
    {
        //TODO upflight logic
        bird_y -= dt * Constants::FLIGHT_SPEED;

        bird_r -= dt * Constants::BIRD_CCW_ROTATION_SPEED;

        if(bird_r < Constants::COUNTERCLOCKWISE_ROTATION_DEG)
            bird_r = Constants::COUNTERCLOCKWISE_ROTATION_DEG;

        if(flightTimer_.elapsed() > Constants::FLIGHT_DURATION_MSEC)
        {
            hoverTimer_.restart();
            birdState_ = GameLogic::HOVERING;
        }
    }

    else if(birdState_ == GameLogic::HOVERING)
    {
        bird_r += dt * Constants::BIRD_HOVER_ROTATION_SPEED;

        if(hoverTimer_.elapsed() > Constants::HOVER_DURATION_MSEC)
            birdState_ = FALLING;
    }

    bird_ct.setY(bird_y);
    bird_.shape.moveCenter(bird_ct);

    bird_.rotation = bird_r;
}

void GameLogic::Game::doFlap()
{
    flightTimer_.start();
    birdState_ = GameLogic::FLYING;
}

const GameLogic::Bird& GameLogic::Game::getBird() const
{
    return bird_;
}

const QList<GameLogic::Pipe>& GameLogic::Game::getPipes() const
{
    return pipes_;
}

GameLogic::Bird::Bird(qreal x, qreal y, qreal w, qreal h)
    : shape(x-w/2, y-w/2, w, h),
      rotation(0.)
{

}
