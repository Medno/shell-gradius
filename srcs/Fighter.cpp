#include "Fighter.hpp"

Fighter::Fighter( void ) : Enemy( "Fighter" ) {
	std::cout << "Fighter, waiting for command" << std::endl;
}

Fighter::~Fighter( void ) {
	std::cout << "Piouuuuuuuuuuupoc" << std::endl;
}

Fighter::Fighter( Fighter const & src ) {
	*this = src;
	return ;
}

Fighter &	Fighter::operator=( Fighter const & ) {
	return *this;
}

void	Fighter::fire( void ) {
	std::cout << "* piou piou *" << std::endl;
}
