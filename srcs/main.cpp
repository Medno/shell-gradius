#include <iostream>
#include <unistd.h>

#include <sstream>
#include <ncurses.h>

#include "Game.hpp"

#define REDIMENSION 410

int	main( void ) {
	initscr();
	noecho(); //Doesn't show char tapped by user
	cbreak(); //Quit program with ctrl-C

	WINDOW *screen;
	WINDOW *win;
	win = NULL;
	screen = newwin(1, COLS, LINES - 1, 0);
	win = newwin(LINES - 1, COLS, 0, 0);
	keypad(win, TRUE);
	nodelay(win, TRUE);
	refresh();

	t_vector	size = { COLS - 1, LINES - 2 };
	Game game(win, size);
	game.setTime(0);
	game.init();
	while(1) {
		std::stringstream	score;
		clear();
		wclear(win);
		box(win, ACS_VLINE, ACS_HLINE); // 2nd param : L-R border, 3rd param : U-D
		game.display();
		score << "Score = " << game.getTime();
		mvwprintw(screen, 0, (COLS / 2) - score.str().size() / 2, score.str().c_str());
		wrefresh(win);  // refresh win in order to display new messages
		wrefresh(screen);  // refresh score in order to display new messages

		game.setTime(game.getTime() + 1);
		game.update();
		usleep(100000);
	}
	delwin(win);
	delwin(screen);
	endwin();
	return (0);
}
