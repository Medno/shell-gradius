#ifndef ASHIPS_HPP
#define ASHIPS_HPP

#include <iostream>
#include "AElement.hpp"
#include "defs.hpp"

enum entity { PLAYER, ENEMY };

class	AShips: public AElement {
public:
	virtual ~AShips( void ) {}
	AShips( AShips const & src );
	AShips &	operator=( AShips const & src );

	typedef std::pair<entity, t_vector>	shot;

	AShips( std::string const &, t_vector const & );

	std::string		getType( void ) const;
	virtual void	fire( void ) = 0;
	static bool		checkShotPosition( AShips::shot const & shot, int const & x );
	static bool		checkShotPosition( AShips::shot const & shot, t_vector const & pos );

	static void		pushShot( entity ent, t_vector position );
	static void		popShot( int );
	static void		moveShots( void );
	static std::vector<AShips::shot>	getShots( void );

	static void		popBordersShots( t_vector const & );

	virtual AElement*	clone( void ) const = 0;

protected:
	AShips( void );

	std::string		type;
	static std::vector<AShips::shot>	shots;
};

std::ostream & operator<<( std::ostream & o, AShips const & rhs );

#endif
