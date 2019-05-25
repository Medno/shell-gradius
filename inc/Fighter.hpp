#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include "Enemy.hpp"
#include <iostream>

/*
 * Basic ship: weak, small
*/ 

class Fighter: public Enemy {
public:
	Fighter( void );
	~Fighter( void );
	Fighter( Fighter const & src );
	Fighter &	operator=( Fighter const & );

	void	fire( void );

private:
};

#endif
