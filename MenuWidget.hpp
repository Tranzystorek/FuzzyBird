#ifndef MENUWIDGET_HPP
#define MENUWIDGET_HPP

#include <QWidget>
#include <QPushButton>

class MenuWidget : public QWidget
{
	Q_OBJECT
public:
	explicit MenuWidget(QWidget *parent = nullptr);
	~MenuWidget();

private:
	QPushButton* playerButton;
	QPushButton* aiButton;
	QPushButton* quitButton;

signals:
	void playerButtonClicked();
	void aiButtonClicked();
	void quitButtonClicked();

public slots:
};

#endif // MENUWIDGET_HPP
