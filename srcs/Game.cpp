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

int		Game::_moveEnemies( AShips* const & ship ) {
	t_vector	positions;

	positions = ship->getPositions();
	positions.x -= 1;
	if ( positions.x == 1 )
		this->pop( ship );
	else
		ship->setPositions( positions );
	return (1);
}

void	Game::_spawnEnemy( void ) {
	if (!(this->_time % 3)) {
		t_vector	positions = {
			this->_wSize.x - 1,
			rand() % (this->_wSize.y - 1) + 1
		};
		this->push(new Fighter( positions ));
	}
	return ;
}

int		Game::_handlePlayer( AShips* const & ship ) {
	t_vector	positions;
	int key = wgetch(this->_win);

	if (key != ERR) {
		positions = ship->getPositions();
		if ( key == KEY_UP && positions.y > 1 )
			positions.y -= 1;
		if ( key == KEY_DOWN && positions.y < this->_wSize.y - 1)
			positions.y += 1;
		if ( key == KEY_LEFT && positions.x > 1)
			positions.x -= 1;
		if ( key == KEY_RIGHT && positions.x < this->_wSize.x - 1)
			positions.x += 1;
		ship->setPositions( positions );
	}
	if (key == ESC_KEY)
		return ( GAME_EXIT );
	return ( GAME_CONTINUE );
}

int		Game::_checkPositions( void ) {
	t_ships*	player = this->_ships;

	if (!player)
		return ( GAME_EXIT );

	t_ships*	enemies = player->next;
	t_vector	playerPositions = player->ship->getPositions();

	while (enemies) {
		t_vector	enemyPosition = enemies->ship->getPositions();
		if ( enemyPosition.x == playerPositions.x
				&& enemyPosition.y == playerPositions.y )
			return ( GAME_EXIT );
		enemies = enemies->next;
	}
	return ( GAME_CONTINUE );
}

t_stars	*clean(t_stars *univers)
{
	if (univers == NULL)
		return NULL;
	else if(univers->star->getCoordinates().x < 1 && univers->next != NULL)
    {
  //   	t_stars *tmp = univers;
		// univers = univers->next;
		// delete tmp->star;
		// delete tmp;
        return univers;
    }
    else
        return univers;
}

int		Game::update ( void ) {

	if (this->_checkPositions() == GAME_EXIT)
		return ( GAME_EXIT );
	t_stars*	univers = clean(this->_stars);
	t_vector	positions;
	while ( univers ) {
		if (univers->star->getCoordinates().x > 0) {
			positions = univers->star->getCoordinates();
			positions.x -= 1;
			univers->star->setCoordinates( positions );
		}
		univers = univers->next;
	}
	std::string	unitTypes[2] = {
		"Player",
		"Fighter"
	};
	int		(Game::*f[2])( AShips* const & ) = {
		&Game::_handlePlayer,
		&Game::_moveEnemies
	};
	int			len = sizeof(unitTypes) / sizeof(unitTypes[0]);
	t_ships*	unit = this->_ships;

	while ( unit ) {
		for (int i = 0; i < len; i++) {
			if (unit->ship->getType() == unitTypes[i]
				&& (this->*f[i])(unit->ship) == GAME_EXIT)
				return ( GAME_EXIT );
		}
		unit = unit->next;
	}
	this->_spawnEnemy();
	return ( GAME_CONTINUE );
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

void	Game::push2( Stars * const & star ) {
	t_stars*	tmp = this->_stars;

	if (!this->_stars) {
		this->_stars = new t_stars;
		this->_stars->star = star;
		this->_stars->next = NULL;
	}
	else {
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new t_stars;
		tmp->next->star = star;
		tmp->next->next = NULL;
	}
	this->_count += 1;
	return ;
}
void	Game::voyage(void) {
	int 			rand_height = std::rand() % (this->_wSize.y -2) + 1;
	t_vector	right = {this->_wSize.x - 1, rand_height }; //add random
	this->push2(new Stars( right ));
}
void	Game::pop2( Stars * const & star ) {
	t_stars*	tmp;
	t_stars*	toDelete;

	tmp = this->_stars;
	if (this->_stars->star == star) {
		this->_stars = this->_stars->next;
		delete tmp->star;
		delete tmp;
	}
	else {
		while ( tmp && tmp->next && tmp->next->star != star )
			tmp = tmp->next;
		if ( !tmp->next || tmp->next->star != star )
			return ;
		toDelete = tmp->next;
		tmp->next = toDelete->next;
		delete toDelete->star;
		delete toDelete;
	}
	return ;
}

void		Game::display( void ) const {
	t_ships*	unit = this->_ships;
	t_vector	position;
	std::string	body;
	t_stars*	univers = this->_stars;

	while (univers) {
		position = univers->star->getCoordinates();
		mvwprintw(this->_win, position.y, position.x, "*");
		univers = univers->next;
	}
	while (unit) {
//		std::cout << *(unit->ship);
		if (unit->ship->getType() == "Player")
			body = "X";
		else
			body = "<";
		position = unit->ship->getPositions();
		mvwprintw(this->_win, position.y, position.x, body.c_str());
		unit = unit->next;
	}
	return ;
}

t_ships*	Game::getShips( void ) const {
	return this->_ships;
}
