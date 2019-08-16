#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include "Logger.hpp"
#include "defs.hpp"
#include <iostream>
class AShips;
class AElement;
class Stars;

typedef struct	s_ships {
	AShips*			ship;
	struct s_ships*	next;
}				t_ships;

typedef struct	s_stars {
	AElement*		star;
	struct s_stars*	next;
}				t_stars;

class	Game {
public:
	~Game( void );
	Game( Game const & src );
	Game &	operator=( Game const & src );

	Game( WINDOW* const &, t_vector const & );

	void	init( void );
	void	push( AShips * const & );
	void	push( AElement * const & );
	void	pop( AShips * const & );
	void	pop( AElement * const & );

	void	voyage( void );

	void	display( void ) const;
	int		update( void );

	void	setTime(int time);
	int		getTime(void) const;
	int		getScore(void) const;
	t_stars*	getStars( void ) const;
	t_ships*	getShips( void ) const;
	WINDOW*		getWin( void ) const;
	t_vector	getWSize( void ) const;

protected:
	t_ships*	_ships;
	WINDOW*		_win;
	t_vector	_wSize;
	int			_time;
	t_stars*	_stars;
	int 		_score;
	Game( void );


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
