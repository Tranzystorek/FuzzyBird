#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>

class GameWidget : public QWidget
{
	Q_OBJECT
public:
	explicit GameWidget(QWidget *parent = nullptr);
	~GameWidget();

public:
	enum GameMode
	{
		PLAYER_MODE,
		AI_MODE
	};

protected:
	void paintEvent(QPaintEvent*) override;
	void keyPressEvent(QKeyEvent*) override;

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
