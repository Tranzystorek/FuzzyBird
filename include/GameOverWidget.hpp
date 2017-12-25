#ifndef GAMEOVERWIDGET_HPP
#define GAMEOVERWIDGET_HPP

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class GameOverWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameOverWidget(QWidget *parent = nullptr);
    ~GameOverWidget();

    void show(int score);

private:
    QLabel* scoreLabel;
    QPushButton* retryButton;
    QPushButton* backButton;

signals:
    void retryButtonClicked();
    void backButtonClicked();

public slots:
};

#endif // GAMEOVERWIDGET_HPP
