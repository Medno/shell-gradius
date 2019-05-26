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
	static void		moveShots( void );
	static void		setShots( t_shots * const & );
	static t_shots*	getShots( void );
	static void		popBordersShots( t_vector const & );
	static void		popShots( void );
	static t_shots*	popShot( t_shots * & shot );
	static bool		checkShotPosition( t_shots * const & shot, int const & x );
	static bool		checkShotPosition( t_shots * const & shot, t_vector const & pos );

protected:
	AShips( void );
	std::string		_type;
	t_vector		_positions;
	static t_shots*	_shots;
private:
};

std::ostream & operator<<( std::ostream & o, AShips const & rhs );

#endif
