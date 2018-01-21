#include "GameWidget.hpp"

#include <QPainter>
#include <QDebug>
#include <QSurfaceFormat>

#include "Constants.hpp"

GameWidget::GameWidget(QWidget* parent) : QOpenGLWidget(parent), game_(&kcontroller_)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window,
                 Constants::BACKGROUND_COLOR);
    setPalette(pal);
    setAutoFillBackground(true);

    qInfo().nospace() << "OpenGL Version: " << this->format().majorVersion()
                       << "." << this->format().minorVersion();

    if(this->format().swapInterval() != 1)
    {
        qWarning() << "Vertical sync not available, setting approximate 60Hz refresh rate";
        updateTimer_.setInterval(Constants::UPDATE_INTERVAL_MSEC);
    }

    setFixedSize(Constants::SCREEN_WIDTH,
                 Constants::SCREEN_HEIGHT);

    connect(&updateTimer_, SIGNAL(timeout()),
            this, SLOT(updateGame()));
}

GameWidget::~GameWidget()
{
}

void GameWidget::start(GameMode mode)
{
    gmode_ = mode;

    switch(gmode_)
    {
    case GameMode::PLAYER_MODE:
        game_.setController(&kcontroller_);
        break;

    case GameMode::AI_MODE:
        game_.setController(&aicontroller_);
        break;
    }

    game_.start();

    updateTimer_.start();
}

void GameWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    QPen pen(QBrush(Qt::black), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);

    //paint the pipes
    painter.setBrush(QBrush(Constants::PIPE_COLOR));

    auto& pipes = game_.getPipes();
    for(auto& p : pipes)
    {
        painter.drawRect(p.lower);
        painter.drawRect(p.upper);
    }

    //paint the bird
    painter.setBrush(QBrush(Constants::BIRD_COLOR));

    const GameLogic::Bird& bird = game_.getBird();
    const QPointF& bct = bird.shape.center();

    painter.save();
    painter.translate(bct);
    painter.rotate(bird.rotation);
    painter.translate(-bct.x(), -bct.y());
    painter.drawRect(bird.shape);
    painter.restore();

#ifdef QT_DEBUG
    painter.save();
    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::red);
    painter.drawRect(bird.shape);
    painter.restore();
#endif

    //paint game score
    painter.setPen(QPen(Constants::SCORE_COLOR));
    painter.setFont(Constants::SCORE_FONT);

    painter.drawText(Constants::SCORE_X, Constants::SCORE_Y,
                     QString::number(game_.getScore()));
}

void GameWidget::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Escape)
    {
        updateTimer_.stop();

        emit returnToMenu();
    }

    else if(gmode_ == GameMode::PLAYER_MODE &&
            event->key() == Qt::Key_Space &&
            !event->isAutoRepeat())
    {
        emit kcontroller_.flap();
    }
}

void GameWidget::updateGame()
{
    game_.update();
    update();

    if(game_.isOver())
    {
        updateTimer_.stop();

        emit gameOver();
    }
}
