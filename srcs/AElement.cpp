#include "AElement.hpp"

AElement::AElement( void ) {}
AElement::AElement( t_vector const & pos ) : positions(pos) {}
AElement::~AElement( void ) {}

AElement::AElement( AElement const & src ) {
	*this = src;
	return ;
}

AElement &	AElement::operator=( AElement const & rhs ) {
	if (this != &rhs) {
		this->positions = rhs.getPositions();
	}
	return *this;
}

t_vector	AElement::getPositions( void ) const {
	return this->positions;
}

void		AElement::setPositions( t_vector const & positions ) {
	this->positions = positions;
	return ;
}

int	AElement::update( void ) {
	t_vector	positions;

	positions = this->positions;
	positions.x -= 1;
	this->setPositions( positions );
	return ( GAME_CONTINUE );
}
