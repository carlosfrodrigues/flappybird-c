#include "backend.h"
#include "frontend.h"
#include <ncurses.h>

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE); 
  curs_set(0);
  timeout(100);
  bool isKeyPressed;
  int xmax;
  int ymax;
  getmaxyx(stdscr, ymax, xmax);
  Game* game = create_game(xmax, ymax);
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_GREEN);
  init_pair(2, COLOR_CYAN, COLOR_BLUE);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_RED);

  while(true) {
    erase();
    show_score(game->score);
    draw_bird(game->bird);
    draw_pipe(game->obstacle, game->ymax);
    show_score(game->score);
    refresh();
    //sleep(1);
    isKeyPressed = get_keyboard();
    bool keepGoing = move_game(game, isKeyPressed);
    if (keepGoing == false) break;
  }
  endwin();
  erase();
  printf("Seu score foi %d", game->score);
  return 0;
}
