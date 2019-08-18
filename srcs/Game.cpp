#include "Game.hpp"
#include "Stars.hpp"
#include "AElement.hpp"
#include "AShips.hpp"
#include "Boss.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Fighter.hpp"

std::vector<AShips *>	Game::ships = {};
WINDOW*	Game::win = NULL;
t_vector	Game::wSize = {0, 0};

Game::Game( void ) {}
Game::~Game( void ) {}

Game::Game( Game const & src ) {
	*this = src;
	return ;
}

Game &	Game::operator=( Game const & rhs ) {
	if ( this != &rhs ) {
		this->stars = rhs.stars;
		this->win = rhs.getWin();
		this->wSize = rhs.getWSize();
		this->time = rhs.getTime();
		this->score = rhs.getScore();
	}
	return *this;
}
Game::Game( WINDOW * const & win, t_vector const & size )
	: stars( {} ), score(0) {
	Game::win = win;
	Game::wSize = size;
}

void	Game::init( void ) {
	t_vector	middle = { this->wSize.x / 5, this->wSize.y / 2 };
	this->push(new Player( middle ));
	return ;
}

void	Game::push( AShips * const ship ) {
	Game::ships.push_back( ship );
	return ;
}
void	Game::push( AElement * const star ) {
	this->stars.push_back( star );
	return ;
}

void	Game::pop( AShips * const ship ) {
	Game::ships.erase(std::remove(Game::ships.begin(), Game::ships.end(), ship), Game::ships.end());
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

std::vector<AShips *> const &	Game::getShips( void ) const {
	return Game::ships;
}

AShips *	Game::getPlayer( void ) const {
	return Game::ships[0];
}

int		Game::checkPositions( void ) {
	AShips const *	player = Game::ships[0];
	if ( player->getType() != "Player" )
		return ( GAME_EXIT );

	t_vector	playerPositions = player->getPositions();

	for ( auto&& enemy : Game::ships ) {
		if ( enemy->getType() != "Player" ) {
			t_vector	enemyPosition = enemy->getPositions();
			if ( enemyPosition.x == playerPositions.x
					&& enemyPosition.y == playerPositions.y )
				return ( GAME_EXIT );
		}
	}
	return ( GAME_CONTINUE );
}

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

int		Game::destroyKilled( void ) {
	std::vector<AShips::shot>	shots = AShips::getShots();
	std::vector<AShips::shot *>	shotOnEnemy;
	std::vector<AShips **>	enemyShooted;
	AShips const *	player = this->getPlayer();

	LOG("Destroying killed...")
	for ( auto&& shot : shots ) { // Check if the player is killed
		if (AShips::checkShotPosition( shot, player->getPositions() ))
			return ( GAME_EXIT );
	}
	for ( auto&& shot : shots ) {
		for ( auto&& enemy : this->ships ) {
			if (AShips::checkShotPosition( shot, enemy->getPositions() )) {
				shotOnEnemy.push_back(&shot);
				enemyShooted.push_back(&enemy);
				this->score += 10;
			}
		}
	}
	for ( auto&& shot : shotOnEnemy )
		AShips::popShot(shot - &shots[0]);
	for ( auto&& enemy : enemyShooted )
		this->ships.erase(this->ships.begin() + (enemy - &this->ships[0]));
	return ( GAME_CONTINUE );
}

int		Game::update( void ) {
	LOG("Updating...")
	this->pushStar();
	AShips::moveShots();
	AShips::popBordersShots( this->wSize );
	this->destroyKilled();
	if (this->checkPositions() == GAME_EXIT)
		return ( GAME_EXIT );
	for ( auto&& star : this->stars )
		star->update();
	for ( auto&& ship : Game::ships )
		ship->update();
	this->stars.erase(std::remove_if(this->stars.begin(), this->stars.end(),
		[]( AElement * star ){return !(star->getPositions().x);}), this->stars.end());
	Game::ships.erase(std::remove_if(Game::ships.begin(), Game::ships.end(),
		[]( AElement * ship ){return !(ship->getPositions().x);}), Game::ships.end());
	this->destroyKilled();
	this->spawnEnemy();
	return ( GAME_CONTINUE );
}

void		Game::displayShots( void ) const {
	std::vector<AShips::shot>	list = AShips::getShots();

	for (auto&& shot : list )
		mvwprintw(this->win, shot.second.y, shot.second.x, "-");
	return ;
}

void	Game::pushStar( void ) {
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
	this->displayShots();
	for ( auto&& ship : Game::ships ) {
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
