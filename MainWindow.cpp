#include "MainWindow.hpp"

#include <QStackedWidget>
#include "MenuWidget.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	MenuWidget* menu = new MenuWidget;

	QStackedWidget* manager = new QStackedWidget;
	manager->addWidget(menu);

	setCentralWidget(manager);

	connect(menu, SIGNAL(quitButtonClicked()),
			this, SLOT(close()));
}

MainWindow::~MainWindow()
{

}
