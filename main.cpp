#include "src/MoveGenerationController.h"
#include "src/Fen.h"

using namespace std;

int main(int argc, char** argv )
{
	shared_ptr<Board> board(new Board());
	shared_ptr<MoveStack> moveStack(new MoveStack(board));
	shared_ptr<AttackedSquare> attackedSquare(new AttackedSquare(board));
	shared_ptr<Fen> fen(new Fen(board));
	shared_ptr<MoveGenerationController> moveGenerationController(new MoveGenerationController(board, moveStack, attackedSquare));
	fen->import("r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1QKB1R w KQkq - 0 1");
	int bestMove = moveGenerationController->getBestMove(5);
    return 0;
}