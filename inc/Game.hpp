#ifndef GAME_HPP
#define GAME_HPP

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

	void	updateCoordinates( void );

	t_vector*	getShips( void ) const;

protected:
	t_ships*	ships;
	int			count;

private:
};

#endif
