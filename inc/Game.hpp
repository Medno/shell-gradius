#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include "Logger.hpp"
#include "defs.hpp"
#include <iostream>
#include <vector>
class AShips;
class AElement;
class Stars;

/*
typedef struct	s_ships {
	AShips*			ship;
	struct s_ships*	next;
}				t_ships;

typedef struct	s_stars {
	AElement*		star;
	struct s_stars*	next;
}				t_stars;
*/
class	Game {
public:
	~Game( void );
	Game( Game const & src );
	Game &	operator=( Game const & src );

	Game( WINDOW* const &, t_vector const & );

	void	init( void );
	void	push( AShips * const );
	void	push( AElement * const );
	void	pop( AShips * const );
	void	pop( AElement * const );

	void	voyage( void );

	void	display( void ) const;
	int		update( void );

	void	setTime(int time);
	int		getTime(void) const;
	int		getScore(void) const;
	std::vector<AElement *>	getStars( void ) const;
	std::vector<AShips *> const &	getShips( void ) const;
	WINDOW*		getWin( void ) const;
	t_vector	getWSize( void ) const;
	AShips *	getPlayer( void ) const;

protected:
	std::vector<AElement *>	stars;
	WINDOW*		win;
	t_vector	wSize;
	int			time;
	int 		score;
	Game( void );


private:
	/*
	int		handlePlayer( t_ships* const & );
	int		moveEnemies( t_ships* const & );
	int		moveBoss( t_ships* const & );
	*/
	void	spawnEnemy( void );
	int		checkPositions( void );
	void	displayShots( void ) const;
	int		destroyKilled( void );
	static std::vector<AShips *>	ships;
};

#endif
