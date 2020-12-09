#include <ncurses.h>
#include "screen.h"

int main() {

	screen s;

	int item[] = {FOOD, TOOL, OBSTACLE, CHEST, SHIP, BINOCULARS, NONE, HEROCHAR};
	int terrain[] = {MEADOW, SWAMP, WATER, WALL, HERO, DIAMOND};

	int key = 0;
	s.printtomenu( "\nCursor keys\nc create junk\ne erase junk\nt terrain\ni item\n\nq quit\n" );
	s.printtobot( "BOTTOM TEXT\n" );

	while (key != 'q') {
		key = s.getKey();
		if (key != ERR) {
			s.clearmenu();
			s.clearbot();
			s.printtomenu( "\nCursor keys\nc create junk\ne erase junk\nt terrain\ni item\n\nq quit\n" );
			s.printtobot( "BOTTOM TEXT\n" );
		}

		if (key == 'c') {
			int t = terrain[rand() % 6];
			for (int i = 0; i <= 127; ++i) {
				for (int j = 0; j <= 127; ++j) {
					int it = NONE;
					if (rand() % 10 > 8) {
						it = item[rand() % 8];
					}
					s.put(i,j,it, t );
				}
			s.putCursor(63, 63);
			s.center(63,63);
			}
		}
		if (key == 'e') {
			s.init();
		}
		if (key == KEY_UP) {
			s.moveCursor(NORTH);
		}
		if (key == KEY_DOWN) {
			s.moveCursor(SOUTH);
		}
		if (key == KEY_LEFT) {
			s.moveCursor(WEST);
		}
		if (key == KEY_RIGHT) {
			s.moveCursor(EAST);
		}
		if (key == 't') {
			s.put(s.getCursorX(), s.getCursorY(), (int) terrain[rand() % 6]);
		}
		if (key == 'i') {
			s.put(s.getCursorX(), s.getCursorY(), (char) item[rand() % 8]);
		}
		s.refreshWin();
	}
}
