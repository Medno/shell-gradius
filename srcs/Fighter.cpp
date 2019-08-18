#include "Fighter.hpp"

Fighter::Fighter( t_vector const & positions ) : Enemy( "Fighter", positions ) {}
Fighter::~Fighter( void ) {}
Fighter::Fighter( Fighter const & src ) { *this = src; }
Fighter &	Fighter::operator=( Fighter const & ) { return *this; }

AElement*	Fighter::clone( void ) const {
	return new Fighter(*this);
}
void	Fighter::fire( void ) {}
