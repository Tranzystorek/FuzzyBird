#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <QColor>

namespace Constants
{
const QColor BIRD_COLOR = QColor(253, 231, 50);
const QColor PIPE_COLOR = QColor(96, 181, 34);
const QColor BACKGROUND_COLOR = QColor(111, 198, 207);

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int FPS = 30;
const int UPDATE_INTERVAL_MSEC = 1000 / FPS;

const int FLIGHT_DURATION_MSEC = 100;
const int HOVER_DURATION_MSEC = 40;

const qreal FALLING_SPEED = 700.;
const qreal FLIGHT_SPEED = 1500.;

const qreal CLOCKWISE_ROTATION_DEG = 45.;
const qreal COUNTERCLOCKWISE_ROTATION_DEG = -40.;

const qreal BIRD_WIDTH = 60.;
const qreal BIRD_HEIGHT = 50.;
const qreal BIRD_START_X = SCREEN_WIDTH / 4;
const qreal BIRD_START_Y = SCREEN_HEIGHT / 2;

const qreal BIRD_CCW_ROTATION_SPEED = 700.;
const qreal BIRD_CW_ROTATION_SPEED = 300.;
const qreal BIRD_HOVER_ROTATION_SPEED = 200.;

const qreal PIPE_WIDTH = 80.;
const qreal PIPE_SPACING = 180.;
}

#endif // CONSTANTS_HPP
