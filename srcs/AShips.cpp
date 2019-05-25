#include "AShips.hpp"

AShips::AShips( void ) {}

AShips::AShips( t_vector const & coord ) : _coordinates( coord ) {
	std::cout << "AShips has been created" << std::endl;
	return ;
}

AShips::AShips( AShips const & src ) {
	*this = src;
	return ;
}

AShips &	AShips::operator=( AShips const & rhs ) {
	if ( this != &rhs ) {
		this->_coordinates = rhs.getCoordinates();
	}
	return *this;
}

t_vector	AShips::getCoordinates( void ) const {
	return this->_coordinates;
}
