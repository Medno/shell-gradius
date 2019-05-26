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
