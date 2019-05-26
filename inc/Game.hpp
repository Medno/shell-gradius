#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include "defs.hpp"
#include "AShips.hpp"
#include "Player.hpp"
#include "Fighter.hpp"
#include "Boss.hpp"
#include "Stars.hpp"
#include <iostream>

typedef struct	s_ships {
	AShips*			ship;
	struct s_ships*	next;
}				t_ships;
typedef struct	s_stars {
	Stars*			star;
	struct s_stars*	next;
}				t_stars;

class	Game {
public:
	Game( void );
	~Game( void );
	Game( Game const & src );
	Game &	operator=( Game const & src );

	Game( WINDOW* const &, t_vector const & );

	void	setTime(int time);
	int		getTime(void) const;
	int		getScore(void) const;

	void	init( void );
	void	push( AShips * const & );
	void	pop( t_ships * const & );

	void 	push2( Stars * const & );
	void	pop2( Stars * const & );
	void	voyage( void );

	void	display( void ) const;
	int		update( void );

	t_ships*	getShips( void ) const;

protected:
	t_ships*	_ships;
	int			_count;
	WINDOW*		_win;
	t_vector	_wSize;
	int			_time;
	t_stars*	_stars;
	int 		_score;


private:
	int		_handlePlayer( t_ships* const & );
	int		_moveEnemies( t_ships* const & );
	int		_moveBoss( t_ships* const & );
	void	_spawnEnemy( void );
	int		_checkPositions( void );
	void	_displayShots( void ) const;
	int		_destroyKilled( void );
};

#endif
