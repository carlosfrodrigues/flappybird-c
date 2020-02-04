#include <ncurses.h>
#include "backend.h"
#include "frontend.h"

void end_screen(Game* game){
  erase();
  attron(COLOR_PAIR(2));
  mvprintw(game->ymax/2, game->xmax/2, "Fim de jogo. Seu score foi %d\n", game->score);
  attroff(COLOR_PAIR(2));
  refresh();
  //endwin();
}

void show_score(int score, int ymax){
  attron(COLOR_PAIR(2));
  mvprintw(0,0, "score:%2d", score);
  for(int i = 1; i < ymax; i++){
    mvprintw(i,0, "        ");
  }
  attroff(COLOR_PAIR(2));
}

void draw_bird(Bird *bird){
  attron(COLOR_PAIR(4));
  mvaddch(bird->y, bird->x, '@');
  attroff(COLOR_PAIR(4));
  attron(COLOR_PAIR(3));
  mvaddch(bird->y, bird->x+1, '>');
  attroff(COLOR_PAIR(3));

}

void draw_pipe(Obstacle *obstacle, int ymax){
  
  int y1, y2, x1, x2;
  int y1_down, y2_down, x1_down, x2_down;
  attron(COLOR_PAIR(1));

  y1 = 0;
  y2 = obstacle->randomCenter - 3;
  x1 = obstacle->x;
  x2 = obstacle->x + 8;

  mvhline(y1, x1, 0, x2-x1);
  mvhline(y2, x1, 0, x2-x1);
  mvvline(y1, x1, 0, y2-y1);
  mvvline(y1, x2, 0, y2-y1);
  mvaddch(y1, x1, ACS_ULCORNER);
  mvaddch(y2, x1, ACS_LLCORNER);
  mvaddch(y1, x2, ACS_URCORNER);
  mvaddch(y2, x2, ACS_LRCORNER);

  
  y1_down = obstacle->randomCenter + 3;
  y2_down = ymax;
  x1_down = obstacle->x;
  x2_down = obstacle->x + 8;
   

  mvhline(y1_down, x1_down, 0, x2_down - x1_down);
  mvhline(y2_down, x1_down, 0, x2_down - x1_down);
  mvvline(y1_down, x1_down, 0, y2_down-y1_down);
  mvvline(y1_down, x2_down, 0, y2_down - y1_down);
  mvaddch(y1_down, x1_down, ACS_ULCORNER);
  mvaddch(y2_down, x1_down, ACS_LLCORNER);
  mvaddch(y1_down, x2_down, ACS_URCORNER);
  mvaddch(y2_down, x2_down, ACS_LRCORNER);
  attroff(COLOR_PAIR(1));
  if(obstacle->next != NULL){
    draw_pipe(obstacle->next, ymax);
  }


}

bool get_keyboard(){
  int ch = getch();
  if(ch == ' '){
    return true;
  }
  return false;
}
