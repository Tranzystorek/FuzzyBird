#ifndef GAME_HPP
#define GAME_HPP

#include <QList>
#include <QRect>
#include "Receiver.hpp"

namespace GameLogic
{
struct Pipe
{
	QRect upper;
	QRect lower;
};

class Game : public Receiver
{
public:
	Game(Controller*);

public:
	void update();
	void doFlap() override;

	const QList<Pipe>& getPipes() const;

private:
	QList<Pipe> pipes_;
};
}

#endif // GAME_HPP
