#include <iostream>
#include <unistd.h>
#include <sstream>
#include <ncurses.h>

#include "Game.hpp"

#define REDIMENSION 410

int	game( void ) {
	initscr();
	noecho(); //Doesn't show char tapped by user
	cbreak(); //Quit program with ctrl-C

	WINDOW *screen;
	WINDOW *win;
	win = NULL;
	screen = newwin(3, COLS, LINES - 1, 0);

	t_vector	wSize = { COLS, LINES - 3 };
	win = newwin(wSize.y, wSize.x, 0, 0);
	keypad(win, TRUE);
	nodelay(win, TRUE);
	refresh();

	t_vector	size = { wSize.x - 1, wSize.y - 1 };
	Game game(win, size);
	game.setTime(0);
	game.init();
	while(1) {
		std::stringstream	score;
		clear();
		wclear(win);
		box(win, ACS_VLINE, ACS_HLINE); // 2nd param : L-R border, 3rd param : U-D
		game.voyage();
		game.display();

		score << "Score = " << game.getScore();
		score << " Time = " << game.getTime();
		mvwprintw(screen, 0, (COLS / 2) - score.str().size() / 2, score.str().c_str());
		wrefresh(win);  // refresh win in order to display new messages
		wrefresh(screen);  // refresh score in order to display new messages

		game.setTime(game.getTime() + 1);
		if (!game.update())
		 	break;
		usleep(100000);
	}
	delwin(win);
	delwin(screen);
	endwin();
	initscr();
	if (LINES > 10 && COLS > 20)
	{
		printw("  ___   __   _  _  ____\n");
		printw(" / __) / _\\ ( \\/ )(  __)\n");
		printw("( (_ \\/    \\/ \\/ \\ ) _) \n");
		printw(" \\___/\\_/\\_/\\_)(_/(____)\n");
		printw("  __   _  _  ____  ____ \n");
		printw(" /  \\ / )( \\(  __)(  _ \\ \n");
		printw("(  O )\\ \\/ / ) _)  )   /\n");
		printw(" \\__/  \\__/ (____)(__\\_)\n");
	}
	else
		printw("Game Over");
	refresh(); 
	getch();
	endwin();
	return (0);

}

int	main( void ) {
	game();
	return (0);
}
