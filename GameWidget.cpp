#include "GameWidget.hpp"

#define FPS_INTERVAL 33
#include <QPainter>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
	updateTimer = new QTimer();

	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);

	setAutoFillBackground(true);

	//TDOD Game

	connect(updateTimer, SIGNAL(timeout()),
			this, SLOT(update()));

	updateTimer->start(FPS_INTERVAL);
}

GameWidget::~GameWidget()
{
	delete updateTimer;
}

void GameWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
}
