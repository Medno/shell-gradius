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

void	Player::fire( void ) {
	std::cout << "Waw, nice shot Captain !" << std::endl;
	return ;
}
