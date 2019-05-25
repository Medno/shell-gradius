#include "Game.hpp"

Game::Game( void ) : /*player( NULL ), enemies( NULL ), */coordinates( NULL ) {}
Game::~Game( void ) {}

Game::Game( Game const & src ) {
	*this = src;
	return ;
}

Game &	Game::operator=( Game const & rhs ) {
	if ( this != &rhs ) {
//		this->player = rhs.getPlayer();
//		this->enemies = rhs.getEnemies();
//		this->coordinates = rhs.getCoordinates;
	}
	return *this;
}
