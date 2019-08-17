#include "Game.hpp"
#include "Stars.hpp"
#include "AElement.hpp"
#include "AShips.hpp"
#include "Boss.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Fighter.hpp"

Game::Game( void ) {}

Game::Game( WINDOW * const & win, t_vector const & size )
	: ships( {} ), stars( {} ), win(win), wSize(size), score(0) {}

Game::~Game( void ) {}

Game::Game( Game const & src ) {
	*this = src;
	return ;
}

Game &	Game::operator=( Game const & rhs ) {
	if ( this != &rhs ) {
		this->ships = rhs.ships;
		this->stars = rhs.stars;
		this->win = rhs.getWin();
		this->wSize = rhs.getWSize();
		this->time = rhs.getTime();
		this->score = rhs.getScore();
		ships = rhs.getShips();
	}
	return *this;
}

void	Game::init( void ) {
	t_vector	middle = { this->wSize.x / 5, this->wSize.y / 2 };
	this->push(new Player( middle ));
	return ;
}

void	Game::push( AShips * const ship ) {
	this->ships.push_back( ship );
	return ;
}
void	Game::push( AElement * const star ) {
	this->stars.push_back( star );
	return ;
}

void	Game::pop( AShips * const ship ) {
	this->ships.erase(std::remove(this->ships.begin(), this->ships.end(), ship), this->ships.end());
	return ;
}

void	Game::pop( AElement * star ) {
	LOG("HELLO I'M TRYING TO BE DELETE")
	this->stars.erase(std::remove(this->stars.begin(), this->stars.end(), star), this->stars.end());
	return ;
}

void		Game::setTime(int time) {
	this->time = time;
	return ;
}

int			Game::getTime(void) const {
	return this->time;
}

int			Game::getScore(void) const {
	return this->score;
}

WINDOW*		Game::getWin( void ) const {
	return this->win;
}

t_vector	Game::getWSize( void ) const {
	return this->wSize;
}

std::vector<AElement *>	Game::getStars( void ) const {
	return this->stars;
}

std::vector<AShips *>	Game::getShips( void ) const {
	return this->ships;
}
/*
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
        while (wgetch(this->_win) == key);
	}
	if (key == ESC_KEY)
		return ( GAME_EXIT );
	if (key == ' ')
		ship->fire();
	return ( GAME_CONTINUE );
}
*/
int		Game::checkPositions( void ) {
	AShips const *	player = this->ships[0];
	if ( player->getType() != "Player" )
		return ( GAME_EXIT );

	t_vector	playerPositions = player->getPositions();

	for ( auto&& enemy : this->ships ) {
		if ( enemy->getType() != "Player" ) {
			t_vector	enemyPosition = enemy->getPositions();
			if ( enemyPosition.x == playerPositions.x
					&& enemyPosition.y == playerPositions.y )
				return ( GAME_EXIT );
		}
	}
	return ( GAME_CONTINUE );
}
/*
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
*/

void	Game::spawnEnemy( void ) {
	if (!(this->time % 10)) {
		t_vector	positions = {
			this->wSize.x - 1,
			rand() % (this->wSize.y - 1) + 1
		};
		if ((this->time % 300) == 120)
			this->push(new Boss( positions ));
		else
			this->push(new Fighter( positions ));
	}
	return ;
}

/*
int		Game::destroyKilled( void ) {
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
				this->pop( nextEnemy->ship );
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
*/

int		Game::update( void ) {
	LOG("Updating...")
	if (this->checkPositions() == GAME_EXIT)
		return ( GAME_EXIT );
	LOG("Check position done")
	for ( auto&& star : this->stars )
		star->update();
	for ( auto&& ship : this->ships ) {
		if (ship->getType() != "Player")
			ship->update();
	}
	LOG("Update of stars done")
	this->stars.erase(std::remove_if(this->stars.begin(), this->stars.end(),
                              []( AElement * star ){return !(star->getPositions().x);}), this->stars.end());
	this->ships.erase(std::remove_if(this->ships.begin(), this->ships.end(),
                              []( AElement * ship ){return !(ship->getPositions().x);}), this->ships.end());
	/*
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
	*/
//	int			len = sizeof(unitTypes) / sizeof(unitTypes[0]);
	/*
	t_ships*	unit = this->ships;

	while ( unit ) {
		for (int i = 0; i < len; i++) {
			if (unit->ship->getType() == unitTypes[i]
				&& //if (unit->ship->update() == GAME_EXIT)
				return ( GAME_EXIT );
		//}
		unit = unit->next;
	}
	*/
	LOG("Update ships done")
	AShips::popBordersShots(this->wSize);
//	this->_destroyKilled();
//	LOG("Destroy Killed")
	this->spawnEnemy();
	LOG("End of Updating")
	return ( GAME_CONTINUE );
}

void		Game::displayShots( void ) const {
	t_shots	*list = AShips::getShots();

	while (list) {
		mvwprintw(this->win, list->positions.y, list->positions.x, "-");
		list = list->next;
	}
	return ;
}

void	Game::voyage(void) {
	int 		rand_height = std::rand() % (this->wSize.y - 1) + 1;
	t_vector	right = {this->wSize.x - 1, rand_height }; //add random
	this->push(new Stars( right ));
}

void		Game::display( void ) const {
	t_vector	position;
	std::string	body;

	for ( auto&& star : this->stars ) {
		position = star->getPositions();
		mvwprintw(this->win, position.y, position.x, ".");
	}
//	this->displayShots();
	for ( auto&& ship : this->ships ) {
		if (ship->getType() == "Player") {
			wattron(this->win, COLOR_PAIR(1));
			body = "$";
		}
		else if (ship->getType() == "Boss")
			body = "8";
		else
			body = "<";
		position = ship->getPositions();
		mvwprintw(this->win, position.y, position.x, body.c_str());

		if (ship->getType() == "Player")
			wattroff(this->win, COLOR_PAIR(1));
	}
	return ;
}
