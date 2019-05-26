#include "AShips.hpp"

AShips::AShips( void ) {}

AShips::AShips( std::string const & type, t_vector const & coord )
	: AElement( coord ), _type(type) {
//	std::cout << "AShips has been created" << std::endl;
	return ;
}

AShips::AShips( AShips const & src ) {
	*this = src;
	return ;
}

AShips &	AShips::operator=( AShips const & rhs ) {
	if ( this != &rhs ) {
		this->_positions = rhs.getPositions();
	}
	return *this;
}

std::string	AShips::getType( void ) const {
	return this->_type;
}

void	AShips::setShots( t_shots * const & shot ) {
	AShips::_shots = shot;
	return ;
}
t_shots*	AShips::getShots( void ) {
	return AShips::_shots;
}

void		AShips::moveShots( void ) {
	t_shots*	shot = AShips::getShots();

	while (shot) {
		shot->positions.x += 1;
		shot = shot->next;
	}
}

bool		AShips::checkShotPosition( t_shots * const & shot, int const & x ) {
	if ( shot->positions.x == x )
		return true;
	return false;
}

bool		AShips::checkShotPosition( t_shots * const & shot, t_vector const & pos ) {
	if ( shot->positions.x == pos.x && shot->positions.y == pos.y )
		return true;
	return false;
}

void		AShips::popBordersShots( t_vector const & wLimits ) {
	t_shots*	tmp = AShips::_shots;

	while (tmp) {
		if (AShips::checkShotPosition( tmp, 1 )
			|| AShips::checkShotPosition( tmp, wLimits.x ))
			tmp = AShips::popShot(tmp);
		if (tmp)
			tmp = tmp->next;
	}
	return ;
}

void		AShips::popShots( void ) {
	t_shots*	tmp = AShips::_shots;

	while (AShips::_shots) {
		AShips::_shots = AShips::_shots->next;
		delete tmp;
		tmp = AShips::_shots;
	}
	return ;
}

t_shots*	AShips::popShot( t_shots * & shot ) {
	t_shots*	tmp = AShips::_shots;

	while (tmp) {
		if (tmp == shot) {
			AShips::_shots = tmp->next;
			delete shot;
			tmp = AShips::_shots;
			break;
		}
		else if (tmp->next && tmp->next == shot) {
			tmp->next = tmp->next->next;
			delete shot;
			break ;
		}
		tmp = tmp->next;
	}
	return tmp;
}


t_shots*	AShips::_shots = NULL;

std::ostream & operator<<( std::ostream & o, AShips const & rhs ) {
	t_vector	positions = rhs.getPositions();
	o << rhs.getType() << " at positions : y: " << positions.y << ", x: " << positions.x << std::endl;
	return o;
}
