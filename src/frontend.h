#include <ncurses.h>

void show_score(int score, int xmax);
void draw_bird(Bird *bird);
void draw_pipe(Obstacle *obstacle, int ymax);
bool get_keyboard();
