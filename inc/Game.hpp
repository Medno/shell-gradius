#ifndef GAME_HPP
#define GAME_HPP

class	Game {
public:
	Game( void );
	~Game( void );
	Game( Game const & src );
	Game &	operator=( Game const & src );

protected:
	Player*			player;
	Enemy*			enemies;
	t_vector*	coordinates;

private:
};

#endif
