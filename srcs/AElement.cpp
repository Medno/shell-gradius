#include "AElement.hpp"

AElement::AElement( void ) {}
AElement::AElement( t_vector const & pos ) : _positions(pos) {}
AElement::~AElement( void ) {}

AElement::AElement( AElement const & src ) {
	*this = src;
	return ;
}

AElement &	AElement::operator=( AElement const & rhs ) {
	if (this != &rhs) {
		this->_positions = rhs.getPositions();
	}
	return *this;
}

t_vector	AElement::getPositions( void ) const {
	return this->_positions;
}

void		AElement::setPositions( t_vector const & positions ) {
	this->_positions = positions;
	return ;
}
