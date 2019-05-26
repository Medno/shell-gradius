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

AShips*	Fighter::clone( void ) const {
	return new Fighter(*this);
}
