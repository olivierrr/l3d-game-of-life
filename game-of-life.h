
/*
  RULES:

	1.STASIS : If, for a given cell, the number of on neighbours is
	exactly two, the cell maintains its status quo into the next
	generation. If the cell is on, it stays on, if it is off, it stays off.

	2.GROWTH : If the number of on neighbours is exactly three, the cell
	will be on in the next generation. This is regardless of the cell's current state.

	3.DEATH : If the number of on neighbours is 0, 1, 4-8, the cell will
	be off in the next generation.
*/

class GameOfLife {
 public:
  GameOfLife(int size);
  ~GameOfLife();

  void tick();
  int * getState();

 private:
   int * board;
   int size;
   int getAdjacents(int x, int y, int z);
};
