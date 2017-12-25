#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <QColor>
#include <QFont>

namespace Constants
{
const QColor BIRD_COLOR = QColor(253, 231, 50);
const QColor PIPE_COLOR = QColor(96, 181, 34);
const QColor BACKGROUND_COLOR = QColor(111, 198, 207);
const QColor SCORE_COLOR = Qt::darkMagenta;

const QFont SCORE_FONT = QFont("Arial Black", 48, QFont::Bold);

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int SCORE_X = 20;
const int SCORE_Y = 70;

const int FPS = 60;
const int UPDATE_INTERVAL_MSEC = 1000 / FPS;

const int FLIGHT_DURATION_MSEC = 230;
const int HOVER_DURATION_MSEC = 150;

//bird simulates jumping in the air with time-based slowdown
//this constant makes up for down-pull effects resulting from this mechanics
const qreal SLOWDOWN_LIMITER = 2.;

const qreal PIPE_SPACE_BETWEEN = 240.;
const qreal PIPE_SPEED = 200.;

const qreal FALLING_SPEED = 400.;
const qreal FLIGHT_SPEED = 350.;

const qreal CLOCKWISE_ROTATION_DEG = 45.;
const qreal COUNTERCLOCKWISE_ROTATION_DEG = -40.;

const qreal BIRD_WIDTH = 40.;
const qreal BIRD_HEIGHT = 30.;
const qreal BIRD_START_X = SCREEN_WIDTH / 4;
const qreal BIRD_START_Y = SCREEN_HEIGHT / 2;

const qreal BIRD_CCW_ROTATION_SPEED = 400.;
const qreal BIRD_CW_ROTATION_SPEED = 200.;
const qreal BIRD_HOVER_ROTATION_SPEED = 200.;

const qreal PIPE_WIDTH = 80.;
const qreal PIPE_SPACING = 180.;

const int HOLE_MIN_ALT = Constants::SCREEN_HEIGHT / 10;
const int HOLE_MAX_ALT = 9 * Constants::SCREEN_HEIGHT / 10 - Constants::PIPE_SPACING;
}

#endif // CONSTANTS_HPP
