#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "AShips.hpp"

class	Enemy: public AShips {
public:
	~Enemy( void );
	Enemy( Enemy const & src);
	Enemy &	operator=( Enemy const & rhs );

	Enemy( std::string const &, t_vector const & );

	virtual void	fire( void ) = 0;
//	virtual void	moveShots( void );
	void	spawn( void );

protected:
	Enemy( void );		// Create a random type enemy ?

private:
};

#endif
