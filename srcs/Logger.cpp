#include "Logger.hpp"

Logger::Logger( void ) {}
Logger::~Logger( void ) {}
Logger::Logger( Logger const & src ) { *this = src; }
Logger &	Logger::operator=( Logger const & ) { return *this; }

Logger &	Logger::Instance( void ) {
	static Logger	Logger;
	return Logger;
}

bool	Logger::openLogFile( void ) {
    this->file.open( "output.log", std::ios::app );
    this->file.seekp( std::ios::beg );

    if (!this->file.good()) return false;

	std::time_t	rawtime;
	std::tm		*timeInfo;
	char		buff[20];

	std::time( &rawtime );
	timeInfo = std::localtime( &rawtime );
	std::strftime(buff, 20, "%Y_%m_%d_%H_%M_%S", timeInfo);

    this->file << "  ===============================================\n"
		<< "    Begin Output log ( "
		<< std::string(buff) 
		<< " )\n  ===============================================\n\n";
    this->file.flush();
	return true;
}

bool	Logger::closeLogFile( void ) {

	std::time_t	rawtime;
	std::tm		*timeInfo;
	char		buff[20];

	std::time( &rawtime );
	timeInfo = std::localtime( &rawtime );
	std::strftime(buff, 20, "%Y_%m_%d_%H_%M_%S", timeInfo);

    if (!this->file.good()) return false;
    this->file << "\n  ===============================================\n"
          << "    End   Output log ( "
		<< std::string(buff)
		<< ")\n  ===============================================\n\n";
    this->file.flush();
	this->file.close();
	return true;
}

void	Logger::write( std::string const & msg ) {
	this->file << msg << '\n';
	this->file.flush();
}
