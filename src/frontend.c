#include <ncurses.h>
#include "backend.h"
#include "frontend.h"

void draw_bird(Bird *bird){
  mvaddch(bird->y, bird->x, '@');
  mvaddch(bird->y, bird->x+1, '>');

}

void draw_pipe(Obstacle *obstacle, int ymax){
  int y1, y2, x1, x2;
  int y1_down, y2_down, x1_down, x2_down;
  //obstacle->x
  //obstacle->randomCenter = new_random_center(ymax);

  //int nRandonNumber = rand()%(my - 8) + 4;
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
  /* 
   mvhline(obstacle->randomCenter + 4, obstacle->x, 0, 8);
   mvhline(ymax, obstacle->x, 0, 8-obstacle->x);
   mvvline(obstacle->randomCenter + 4, obstacle->x, 0, ymax-obstacle->randomCenter + 4 - obstacle->x);
   mvvline(obstacle->randomCenter + 4, 8, 0, ymax-obstacle->randomCenter + 4);
   mvaddch(obstacle->randomCenter + 4, 0, ACS_ULCORNER);
   mvaddch(ymax, 0, ACS_LLCORNER);
   mvaddch(obstacle->randomCenter + 4, 8, ACS_URCORNER);
   mvaddch(ymax, 8, ACS_LRCORNER);
*/
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


