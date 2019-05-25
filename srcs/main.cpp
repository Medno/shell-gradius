#include <iostream>
#include <unistd.h>

#include <sstream>
#include <ncurses.h>

#define REDIMENSION 410

int	main( void ) {
	initscr();
	noecho(); //Doesn't show char tapped by user
	cbreak(); //Quit program with ctrl-C

	WINDOW *screen;
	WINDOW *win;

	int	n = 0;
	while(1) {
		std::stringstream	score;
		clear();
		screen = newwin(1, COLS, LINES - 1, 0);
		win = newwin(LINES - 1, COLS, 0, 0);
		refresh();
		box(win, ACS_VLINE, ACS_HLINE); // 2nd param : L-R border, 3rd param : U-D
		score << "Score = " << n;
		mvwprintw(screen, 0, (COLS / 2) - score.str().size() / 2, score.str().c_str());
		wrefresh(win);  // refresh win in order to display new messages
		wrefresh(screen);  // refresh score in order to display new messages
		n += 1;
		usleep(100000);
	}
	delwin(win);
	delwin(screen);
	endwin();
	return (0);
}
