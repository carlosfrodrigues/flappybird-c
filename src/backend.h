#include <stdbool.h>

typedef struct {
  int x;
  int y;
  bool status_jumping;
} Bird;

struct Obstacle{
  int randomCenter;
  int x;
  struct Obstacle *next;
};

typedef struct Obstacle Obstacle;

typedef struct {
  Bird *bird;
  Obstacle *obstacle;
  int xmax;
  int ymax;
  int score;
} Game;

Obstacle* create_obstacle(int xmax, int randomCenter);
Bird* create_bird(int xmax, int ymax);
Game* create_game(int xmax, int ymax);
int new_random_center(int ymax);
//bool collision(Bird* bird, Obstacle* obstacle);
void move_obstacle(Obstacle* obstacle);
bool move_game(Game* game, bool isKeyPressed);
Obstacle* destroy_obstacle(Obstacle* obstacle);
void add_obstacle(Obstacle* obstacle, int xmax, int ymax);
bool is_obstacle_in_the_middle(Obstacle* obstacle, int xmax);
