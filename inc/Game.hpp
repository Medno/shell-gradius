#ifndef GAME_HPP
#define GAME_HPP

//#include "Player.hpp"
//#include "Enemy.hpp"


#include <iostream>
typedef struct	s_vector {
	int	x;
	int	y;
}				t_vector;

class	Game {
public:
	Game( void );
	~Game( void );
	Game( Game const & src );
	Game &	operator=( Game const & src );

protected:
//	Player*			player;
//	Enemy*			enemies;
	t_vector*	coordinates;

	private:
};

#endif
