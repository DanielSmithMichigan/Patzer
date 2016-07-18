#ifndef Board_h
#define Board_h
	#include "Square.h"
	#include "globals.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <vector>
	#include "RookMoveGenerator.h"
	#include "KnightMoveGenerator.h"

	using namespace std;

	class Board {
		private:
			unique_ptr<RookMoveGenerator> rookMoveGenerator;
			unique_ptr<KnightMoveGenerator> knightMoveGenerator;
			uint64_t WhitePawns = 0;
			uint64_t WhiteRooks = 0;
			uint64_t WhiteKnights = 0;
			uint64_t WhiteBishops = 0;
			uint64_t WhiteQueens = 0;
			uint64_t WhiteKings = 0;
			uint64_t BlackPawns = 0;
			uint64_t BlackRooks = 0;
			uint64_t BlackKnights = 0;
			uint64_t BlackBishops = 0;
			uint64_t BlackQueens = 0;
			uint64_t BlackKings = 0;
			uint64_t OccupiedSpace = 0;
			uint64_t WhitePieces = 0;
			uint64_t BlackPieces = 0;
		public:
			Board();
			~Board();
			void reset();
			void place(uint64_t color, uint64_t type, int x, int y);
			void removeIndicatorColors();
			void highlightAllMatches(uint64_t bitboard);
			uint64_t& getPieceBoard(uint64_t color, uint64_t type);
			uint64_t& getColorBoard(uint64_t color);
			void highlightMovesAt(int x, int y);
			vector<vector<unique_ptr<Square>>> squares;
	};
#endif