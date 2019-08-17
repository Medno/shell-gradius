#ifndef STARS_HPP
#define STARS_HPP

#include <iostream>
#include "AElement.hpp"
#include "defs.hpp"

class	Stars: public AElement {
	public:
		~Stars( void );
		Stars( Stars const &src );
		Stars &	operator=( Stars const & );

		Stars( t_vector const &coord );

		virtual AElement* clone( void ) const;

	protected:
		Stars( void );
};

#endif
