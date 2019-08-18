#include "Boss.hpp"

Boss::Boss( t_vector const & positions ) : Enemy( "Boss", positions ) {}
Boss::~Boss( void ) {}
Boss::Boss( Boss const & src ) { *this = src; }
Boss &	Boss::operator=( Boss const & ) { return *this; }

AElement*	Boss::clone( void ) const {
	return new Boss(*this);
}
void	Boss::fire( void ) {}

int		Boss::update( void ) {
	t_vector	positionsPlayer = this->getPlayer()->getPositions();
	t_vector	positionsBoss;

	positionsBoss = this->positions;
	if (positionsBoss.x > positionsPlayer.x + 50)
		positionsBoss.x -= 1;
	else if (positionsBoss.x < positionsPlayer.x + 20 &&
		positionsBoss.x < this->wSize.x - 1)
		positionsBoss.x += 1;
	if (positionsBoss.y > positionsPlayer.y)
		positionsBoss.y -= 1;
	else if (positionsBoss.y < positionsPlayer.y)
		positionsBoss.y += 1;
	this->setPositions( positionsBoss );
	return (1);
}
