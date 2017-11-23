#include "GameWidget.hpp"

#include <QPainter>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{

}

void GameWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
}
