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

void		AShips::setCoordinates( t_vector const & coordinates ) {
	this->_coordinates = coordinates;
	return ;
}

t_vector	AShips::getCoordinates( void ) const {
	return this->_coordinates;
}

std::ostream & operator<<( std::ostream & o, AShips const & rhs ) {
	t_vector	coordinates;
	o << "Ship at coordinates : y: " << coordinates.y << ", x: " << coordinates.x << std::endl;
	return o;
}
