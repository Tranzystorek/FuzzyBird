#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <QWidget>
#include <QTimer>

class GameWidget : public QWidget
{
	Q_OBJECT
public:
	explicit GameWidget(QWidget *parent = nullptr);
	~GameWidget();

protected:
	void paintEvent(QPaintEvent*) override;

private:
	QTimer* updateTimer;

signals:

public slots:
	void updateGame();

public:
	static const QColor birdColor;
	static const QColor pipeColor;
	static const QColor backgroundColor;
};

#endif // GAMEWIDGET_HPP
