#include "AShips.hpp"

AShips::AShips( void ) {}

AShips::AShips( std::string const & type, t_vector const & coord ) : _type(type), _positions( coord ) {
//	std::cout << "AShips has been created" << std::endl;
	return ;
}

AShips::AShips( AShips const & src ) {
	*this = src;
	return ;
}

AShips &	AShips::operator=( AShips const & rhs ) {
	if ( this != &rhs ) {
		this->_positions = rhs.getPositions();
	}
	return *this;
}

void		AShips::setPositions( t_vector const & positions ) {
	this->_positions = positions;
	return ;
}

t_vector	AShips::getPositions( void ) const {
	return this->_positions;
}

std::string	AShips::getType( void ) const {
	return this->_type;
}

std::ostream & operator<<( std::ostream & o, AShips const & rhs ) {
	t_vector	positions = rhs.getPositions();
	o << rhs.getType() << " at positions : y: " << positions.y << ", x: " << positions.x << std::endl;
	return o;
}
