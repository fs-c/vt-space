#ifndef SPACE_H
#define SPACE_H

/* ASCII "escape" character */
#define ESC 0x1B

#define PLAYER_WIDTH 3
#define PLAYER_HEIGHT 4

#include <stdio.h>
#include <stddef.h>

struct projectile {
	int x;
	int y;
	int speed;
};

/* Draws a ship at the given position. Width and height are constant.
 */
void draw_ship(int x, int y);

/* Draws a projectile at the given position. Width and height are constant.
 */
void draw_projectile(int x, int y);

/* Fetches the dimensions in columns and lines (aka rows) of the current 
 * terminal window. Returns nonzero on failure.
 */
int get_terminal_dimensions(int *columns, int *lines);

/* Enables processing of virtual terminal sequences through the input stream.
 * Returns nonzero on failure.
 */
int setup_terminal();

/* Erases the terminal screen.
 */
void clear_terminal();

/* Nonblocking version of stdlib function getchar.
 */
inline char getchar_nonblock();

/* Make a given number "wrap around" if it is larger or smaller than the min or
 * max, respectively.
 */
inline int wrap_around(int actual, int min, int max);

/* Removes an array item, moving the rest of the array "downwards".
 */
int remove_array_item(void *array, int index, int length, size_t item_size);

#endif
