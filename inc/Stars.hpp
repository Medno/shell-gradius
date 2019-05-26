#ifndef STARS_HPP
#define STARS_HPP

#include <iostream>
#include "defs.hpp"
#include <vector>

class	Stars
{
	public:
		virtual ~Stars( void ) {}
		Stars( Stars const &src );
		Stars &	operator=( Stars const &src );
		Stars( t_vector const &coord );

		t_vector		getCoordinates( void ) const;
		void			setCoordinates( t_vector const &coord);

	protected:
		Stars( void );
		t_vector	_coordinates;

};

#endif
