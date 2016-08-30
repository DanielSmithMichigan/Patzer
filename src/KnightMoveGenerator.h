#ifndef KnightMoveGenerator_h
#define KnightMoveGenerator_h
	#include "MoveGenerator.h"
	#define KNIGHT_MOVES_SIZE 8

	using namespace std;

	class KnightMoveGenerator : public MoveGenerator{
		private:
			int knightMoves[8] = {ROWS(2) + 1, ROWS(2) - 1, ROWS(1) + 2, ROWS(1) - 2, ROWS(-1) + 2, ROWS(-1) - 2, ROWS(-2) + 1, ROWS(-2) - 1};
		public:
			KnightMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~KnightMoveGenerator();
			void generateMoves(int from);
	};
#endif