#include "Game.hpp"

Game::Game( void ) {}

Game::Game( WINDOW * const & win, t_vector const & size )
	: _ships( NULL ), _win(win), _wSize(size), _score(0) {}

Game::~Game( void ) {
	t_ships*	tmp = this->_ships;
	t_stars*	stars;

	if (tmp) {
		this->_ships = this->_ships->next;
		delete tmp->ship;
		delete tmp;
		tmp = this->_ships;
	}
	stars = this->_stars;
	while (stars) {
		this->_stars = this->_stars->next;
		delete stars->star;
		delete stars;
		stars = this->_stars;
	}
	return ;
}

Game::Game( Game const & src ) {
	t_ships*	ships;
	t_stars*	stars;

	this->_win = src.getWin();
	this->_wSize = src.getWSize();
	this->_time = src.getTime();
	this->_score = src.getScore();
	ships = src.getShips();
	while (ships) {
		this->push(ships->ship->clone());
		ships = ships->next;
	}
	stars = src.getStars();
	while (stars) {
		this->push(stars->star->clone());
		stars = stars->next;
	}
	return ;
}

Game &	Game::operator=( Game const & rhs ) {
	t_ships*	ships;
	t_stars*	stars;

	if ( this != &rhs ) {
		ships = this->_ships;
		while (ships) {
			this->_ships = this->_ships->next;
			delete ships->ship;
			delete ships;
			ships = this->_ships;
		}
		stars = this->_stars;
		while (stars) {
			this->_stars = this->_stars->next;
			delete stars->star;
			delete stars;
			stars = this->_stars;
		}

		this->_win = rhs.getWin();
		this->_wSize = rhs.getWSize();
		this->_time = rhs.getTime();
		this->_score = rhs.getScore();
		ships = rhs.getShips();
		while (ships) {
			this->push(ships->ship->clone());
			ships = ships->next;
		}
		stars = rhs.getStars();
		while (stars) {
			this->push(stars->star->clone());
			stars = stars->next;
		}
	}
	return *this;
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
	return ;
}
void	Game::push( AElement * const & star ) {
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
	return ;
}


void	Game::pop( t_ships * const & ship ) {
	t_ships*	tmp = this->_ships;
	t_ships*	toDelete;

	tmp = this->_ships;
	if (this->_ships == ship) {
		this->_ships = this->_ships->next;
		delete tmp->ship;
		delete tmp;
	}
	else {
		while ( tmp && tmp->next && tmp->next != ship )
			tmp = tmp->next;
		if ( !tmp->next || tmp->next != ship )
			return ;
		toDelete = tmp->next;
		tmp->next = toDelete->next;
		delete toDelete->ship;
		delete toDelete;
	}

	return ;
}

void	Game::pop( t_stars * const & star ) {
	t_stars*	tmp = this->_stars;
	t_stars*	toDelete;

	tmp = this->_stars;
	if (this->_stars == star) {
		this->_stars = this->_stars->next;
		delete tmp->star;
		delete tmp;
	}
	else {
		while ( tmp && tmp->next && tmp->next != star )
			tmp = tmp->next;
		if ( !tmp->next || tmp->next != star )
			return ;
		toDelete = tmp->next;
		tmp->next = toDelete->next;
		delete toDelete->star;
		delete toDelete;
	}

	return ;
}

void		Game::setTime(int time) {
	this->_time = time;
	return ;
}

int			Game::getTime(void) const {
	return this->_time;
}

int			Game::getScore(void) const {
	return this->_score;
}

WINDOW*		Game::getWin( void ) const {
	return this->_win;
}

t_vector	Game::getWSize( void ) const {
	return this->_wSize;
}

t_stars*	Game::getStars( void ) const {
	return this->_stars;
}

t_ships*	Game::getShips( void ) const {
	return this->_ships;
}

