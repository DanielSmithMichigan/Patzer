#ifndef MoveGenerationController_h
#define MoveGenerationController_h
	#include "Board.h"
	#include "PawnMoveGeneration.h"
	#include "BishopMoveGeneration.h"
	#include "RookMoveGeneration.h"
	

	using namespace std;

	class MoveGenerationController {
		private:
		public:
			MoveGenerationController();
			~MoveGenerationController();
			static void generateAllMoves();
	};
#endif