#include "MenuWidget.hpp"

#include <QVBoxLayout>

MenuWidget::MenuWidget(QWidget* parent) : QWidget(parent)
{
    playerButton = new QPushButton("Play");
    aiButton = new QPushButton("AI Controlled");
    quitButton = new QPushButton("Quit");

    QVBoxLayout* mainLayout = new QVBoxLayout;

    mainLayout->addWidget(playerButton);
    mainLayout->addWidget(aiButton);
    mainLayout->addWidget(quitButton);

    setLayout(mainLayout);

    connect(playerButton, SIGNAL(clicked()),
            this, SIGNAL(playerButtonClicked()));
    connect(aiButton, SIGNAL(clicked()),
            this, SIGNAL(aiButtonClicked()));
    connect(quitButton, SIGNAL(clicked()),
            this, SIGNAL(quitButtonClicked()));
}

MenuWidget::~MenuWidget()
{
    delete quitButton;
    delete aiButton;
    delete playerButton;
}
