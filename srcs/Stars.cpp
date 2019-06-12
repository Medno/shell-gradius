#include "Stars.hpp"

Stars::Stars( void ) {}
Stars::~Stars( void ) {}

Stars::Stars( t_vector const &coord ) : AElement( coord ) {
	// std::cout << "Stars has been created" << std::endl;
	return ;
}

Stars::Stars( Stars const & src ) {
	*this = src;
	return ;
}

Stars &	Stars::operator=( Stars const & ) {
	return *this;
}

AElement*	Stars::clone( void ) const {
	return new Stars(*this);
}

int			Stars::update( void ) {
	t_vector	positions;

	if (this->_positions.x > 1) {
		positions = this->_positions;
		positions.x -= 1;
		if (positions.x == 1)
			this->pop( this );
		else
			this->setPositions( positions );
	}
	return ( GAME_CONTINUE );
}
