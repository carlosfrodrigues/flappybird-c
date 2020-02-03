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


  while(true) {
    erase();
    draw_bird(game->bird);
    draw_pipe(game->obstacle, game->ymax);
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
