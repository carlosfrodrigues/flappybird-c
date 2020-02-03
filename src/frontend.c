#include <ncurses.h>
#include "backend.h"
#include "frontend.h"

void draw_bird(Bird *bird){
  mvaddch(bird->y, bird->x, '@');
  mvaddch(bird->y, bird->x+1, '>');

}

void draw_pipe(Obstacle *obstacle, int ymax){
  //obstacle->x
  //obstacle->randomCenter = new_random_center(ymax);

  //int nRandonNumber = rand()%(my - 8) + 4;
   int y1 = 0;
   int y2 = obstacle->randomCenter - 4;
   int x1 = obstacle->x;
   int x2 = obstacle->x + 8;

   mvhline(y1, x1, 0, x2-x1);
   mvhline(y2, x1, 0, x2-x1);
   mvvline(y1, x1, 0, y2-y1);
   mvvline(y1, x2, 0, y2-y1);
   mvaddch(y1, x1, ACS_ULCORNER);
   mvaddch(y2, x1, ACS_LLCORNER);
   mvaddch(y1, x2, ACS_URCORNER);
   mvaddch(y2, x2, ACS_LRCORNER);

   /*
   y1 = nRandonNumber + 2;
   y2 = my;
   x1 = 0;
   x2 = 4;
   */
   mvhline(obstacle->randomCenter + 4, obstacle->x, 0, 8);
   mvhline(ymax, obstacle->x, 0, 8-obstacle->x);
   mvvline(obstacle->randomCenter + 4, obstacle->x, 0, ymax-obstacle->randomCenter + 4 - obstacle->x);
   mvvline(obstacle->randomCenter + 4, 8, 0, ymax-obstacle->randomCenter + 4);
   mvaddch(obstacle->randomCenter + 4, 0, ACS_ULCORNER);
   mvaddch(ymax, 0, ACS_LLCORNER);
   mvaddch(obstacle->randomCenter + 4, 8, ACS_URCORNER);
   mvaddch(ymax, 8, ACS_LRCORNER);

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