int		Game::_handlePlayer( t_ships* const & unit ) {
	t_vector	positions;
	int key = wgetch(this->_win);
	AShips*	ship = unit->ship;

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
	if (key == ' ')
		ship->fire();
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

int		Game::_moveEnemies( t_ships* const & unit ) {
	t_vector	positions;
	AShips*	const &	ship = unit->ship;

	positions = ship->getPositions();
	positions.x -= 1;
	if ( positions.x == 1 )
		this->pop( unit );
	else
		ship->setPositions( positions );
	return (1);
}

int		Game::_moveBoss( t_ships* const & unit ) {
	t_vector	positionsBoss;
	t_vector	positionsPlayer = this->_ships->ship->getPositions();
	AShips*	ship = unit->ship;

	positionsBoss = ship->getPositions();
	if (positionsBoss.x > positionsPlayer.x + 50)
		positionsBoss.x -= 1;
	else if (positionsBoss.x < positionsPlayer.x + 20 &&
		positionsBoss.x < this->_wSize.x - 1)
		positionsBoss.x += 1;
	if (positionsBoss.y > positionsPlayer.y)
		positionsBoss.y -= 1;
	else if (positionsBoss.y < positionsPlayer.y)
		positionsBoss.y += 1;
	if ( positionsBoss.x == 1 )
		this->pop( unit );
	else
		ship->setPositions( positionsBoss );
	return (1);
}


void	Game::_spawnEnemy( void ) {
	if (!(this->_time % 10)) {
		t_vector	positions = {
			this->_wSize.x - 1,
			rand() % (this->_wSize.y - 1) + 1
		};
		if ((this->_time % 300) == 120)
			this->push(new Boss( positions ));
		else
			this->push(new Fighter( positions ));
	}
	return ;
}


int		Game::_destroyKilled( void ) {
	if (!this->_ships)
		return ( GAME_EXIT );

	t_ships*	enemies;
	t_ships*	nextEnemy;
	t_shots*	shots = AShips::getShots();
	t_shots*	prevShot;
	int			del = 0;

	while (shots) { // Check if the player is killed (first of linked list)
		enemies =  this->_ships;
		if (AShips::checkShotPosition( shots, enemies->ship->getPositions() )) {
			AShips::popShots();
			return ( GAME_EXIT );
		}
		shots = shots->next;
	}
	shots = AShips::getShots();
	prevShot = shots;
	while (shots) {
		enemies = this->_ships;
		nextEnemy = this->_ships->next;
		while (!del && shots && nextEnemy) {
			t_vector vecTmp = nextEnemy->ship->getPositions();
			vecTmp.x -= 1;
			if (AShips::checkShotPosition( shots, nextEnemy->ship->getPositions() )
				|| AShips::checkShotPosition( shots, vecTmp )) {
				shots = AShips::popShot(shots);
				prevShot = shots;
				this->pop(nextEnemy);
				this->_score += 10;
				del = 1;
			}
			if (!del && enemies) {
				enemies = enemies->next;
				nextEnemy = enemies->next;
			}
		}
		if (!del && shots) {
			prevShot = shots;
			shots = shots->next;
		}
		else
			del = 0;
	}
	return ( GAME_EXIT );
}

int		Game::update ( void ) {
	if (this->_checkPositions() == GAME_EXIT)
		return ( GAME_EXIT );
	t_stars*	univers = this->_stars;
	t_vector	positions;

	while ( univers ) {
		if (univers->star->getPositions().x > 1) {
			positions = univers->star->getPositions();
			positions.x -= 1;
			if (positions.x == 1)
				this->pop(univers);
			else
				univers->star->setPositions( positions );
		}
		univers = univers->next;
	}
	AShips::moveShots();
	std::string	unitTypes[3] = {
		"Player",
		"Boss",
		"Fighter"
	};
	int		(Game::*f[3])( t_ships* const & ) = {
		&Game::_handlePlayer,
		&Game::_moveBoss,
		&Game::_moveEnemies
	};
	int			len = sizeof(unitTypes) / sizeof(unitTypes[0]);
	t_ships*	unit = this->_ships;

	while ( unit ) {
		for (int i = 0; i < len; i++) {
			if (unit->ship->getType() == unitTypes[i]
				&& (this->*f[i])(unit) == GAME_EXIT)
				return ( GAME_EXIT );
		}
		unit = unit->next;
	}
	AShips::popBordersShots(this->_wSize);
	this->_destroyKilled();
	this->_spawnEnemy();
	return ( GAME_CONTINUE );
}

void		Game::_displayShots( void ) const {
	t_shots	*list = AShips::getShots();

	while (list) {
		mvwprintw(this->_win, list->positions.y, list->positions.x, "-");
		list = list->next;
	}
	return ;
}

void	Game::voyage(void) {
	int 		rand_height = std::rand() % (this->_wSize.y - 1) + 1;
	t_vector	right = {this->_wSize.x - 1, rand_height }; //add random
	this->push(new Stars( right ));
}

void		Game::display( void ) const {
	t_ships*	unit = this->_ships;
	t_vector	position;
	std::string	body;
	t_stars*	univers = this->_stars;

	while (univers) {
		position = univers->star->getPositions();
		mvwprintw(this->_win, position.y, position.x, "*");
		univers = univers->next;
	}
	this->_displayShots();
	while (unit) {
		if (unit->ship->getType() == "Player")
			body = "X";
		else if (unit->ship->getType() == "Boss")
			body = "8";
		else
			body = "<";
		position = unit->ship->getPositions();
		mvwprintw(this->_win, position.y, position.x, body.c_str());
		unit = unit->next;
	}
	return ;
}
