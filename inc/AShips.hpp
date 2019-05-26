#ifndef ASHIPS_HPP
#define ASHIPS_HPP

#include <iostream>
#include "defs.hpp"

class	AShips {
public:
	virtual ~AShips( void ) {}
	AShips( AShips const & src );
	AShips &	operator=( AShips const & src );

	AShips( std::string const &, t_vector const & );

	void			setPositions( t_vector const & );
	t_vector		getPositions( void ) const;
	std::string		getType( void ) const;
	virtual void	fire( void ) = 0;

protected:
	AShips( void );
	std::string	_type;
	t_vector	_positions;

};

std::ostream & operator<<( std::ostream & o, AShips const & rhs );

#endif
