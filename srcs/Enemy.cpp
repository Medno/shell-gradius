#include "Enemy.hpp"

Enemy::Enemy( std::string const & type, t_vector const & positions ) : AShips( type, positions ) {
//	std::cout << "An enemy has been created" << std::endl;
	return ;
}

Enemy::Enemy( void ) {}

Enemy::~Enemy( void ) {
//	std::cout << "An enemy has been destroyed" << std::endl;
	return ;
}

Enemy::Enemy( Enemy const & src ) {
	*this = src;
	return ;
}

Enemy &	Enemy::operator=( Enemy const & rhs ) {
	if ( this != &rhs ) {
		this->type = rhs.type;
		this->positions = rhs.positions;
	}
	return *this;
}

/*void	Enemy::moveShots( void ) {
	t_shots*	shots = this->_shots;

	while (shots) {
		shots->positions.x -= 1;
		shots = shots->next;
	}
	return ;
}*/

void	Enemy::spawn( void ) {
//	this->addCoordinates();
	return ;	
}
/*
int	Enemy::update( void ) {
	t_vector	positions;

	positions = this->_positions;
	positions.x -= 1;
	if ( positions.x == 1 )
		this->pop( this );
	else
		this->setPositions( positions );
	return ( GAME_CONTINUE );
}
*/
