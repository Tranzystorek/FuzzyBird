#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <QWidget>
#include <QTimer>

class GameWidget : public QWidget
{
	Q_OBJECT
public:
	explicit GameWidget(QWidget *parent = nullptr);
	~GameWidget();

protected:
	void paintEvent(QPaintEvent*) override;

private:
	QTimer* updateTimer;

signals:

public slots:
};

#endif // GAMEWIDGET_HPP
