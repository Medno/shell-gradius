#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AShips.hpp"

class	Player: public AShips {
public:
	Player( void );
	~Player( void );
	Player( Player const & src );
	Player &	operator=( Player const & );

	virtual AShips*	clone( void ) const;
	Player( t_vector const & );
	virtual void	fire( void );
//	virtual void	moveShots( void );

private:
};

#endif
