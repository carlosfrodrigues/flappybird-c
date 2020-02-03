#include "backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


Obstacle* create_obstacle(int xmax, int center){
  Obstacle* obstacle = (Obstacle*) malloc(sizeof(Obstacle));
  obstacle->randomCenter = center;
  obstacle->x = xmax;
  obstacle->next = NULL;
  return obstacle;
}

Bird* create_bird(int xmax, int ymax){
  Bird* bird = (Bird*) malloc(sizeof(Bird));
  bird->x = xmax/2;
  bird->y = ymax/2;
  bird->status_jumping = false;
  return bird;
}

Game* create_game(int xmax, int ymax){
  Game* game = (Game*) malloc(sizeof(Game));
  Bird* bird = create_bird(xmax, ymax);
  Obstacle* obstacle = create_obstacle(xmax, new_random_center(ymax));
  game->bird = bird;
  game->obstacle = obstacle;
  game->score = 0;
  game->xmax = xmax;
  game->ymax = ymax;
  return game;
}

int new_random_center(int ymax){
  srand(time(NULL));
  int randomCenter = rand()%(ymax - 8) + 4;
  return randomCenter;
}

void move_obstacle(Obstacle* obstacle){
  obstacle->x = obstacle->x-1;
}

bool move_game(Game* game, bool isKeyPressed){
  if(isKeyPressed == true){
      game->bird->y = game->bird->y-2;
  }else{
    game->bird->y = game->bird->y+1;
  }
  move_obstacle(game->obstacle);
  /*
  if(collision(game->bird, game->obstacle)){
    return false;
  } */
  return true;
}
/*
bool collision(Bird* bird, Obstacle* obstacle){
  if(bird->x && bird->y )
}
*/
void destroy_obstacle(Obstacle* obstacle){
  Obstacle* obstacleFirst = obstacle;
  obstacle = obstacle->next;
  free(obstacleFirst);

}

void add_obstacle(Obstacle* obstacle, int xmax, int ymax){
  if(obstacle->next != NULL){
    add_obstacle(obstacle->next, xmax, ymax);
  }else{

    obstacle->next = create_obstacle(xmax, new_random_center(ymax));
  }

}