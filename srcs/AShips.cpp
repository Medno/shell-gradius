#include "AShips.hpp"

std::vector<AShips::shot>	AShips::shots = {};

AShips::AShips( void ) {}
AShips::AShips( AShips const & src ) {
	*this = src;
	return ;
}
AShips &	AShips::operator=( AShips const & rhs ) {
	if ( this != &rhs ) {
		this->positions = rhs.getPositions();
	}
	return *this;
}

AShips::AShips( std::string const & type, t_vector const & coord )
	: AElement( coord ), type(type) {}

std::string	AShips::getType( void ) const {
	return this->type;
}

std::vector<AShips::shot>	AShips::getShots( void ) {
	return AShips::shots;
}

void	AShips::pushShot( entity ent, t_vector position ) {
	AShips::shots.push_back({ ent, position });
	LOG(std::to_string(AShips::shots.size()))
}

void	AShips::moveShots( void ) {
	for (auto&& shot : AShips::shots )
		shot.second.x += 1;
}

bool		AShips::checkShotPosition( AShips::shot const & shot, int const & x ) {
	return shot.second.x == x;
}

bool		AShips::checkShotPosition( AShips::shot const & shot, t_vector const & pos ) {
	return ( shot.second.x == pos.x && shot.second.y == pos.y );
}

void		AShips::popBordersShots( t_vector const & wSize ) {
	AShips::shots.erase(std::remove_if(AShips::shots.begin(), AShips::shots.end(),
		[wSize]( AShips::shot shot ){
			return AShips::checkShotPosition( shot, 1 )
				|| AShips::checkShotPosition( shot, wSize.x );
		}), AShips::shots.end());
	return ;
}

void	AShips::popShot( int index ) {
	AShips::shots.erase(AShips::shots.begin() + index);
}

std::ostream & operator<<( std::ostream & o, AShips const & rhs ) {
	t_vector	positions = rhs.getPositions();
	o << rhs.getType() << " at positions : y: " << positions.y << ", x: " << positions.x << std::endl;
	return o;
}
