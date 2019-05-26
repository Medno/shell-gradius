#include "Game.hpp"

Game::Game( void ) : ships( NULL ) {}
Game::~Game( void ) {
	t_ships*	tmp = this->ships;

	if (tmp) {
		this->ships = this->ships->next;
		delete tmp->ship;
		delete tmp;
		tmp = this->ships;
	}
	return ;
}

Game::Game( Game const & src ) {
	*this = src;
	return ;
}

Game &	Game::operator=( Game const & rhs ) {
	if ( this != &rhs ) {
	}
	return *this;
}

void		Game::setTime(int time)
{
	this->_time = time;
	return ;
}
int			Game::getTime(void) const
{
	return this->_time;
}

void	Game::updateCoordinates ( void ) {}

t_vector*	Game::getShips( void ) const {
	return this->ships;
}
