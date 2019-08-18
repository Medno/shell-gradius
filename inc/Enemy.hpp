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

protected:
	Enemy( void );

private:
};

#endif
