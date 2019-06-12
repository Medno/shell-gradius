#ifndef BOSS_HPP
#define BOSS_HPP

#include "Enemy.hpp"
#include <iostream>

/*
 * Intelligent ship: come to you
*/ 

class Boss: public Enemy {
public:
	~Boss( void );
	Boss( Boss const & src );
	Boss &	operator=( Boss const & );

	Boss( t_vector const & );

	void	fire( void );
	virtual AElement*	clone( void ) const;
	virtual int	update( void );

private:
	Boss( void );

};

#endif
