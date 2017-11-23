#ifndef GAME_HPP
#define GAME_HPP

#include "Receiver.hpp"

class Game : public Receiver
{
public:
	Game(Controller*);
};

#endif // GAME_HPP
