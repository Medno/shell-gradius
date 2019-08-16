#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>
#include <fstream>
#ifdef NLOG
#	define LOG(msg)
#	define LOG_OPEN()
#	define LOG_CLOSE()
#else
#	define LOG(msg) Logger::Instance().write(msg);
#	define LOG_OPEN() Logger::Instance().openLogFile();
#	define LOG_CLOSE() Logger::Instance().closeLogFile();
#endif

class	Logger {
private:
	Logger( void );
	~Logger( void );
	Logger( Logger const & );
	Logger &	operator=( Logger const & );

	std::ofstream file;

public:
	static Logger &	Instance( void );
	bool	openLogFile( void );
	void	write( std::string const & );
	bool	closeLogFile( void );
};

#endif
