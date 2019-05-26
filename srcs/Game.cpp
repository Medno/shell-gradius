#include "Game.hpp"

Game::Game( void ) : _ships( NULL ), _count(0) {}

Game::Game( WINDOW * const & win, t_vector const & size ) : _ships( NULL ), _count(0), _win(win), _wSize(size) {}

Game::~Game( void ) {
	t_ships*	tmp = this->_ships;

	if (tmp) {
		this->_ships = this->_ships->next;
		delete tmp->ship;
		delete tmp;
		tmp = this->_ships;
	}
	return ;
}

Game::Game( Game const & src ) {
	*this = src;
	return ;
}

Game &	Game::operator=( Game const & rhs ) {
	if ( this != &rhs ) {
	}
	return *this;
}

void		Game::setTime(int time)
{
	this->_time = time;
	return ;
}
int			Game::getTime(void) const
{
	return this->_time;
}

void	Game::update ( void ) {
	t_ships*	unit = this->_ships;
	t_vector	positions;

	while ( unit ) {
		if (unit->ship->getType() != "Player") {
			positions = unit->ship->getPositions();
			positions.x -= 1;
			unit->ship->setPositions( positions );
		}
		int key = wgetch(this->_win);
		if (unit->ship->getType() == "Player" && key != ERR) {
			positions = unit->ship->getPositions();
			if ( key == KEY_UP && positions.y > 1 )
				positions.y -= 1;
			if ( key == KEY_DOWN && positions.y < this->_wSize.y - 1)
				positions.y += 1;
			if ( key == KEY_LEFT && positions.x > 1)
				positions.x -= 1;
			if ( key == KEY_RIGHT && positions.x < this->_wSize.x - 1)
				positions.x += 1;
			unit->ship->setPositions( positions );
//			std::cout << *(unit->ship);
		}
		unit = unit->next;
	}
	return ;
}

void	Game::init( void ) {
	t_vector	middle = { this->_wSize.x / 5, this->_wSize.y / 2 };
	this->push(new Player( middle ));
	return ;
}

void	Game::push( AShips * const & ship ) {
	t_ships*	tmp = this->_ships;

	if (!this->_ships) {
		this->_ships = new t_ships;
		this->_ships->ship = ship;
		this->_ships->next = NULL;
	}
	else {
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new t_ships;
		tmp->next->ship = ship;
		tmp->next->next = NULL;
	}
	this->_count += 1;
	return ;
}

void	Game::pop( AShips * const & ship ) {
	t_ships*	tmp;
	t_ships*	toDelete;

	tmp = this->_ships;
	if (this->_ships->ship == ship) {
		this->_ships = this->_ships->next;
		delete tmp->ship;
		delete tmp;
	}
	else {
		while ( tmp && tmp->next && tmp->next->ship != ship )
			tmp = tmp->next;
		if ( !tmp->next || tmp->next->ship != ship )
			return ;
		toDelete = tmp->next;
		tmp->next = toDelete->next;
		delete toDelete->ship;
		delete toDelete;
	}
	return ;
}

void		Game::display( void ) const {
	t_ships*	unit = this->_ships;
	t_vector	position;

	while (unit) {
//		std::cout << *(unit->ship);
		position = unit->ship->getPositions();
		mvwprintw(this->_win, position.y, position.x, "X");
		unit = unit->next;
	}
	return ;
}

t_ships*	Game::getShips( void ) const {
	return this->_ships;
}
