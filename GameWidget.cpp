#include "GameWidget.hpp"

#define FPS 30
#define FPS_MILISECOND_INTERVAL (1000 / FPS)

#include <QPainter>

const QColor GameWidget::birdColor = QColor(253, 231, 50);
const QColor GameWidget::pipeColor = QColor(96, 181, 34);
const QColor GameWidget::backgroundColor = QColor(111, 198, 207);

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
	updateTimer = new QTimer();

	QPalette pal = palette();
	pal.setColor(QPalette::Background, backgroundColor);
	setPalette(pal);

	setAutoFillBackground(true);

	//TODO Game

	connect(updateTimer, SIGNAL(timeout()),
			this, SLOT(updateGame()));

	//TODO need a separate init method for this
	updateTimer->start(FPS_MILISECOND_INTERVAL);
}

GameWidget::~GameWidget()
{
	delete updateTimer;
}

void GameWidget::paintEvent(QPaintEvent* event)
{
	//to disable "unused" warnings temporarily
	(void)event;

	QPainter painter(this);
}

void GameWidget::updateGame()
{
	//TODO add game logic update here

	update();
}
