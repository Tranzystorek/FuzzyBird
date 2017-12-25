#include "MainWindow.hpp"

#include <QStackedWidget>
#include "MenuWidget.hpp"
#include "GameWidget.hpp"
#include "GameOverWidget.hpp"

#include "Constants.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setFixedSize(Constants::SCREEN_WIDTH,
                 Constants::SCREEN_HEIGHT);

    MenuWidget* menu = new MenuWidget;
    GameWidget* game = new GameWidget;
    GameOverWidget* gameover = new GameOverWidget;

    manager_ = new QStackedWidget;
    menuIndex_ = manager_->addWidget(menu);
    gameIndex_ = manager_->addWidget(game);
    goIndex_ = manager_->addWidget(gameover);

    setCentralWidget(manager_);

    connect(menu, SIGNAL(playerButtonClicked()),
            this, SLOT(startPlayerGame()));
    connect(menu, SIGNAL(aiButtonClicked()),
            this, SLOT(startAiGame()));
    connect(menu, SIGNAL(quitButtonClicked()),
            this, SLOT(close()));

    connect(game, SIGNAL(gameOver()),
            this, SLOT(showGameOver()));

    connect(gameover, SIGNAL(retryButtonClicked()),
            this, SLOT(startLastGameType()));
    connect(gameover, SIGNAL(backButtonClicked()),
            this, SLOT(goBackToMenu()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::startPlayerGame()
{
    lastGameMode_ = GameWidget::PLAYER_MODE;

    manager_->setCurrentIndex(gameIndex_);
    ((GameWidget*)(manager_->currentWidget()))->start(GameWidget::PLAYER_MODE);
}

void MainWindow::startAiGame()
{
    lastGameMode_ = GameWidget::AI_MODE;

    manager_->setCurrentIndex(gameIndex_);
    ((GameWidget*)(manager_->currentWidget()))->start(GameWidget::AI_MODE);
}

void MainWindow::startLastGameType()
{
    switch(lastGameMode_)
    {
    case GameWidget::PLAYER_MODE:
        startPlayerGame();
        break;

    case GameWidget::AI_MODE:
        startAiGame();
        break;
    }
}

void MainWindow::showGameOver()
{
    GameOverWidget* w = (GameOverWidget*)(manager_->widget(goIndex_));
    GameWidget* gw = (GameWidget*)(manager_->widget(gameIndex_));
    w->show(gw->getGameScore());

    manager_->setCurrentIndex(goIndex_);
}

void MainWindow::goBackToMenu()
{
    manager_->setCurrentIndex(menuIndex_);
}
