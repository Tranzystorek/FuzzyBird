#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>

#include "GameWidget.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();

public slots:
    void startPlayerGame();
    void startAiGame();
    void startLastGameType();
    void showGameOver();
    void goBackToMenu();

private:
    QStackedWidget* manager_;

    int menuIndex_;
    int gameIndex_;
    int goIndex_;

    GameWidget::GameMode lastGameMode_;
};

#endif // MAINWINDOW_HPP
