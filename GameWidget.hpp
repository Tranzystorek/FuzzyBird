#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <QWidget>

class GameWidget : public QWidget
{
	Q_OBJECT
public:
	explicit GameWidget(QWidget *parent = nullptr);

protected:
	void paintEvent(QPaintEvent*) override;

signals:

public slots:
};

#endif // GAMEWIDGET_HPP
