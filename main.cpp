#include "src/BitBoard.h"
#include "src/Fen.h"
#include "src/MoveGenerationController.h"
#include <stdlib.h>

using namespace std;
int main(int argc, char** argv )
{
	BitBoard::InitRookBitBoards();
	BitBoard::InitBishopBitBoards();
	MoveStack::instance->reset();
	Fen::import("r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1QKB1R w KQkq - 0 1"); // benchmark
	uint32_t bestMove = MoveGenerationController::getBestMove(5);
	// cout << "FROM: " << FROM(bestMove)
	//      << " TO: " << TO(bestMove) << endl;
    return 0;
}