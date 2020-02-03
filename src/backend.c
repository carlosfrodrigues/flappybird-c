#include "backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "frontend.h"

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
  if(obstacle->next != NULL){
    move_obstacle(obstacle->next);
  }
}

bool move_game(Game* game, bool isKeyPressed){
  if(isKeyPressed == true){
      game->bird->y = game->bird->y-2;
  }else{
    game->bird->y = game->bird->y+1;
  }
  move_obstacle(game->obstacle);
  if(game->obstacle->x == game->xmax/2){
    add_obstacle(game->obstacle, game->xmax, game->ymax);
  }
  else if(game->obstacle->x < game->xmax/2){
      if(game->obstacle->next->x == game->xmax/2){
        add_obstacle(game->obstacle->next, game->xmax, game->ymax);
        /* 
        Obstacle* obstacleFirst = game->obstacle;
        game->obstacle = game->obstacle->next;
        free(obstacleFirst);*/
        //destroy_obstacle(game->obstacle);
        game->obstacle = destroy_obstacle(game->obstacle);
      }
  }
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
Obstacle* destroy_obstacle(Obstacle* obstacle){
  if(obstacle == NULL)
    return NULL;

  Obstacle* obstacleFirst = obstacle;
  obstacle = obstacle->next;
  free(obstacleFirst);
  return obstacle;

}

void add_obstacle(Obstacle* obstacle, int xmax, int ymax){
  if(obstacle->next != NULL){
    add_obstacle(obstacle->next, xmax, ymax);
  }else{
    obstacle->next = create_obstacle(xmax, new_random_center(ymax));
    
  }
}