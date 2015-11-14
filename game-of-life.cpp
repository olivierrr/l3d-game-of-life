
#include <stdlib.h> /* malloc, free */
#include "game-of-life.h"

GameOfLife::GameOfLife(int _size) {
  size = _size;

  board = (int *)malloc(sizeof(int)*size*size*size);
  if (board == NULL) {
    exit(1);
  }

  int	x, y, z;
  for (x = 0; x < size; x++) for (y = 0; y < size; y++) for (z = 0; z < size; z++) {
    board[x][y][z] = random(5) == 1 ? 1 : 0;
  }
}

GameOfLife::~GameOfLife() {
  free(board);
}

void GameOfLife::tick() {
  int	x, y, z, adjacents, newboard[size][size][size];

	/* for each cell, apply the rules of Life */
	for (x = 0; x < SIDE; x++) for (y = 0; y < SIDE; y++) for (z = 0; z < SIDE; z++) {
		adjacents = getAdjacents(x, y, z);
		if (adjacents == 2) newboard[x][y][z] = board[x][y][z];
		if (adjacents == 3) newboard[x][y][z] = 1;
		if (adjacents < 2) newboard[x][y][z] = 0;
		if (adjacents > 3) newboard[x][y][z] = 0;
	}

	/* copy the new board back into the old board */
	for (x = 0; x < SIDE; x++) for (y = 0; y < SIDE; y++) for (z = 0; z < SIDE; z++) {
		board[x][y][z] = newboard[x][y][z];
	}
}

int * GameOfLife::getState() {
  return board;
}

int GameOfLife::getAdjacents(int x, int y, int z) {
  // todo
}
