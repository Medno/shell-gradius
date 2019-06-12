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

AElement*	Boss::clone( void ) const {
	return new Boss(*this);
}

void	Boss::fire( void ) {
//	std::cout << "* piou piou *" << std::endl;
}

int		Boss::update( void ) {
	t_vector	positionsBoss;
	t_vector	positionsPlayer = this->_ships->ship->getPositions();

	positionsBoss = this->getPositions();
	if (positionsBoss.x > positionsPlayer.x + 50)
		positionsBoss.x -= 1;
	else if (positionsBoss.x < positionsPlayer.x + 20 &&
		positionsBoss.x < this->_wSize.x - 1)
		positionsBoss.x += 1;
	if (positionsBoss.y > positionsPlayer.y)
		positionsBoss.y -= 1;
	else if (positionsBoss.y < positionsPlayer.y)
		positionsBoss.y += 1;
	if ( positionsBoss.x == 1 )
		this->pop( this );
	else
		this->setPositions( positionsBoss );
	return (1);
}
