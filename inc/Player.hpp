#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AShips.hpp"

class	Player: public AShips {
public:
	Player( void );
	~Player( void );
	Player( Player const & src );
	Player &	operator=( Player const & );

	Player( t_vector const & );
	void	fire( void );

private:
};

#endif
