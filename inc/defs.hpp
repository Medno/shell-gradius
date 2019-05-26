#ifndef DEFS_HPP
# define DEFS_HPP

#define GAME_EXIT		0
#define GAME_CONTINUE	1
#define ESC_KEY			27

typedef struct	s_vector {
	int	x;
	int	y;
}				t_vector;

typedef struct  s_shots {
	bool			enemy;
	t_vector        positions;
	struct s_shots  *next;
}               t_shots;

#endif
