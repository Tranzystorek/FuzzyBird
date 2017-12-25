#include "GameOverWidget.hpp"

#include "Constants.hpp"
#include <QVBoxLayout>

GameOverWidget::GameOverWidget(QWidget *parent) : QWidget(parent)
{
    scoreLabel = new QLabel;
    scoreLabel->setAlignment(Qt::AlignHCenter);
    scoreLabel->setFont(Constants::SCORE_FONT);

    retryButton = new QPushButton("Retry");
    backButton = new QPushButton("Back To Menu");

    QVBoxLayout* mainLayout = new QVBoxLayout;

    mainLayout->addWidget(scoreLabel);
    mainLayout->addWidget(retryButton);
    mainLayout->addWidget(backButton);

    setLayout(mainLayout);

    connect(retryButton, SIGNAL(clicked()),
            this, SIGNAL(retryButtonClicked()));
    connect(backButton, SIGNAL(clicked()),
            this, SIGNAL(backButtonClicked()));
}

GameOverWidget::~GameOverWidget()
{
    delete backButton;
    delete retryButton;
    delete scoreLabel;
}

void GameOverWidget::show(int score)
{
    scoreLabel->setText(QString("Your score: ") + QString::number(score));
}
