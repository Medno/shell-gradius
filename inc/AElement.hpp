#ifndef AELEMENT_HPP
#define AELEMENT_HPP

#include "defs.hpp"

class	AElement {
public:
	virtual ~AElement( void );
	AElement( AElement const & src );
	AElement &	operator=( AElement const & src );

	AElement( t_vector const & );

	void			setPositions( t_vector const & );
	t_vector		getPositions( void ) const;
	virtual AElement*	clone( void ) const = 0;

protected:
	AElement( void );
	t_vector	_positions;
private:
};

#endif
