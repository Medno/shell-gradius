#ifndef ASHIPS_HPP
#define ASHIPS_HPP

#include <iostream>
#include "defs.hpp"


class	AShips {
public:
	virtual ~AShips( void ) {}
	AShips( AShips const & src );
	AShips &	operator=( AShips const & src );

	AShips( t_vector const & );

	t_vector		getCoordinates( void ) const;
	virtual void	fire( void ) = 0;

protected:
	AShips( void );
	t_vector	_coordinates;

};

#endif
