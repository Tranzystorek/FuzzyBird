#ifndef GAME_HPP
#define GAME_HPP

#include <QList>
#include <QRect>
#include <QTime>
#include "Receiver.hpp"

namespace GameLogic
{
struct Pipe
{
    QRect upper;
    QRect lower;
};

enum BirdState
{
    STILL,
    FLYING,
    FALLING
};

class Game : public Receiver
{
public:
    Game(Controller*);

public:
    void update();
    void doFlap() override;

    const QList<Pipe>& getPipes() const;

private:
    QRect bird_;
    BirdState birdState_;
    QList<Pipe> pipes_;

    QTime mainTimer_;
    QTime flightTimer_;
};
}

#endif // GAME_HPP
