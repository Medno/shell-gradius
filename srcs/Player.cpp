#include "Player.hpp"

Player::Player( void ) {
	std::cout << "Welcome aboard, Captain." << std::endl;
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

void	Player::fire( void ) {
	std::cout << "Waw, nice shot Captain !" << std::endl;
	return ;
}
