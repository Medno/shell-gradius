#include "Boss.hpp"

Boss::Boss( t_vector const & positions ) : Enemy( "Boss", positions ) {
//	std::cout << "Fighter, waiting for command" << std::endl;
}

Boss::~Boss( void ) {
//	std::cout << "Piouuuuuuuuuuupoc" << std::endl;
}

Boss::Boss( Boss const & src ) {
	*this = src;
	return ;
}

Boss &	Boss::operator=( Boss const & ) {
	return *this;
}

AShips*	Boss::clone( void ) const {
	return new Boss(*this);
}

void	Boss::fire( void ) {
//	std::cout << "* piou piou *" << std::endl;
}
