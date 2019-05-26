#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include "defs.hpp"
#include "AShips.hpp"
#include "Player.hpp"
#include <iostream>

typedef struct	s_ships {
	AShips*			ship;
	struct s_ships*	next;
}				t_ships;

class	Game {
public:
	Game( void );
	~Game( void );
	Game( Game const & src );
	Game &	operator=( Game const & src );

	Game( WINDOW* const &, t_vector const & );

	void	setTime(int time);
	int		getTime(void) const;

	void	init( void );
	void	push( AShips * const & );
	void	pop( AShips * const & );

	void	display( void ) const;
	void	update( void );

	t_ships*	getShips( void ) const;

protected:
	t_ships*	_ships;
	int			_count;
	WINDOW*		_win;
	t_vector	_wSize;
	int			_time;

private:
};

#endif
