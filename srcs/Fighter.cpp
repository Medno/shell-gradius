#include "Fighter.hpp"

Fighter::Fighter( t_vector const & positions ) : Enemy( "Fighter", positions ) {
//	std::cout << "Fighter, waiting for command" << std::endl;
}

Fighter::~Fighter( void ) {
//	std::cout << "Piouuuuuuuuuuupoc" << std::endl;
}

Fighter::Fighter( Fighter const & src ) {
	*this = src;
	return ;
}

Fighter &	Fighter::operator=( Fighter const & ) {
	return *this;
}

void	Fighter::fire( void ) {
//	std::cout << "* piou piou *" << std::endl;
}

AElement*	Fighter::clone( void ) const {
	return new Fighter(*this);
}

int	Fighter::update( void ) {
	t_vector	positions;

	positions = this->positions;
	positions.x -= 1;
	if ( positions.x == 1 )
		this->pop( this );
	else
		this->setPositions( positions );
	return ( GAME_CONTINUE );
}
