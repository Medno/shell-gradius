#ifndef ASHIPS_HPP
#define ASHIPS_HPP

#include <iostream>
#include "AElement.hpp"
#include "defs.hpp"

class	AShips: public AElement {
public:
	virtual ~AShips( void ) {}
	AShips( AShips const & src );
	AShips &	operator=( AShips const & src );

	AShips( std::string const &, t_vector const & );

	std::string		getType( void ) const;
	virtual void	fire( void ) = 0;
	static void		moveShots( void );
	static void		setShots( t_shots * const & );
	static t_shots*	getShots( void );
	static void		popShots( void );
	static t_shots*	popShot( t_shots * & shot );
	static bool		checkShotPosition( t_shots * const & shot, int const & x );
	static bool		checkShotPosition( t_shots * const & shot, t_vector const & pos );

	static void		popBordersShots( t_vector const & );

	virtual AShips*	clone( void ) const = 0;

protected:
	AShips( void );
	std::string		_type;
	static t_shots*	_shots;
private:
};

std::ostream & operator<<( std::ostream & o, AShips const & rhs );

#endif
