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
		this->_type = rhs._type;
		this->_positions = rhs._positions;
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
