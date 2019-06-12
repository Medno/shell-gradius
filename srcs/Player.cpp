#include "Player.hpp"

Player::Player( void ) {
//	std::cout << "Welcome aboard, Captain." << std::endl;
	return ;
}

Player::~Player( void ) {
	std::cout << "No, Captain !!! * Then, mothing *" << std::endl;
}

Player::Player( Player const & src ) {
	*this = src;
	return ;
}

Player &	Player::operator=( Player const & ) {
	return *this;
}


Player::Player( t_vector const & coordinates ) : AShips( "Player", coordinates ) {
//	std::cout << "Welcome aboard, Captain middle." << std::endl;
	return ;
}

AElement*	Player::clone( void ) const {
	return new Player(*this);
}

void	Player::fire( void ) {
	t_shots*	shot = AShips::_shots;
	t_vector	positions = this->getPositions();

	if (!AShips::_shots) {
		AShips::_shots = new t_shots;
		AShips::_shots->enemy = 0;
		AShips::_shots->positions.x = positions.x + 1;
		AShips::_shots->positions.y = positions.y;
		AShips::_shots->next = NULL;
	}
	else {
		while (shot && shot->next)
			shot = shot->next;
		shot->next = new t_shots;
		shot->enemy = 0;
		shot->next->positions.x = positions.x + 1;
		shot->next->positions.y = positions.y;
		shot->next->next = NULL;
	}
	//std::cout << "Waw, nice shot Captain !" << std::endl;
	return ;
}
/*
void	Player::moveShots( void ) {
	t_shots*	shots = this->_shots;

	while (shots) {
		shots->positions.x += 1;
		shots = shots->next;
	}
	return ;
}
*/
int		Player::update( void ) {
	int			key = wgetch(this->_win);
	t_vector	positions;

	if (key != ERR) {
		positions = this->_positions;
		if ( key == KEY_UP && positions.y > 1 )
			positions.y -= 1;
		if ( key == KEY_DOWN && positions.y < this->_wSize.y - 1)
			positions.y += 1;
		if ( key == KEY_LEFT && positions.x > 1)
			positions.x -= 1;
		if ( key == KEY_RIGHT && positions.x < this->_wSize.x - 1)
			positions.x += 1;
		this->setPositions( positions );
        while (wgetch(this->_win) == key);
	}
	if (key == ESC_KEY)
		return ( GAME_EXIT );
	if (key == ' ')
		this->fire();
	return ( GAME_CONTINUE );
}
