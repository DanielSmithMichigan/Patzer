#ifndef Board_h
#define Board_h
	#include "Square.h"
	#include "globals.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <vector>

	using namespace std;

	class Board {
		private:
			void initialize();
		public:
			Board();
			~Board();
			uint64_t occupiedSpace = 0;
			uint64_t pieceBoards[2][6];
			uint64_t colorBoards[2];
			void place(int color, int type, int x, int y);
			void remove(int color, int type, int x, int y);
			void move(int xBefore, int yBefore, int xAfter, int yAfter);
			void removeIndicatorColors();
			void doForAllMatches(int x, int y, int action);
			void doForAllMatches(uint64_t bitboard, int action);
			int getPieceAtSquare(int x, int y);
			vector<vector<unique_ptr<Square>>> squares;
	};
#endif