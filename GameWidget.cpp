#include "GameWidget.hpp"

#include <QPainter>

#include "Constants.hpp"

GameWidget::GameWidget(QWidget* parent) : QWidget(parent), game_(&kcontroller_)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background,
                 Constants::BACKGROUND_COLOR);
    setPalette(pal);
    setAutoFillBackground(true);

    setFixedSize(Constants::SCREEN_WIDTH,
                 Constants::SCREEN_HEIGHT);

    //TODO Game

    connect(&updateTimer_, SIGNAL(timeout()),
            this, SLOT(updateGame()));

    //TODO need a separate init method for this
    //updateTimer_.start(Constants::UPDATE_INTERVAL_MSEC);
}

GameWidget::~GameWidget()
{
}

void GameWidget::start()
{
    game_.start();

    updateTimer_.start(Constants::UPDATE_INTERVAL_MSEC);
}

void GameWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    QPen pen(QBrush(Qt::black), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(QBrush(Constants::BIRD_COLOR));
    painter.drawConvexPolygon(game_.getBird().shape);
}

void GameWidget::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Space)
    {
        emit kcontroller_.flap();
    }
}

void GameWidget::updateGame()
{
    game_.update();

    update();
}
