#include "Game.hpp"

#include <QTransform>
#include <cstdlib>
#include <ctime>

#include "Constants.hpp"

GameLogic::Game::Game(Controller* controller)
    : Receiver(controller),
      bird_(Constants::BIRD_START_X, Constants::BIRD_START_Y,
            Constants::BIRD_WIDTH, Constants::BIRD_HEIGHT)
{

}

void GameLogic::Game::start()
{
    srand(time(NULL));

    bird_.shape.moveCenter(QPoint(Constants::BIRD_START_X, Constants::BIRD_START_Y));
    bird_.rotation = 0;

    pipes_.clear();
    pipes_.append(pgen_.generate());

    bird_ahead_ = false;
    gameover_ = false;

    score_ = 0;

    mainTimer_.start();
    hoverTimer_.start();
    birdState_ = GameLogic::HOVERING;
}

void GameLogic::Game::update()
{
    qreal dt = mainTimer_.restart() / 1000.;
    int flight_elapsed = flightTimer_.elapsed();
    int hover_elapsed = hoverTimer_.elapsed();
    QPointF bird_ct = bird_.shape.center();
    qreal bird_y = bird_ct.y();
    qreal bird_r = bird_.rotation;

    //pipe movement
    for(auto& p : pipes_)
        p.move(-dt * Constants::PIPE_SPEED);

    //remove pipes which have moved out of screen
    if(pipes_.front().lower.x() < -Constants::PIPE_WIDTH)
    {
        pipes_.removeFirst();
        bird_ahead_ = false;
    }

    //pipe generation
    if(Constants::SCREEN_WIDTH - Constants::PIPE_WIDTH - pipes_.back().lower.x() > Constants::PIPE_SPACE_BETWEEN)
        pipes_.append(pgen_.generate());

    //bird state machine
    if(birdState_ == GameLogic::FALLING)
    {
        bird_y += dt * Constants::FALLING_SPEED;

        bird_r += dt * Constants::BIRD_CW_ROTATION_SPEED;

        if(bird_r > Constants::CLOCKWISE_ROTATION_DEG)
            bird_r = Constants::CLOCKWISE_ROTATION_DEG;
    }

    else if(birdState_ == GameLogic::FLYING)
    {
        bird_y -= dt * Constants::FLIGHT_SPEED;

        bird_r -= dt * Constants::BIRD_CCW_ROTATION_SPEED;

        if(bird_r < Constants::COUNTERCLOCKWISE_ROTATION_DEG)
            bird_r = Constants::COUNTERCLOCKWISE_ROTATION_DEG;

        if(flight_elapsed > Constants::FLIGHT_DURATION_MSEC)
        {
            //hoverTimer_.restart();
            //birdState_ = GameLogic::HOVERING;

            birdState_ = GameLogic::FALLING;
        }
    }

    else if(birdState_ == GameLogic::HOVERING)
    {
        bird_r += dt * Constants::BIRD_HOVER_ROTATION_SPEED;

        if(hover_elapsed > Constants::HOVER_DURATION_MSEC)
            birdState_ = FALLING;
    }

    bird_ct.setY(bird_y);
    bird_.shape.moveCenter(bird_ct);

    //floor/ceiling collisions
    if(bird_.shape.bottom() > Constants::SCREEN_HEIGHT ||
       bird_.shape.top() < 0.)
        gameover_ = true;

    //pipe collision
    if(bird_ahead_)
    {
        if(bird_.shape.intersects(pipes_[1].upper) ||
           bird_.shape.intersects(pipes_[1].lower))
            gameover_ = true;
    }

    else
    {
        if(bird_.shape.left() > pipes_[0].lower.right())
        {
            bird_ahead_ = true;
            ++score_;
        }

        if(bird_.shape.intersects(pipes_.front().upper) ||
           bird_.shape.intersects(pipes_.front().lower))
            gameover_ = true;
    }

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

GameLogic::Pipe::Pipe(qreal hole_altitude)
{
    lower = QRectF(Constants::SCREEN_WIDTH, hole_altitude + Constants::PIPE_SPACING,
                   Constants::PIPE_WIDTH, Constants::SCREEN_HEIGHT - hole_altitude - Constants::PIPE_SPACING);

    upper = QRectF(Constants::SCREEN_WIDTH, 0.,
                   Constants::PIPE_WIDTH, hole_altitude);
}

void GameLogic::Pipe::move(qreal dx)
{
    upper.translate(dx, 0.);
    lower.translate(dx, 0.);
}

GameLogic::Pipe GameLogic::PipeGenerator::generate()
{
    return Pipe(rand() % (Constants::HOLE_MAX_ALT - Constants::HOLE_MIN_ALT)
                + Constants::HOLE_MIN_ALT);
}
