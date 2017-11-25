#include "MainWindow.hpp"

#include <QStackedWidget>
#include "MenuWidget.hpp"
#include "GameWidget.hpp"

#include "Constants.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setFixedSize(Constants::SCREEN_WIDTH,
                 Constants::SCREEN_HEIGHT);

    MenuWidget* menu = new MenuWidget;
    GameWidget* game = new GameWidget;

    manager_ = new QStackedWidget;
    menuIndex_ = manager_->addWidget(menu);
    gameIndex_ = manager_->addWidget(game);

    setCentralWidget(manager_);

    connect(menu, SIGNAL(playerButtonClicked()),
            this, SLOT(startPlayerGame()));
    connect(menu, SIGNAL(aiButtonClicked()),
            this, SLOT(startAiGame()));
    connect(menu, SIGNAL(quitButtonClicked()),
            this, SLOT(close()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::startPlayerGame()
{
    manager_->setCurrentIndex(gameIndex_);
    ((GameWidget*)(manager_->currentWidget()))->start();
}

void MainWindow::startAiGame()
{

}
