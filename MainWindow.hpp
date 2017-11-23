#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void startPlayerGame();
	void startAiGame();

private:
	QStackedWidget* manager_;

	int menuIndex_;
	int gameIndex_;
};

#endif // MAINWINDOW_HPP
