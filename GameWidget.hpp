#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>

#include "KeyboardController.hpp"

#include "Game.hpp"

class GameWidget : public QWidget
{
	Q_OBJECT
public:
    explicit GameWidget(QWidget* parent = nullptr);
	~GameWidget();

public:
	enum GameMode
	{
		PLAYER_MODE,
		AI_MODE
	};

public:
    void start();

protected:
	void paintEvent(QPaintEvent*) override;
	void keyPressEvent(QKeyEvent*) override;

private:
    KeyboardController kcontroller_;

private:
    QTimer updateTimer_;
    GameLogic::Game game_;

signals:

public slots:
	void updateGame();
};

#endif // GAMEWIDGET_HPP
