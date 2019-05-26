#ifndef GAME_HPP
#define GAME_HPP

#include "defs.hpp"
#include "AShips.hpp"
#include <iostream>

typedef struct	s_ships {
	AShips*			ship;
	struct s_ships*	next;
}				t_ships;

class	Game {
public:
	Game( void );
	~Game( void );
	Game( Game const & src );
	Game &	operator=( Game const & src );

protected:
	t_ships*	ships;

private:
};

#endif
