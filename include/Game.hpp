#ifndef GAME_HPP
#define GAME_HPP

#include <QList>
#include <QRectF>
#include <QPolygonF>
#include <QPointF>
#include <QElapsedTimer>
#include "Receiver.hpp"

namespace GameLogic
{
struct Pipe
{
    Pipe(qreal hole_altitude);

    void move(qreal dx);

    qreal hole_mid;

    QRectF upper;
    QRectF lower;
};

struct Bird
{
    Bird(qreal x, qreal y, qreal w, qreal h);

    QRectF shape;
    qreal rotation;
};

enum BirdState
{
    HOVERING,
    FLYING,
    FALLING
};

class PipeGenerator
{
public:
    Pipe generate();

private:
    qreal current_alt_;
};

class Game : public Receiver
{
public:
    Game(Controller*);

public:
    void start();
    void update();
    void doFlap() override;

    const Bird& getBird() const;
    const QList<Pipe>& getPipes() const;

    bool isOver() const {return gameover_;}
    int getScore() const {return score_;}

private:
    Bird bird_;
    BirdState birdState_;
    QList<Pipe> pipes_;
    PipeGenerator pgen_;

    bool bird_ahead_;
    bool gameover_;

    int score_;

    QElapsedTimer mainTimer_;
    QElapsedTimer flightTimer_;
    QElapsedTimer hoverTimer_;
};
}

#endif // GAME_HPP
