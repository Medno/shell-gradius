#include "Player.hpp"

Player::Player( void ) {}
Player::~Player( void ) {}
Player::Player( Player const & src ) { *this = src; }
Player &	Player::operator=( Player const & ) { return *this; }

AElement*	Player::clone( void ) const {
	return new Player(*this);
}
Player::Player( t_vector const & coordinates ) : AShips( "Player", coordinates ) {}

void	Player::fire( void ) {
	t_vector	positions = this->getPositions();

	this->pushShot(PLAYER, positions);
	LOG("FIREEEEEEEEEEEEEEEEE")
	return ;
}

int		Player::update( void ) {
	int			key = wgetch(this->getWin());
	t_vector	positions;

	LOG("Swinging")
	if (key != ERR) {
		positions = this->positions;
		if ( key == KEY_UP && positions.y > 1 )
			positions.y -= 1;
		if ( key == KEY_DOWN && positions.y < this->getWSize().y - 1)
			positions.y += 1;
		if ( key == KEY_LEFT && positions.x > 1)
			positions.x -= 1;
		if ( key == KEY_RIGHT && positions.x < this->getWSize().x - 1)
			positions.x += 1;
		this->setPositions( positions );
        while (wgetch(this->getWin()) == key);
	}
	if (key == ESC_KEY)
		return ( GAME_EXIT );
	if (key == ' ')
		this->fire();
	return ( GAME_CONTINUE );
}
