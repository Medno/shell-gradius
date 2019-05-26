#include "Stars.hpp"

Stars::Stars( void ) {}

Stars::Stars( t_vector const &coord ) : _coordinates( coord ) {
	// std::cout << "Stars has been created" << std::endl;
	return ;
}

Stars::Stars( Stars const & src ) {
	*this = src;
	return ;
}

Stars &	Stars::operator=( Stars const & rhs ) {
	if ( this != &rhs ) {
		this->_coordinates = rhs.getCoordinates();
	}
	return *this;
}

void		Stars::setCoordinates( t_vector const &coord ) {
	this->_coordinates = coord;
	return ;
}
t_vector	Stars::getCoordinates( void ) const {
	return this->_coordinates;
}
