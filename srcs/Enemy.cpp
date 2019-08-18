#include "Enemy.hpp"

Enemy::Enemy( void ) {}
Enemy::~Enemy( void ) {}
Enemy::Enemy( Enemy const & src ) { *this = src; }

Enemy &	Enemy::operator=( Enemy const & rhs ) {
	if ( this != &rhs ) {
		this->type = rhs.type;
		this->positions = rhs.positions;
	}
	return *this;
}

Enemy::Enemy( std::string const & type, t_vector const & positions ) : AShips( type, positions ) {}
