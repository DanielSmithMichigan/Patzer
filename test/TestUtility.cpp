#include "TestUtility.h"
void assertMoveExists(string fenString, string param) {
	bool found = false;
	Fen* fen = new Fen();
	if (param != "quiescence") {
		MoveGenerationController::instance->generateAllMoves<false>();
	} else {
		MoveGenerationController::instance->generateAllMoves<true>();
	}
	vector<string> fensFound;
	while (uint32_t currentMove = MoveStack::instance->pop()) {
		Board::doMove(currentMove);
		string newFen = fen->getBoardSquares();
		fensFound.push_back(newFen);
		if (newFen.compare(fenString) == 0) {
			found = true;
		}
		Board::undoMove();
	}
	ASSERT_TRUE(found) << fenString << " should be an available move."
	  << " Moves found: " << endl
	  << boost::algorithm::join(fensFound, "\n");
}
void assertNotMoveExists(string fenString, string param) {
	bool found = false;
	Fen* fen = new Fen();
	if (param != "quiescence") {
		MoveGenerationController::instance->generateAllMoves<false>();
	} else {
		MoveGenerationController::instance->generateAllMoves<true>();
	}
	while (uint32_t currentMove = MoveStack::instance->pop()) {
		Board::doMove(currentMove);
		if (fen->getBoardSquares().compare(fenString) == 0) {
			found = true;
		}
		Board::undoMove();
	}
	ASSERT_FALSE(found) << fenString << " should not be an available move.";
}
void showAllMoves() {
	Fen* fen = new Fen();
	MoveGenerationController::instance->generateAllMoves<false>();
	while (uint32_t currentMove = MoveStack::instance->pop()) {
		Board::doMove(currentMove);
		cout << fen->getBoardSquares() << endl;
		Board::undoMove();
	}
}
void assertMoveCount(int assertedAmount) {
	int moveCount = 0;
	Fen* fen = new Fen();
	vector<string> fensFound;
	MoveGenerationController::instance->generateAllMoves<false>();
	while (uint32_t currentMove = MoveStack::instance->pop()) {
		moveCount++;
		fensFound.push_back(fen->getBoardSquares());
	}
	ASSERT_EQ(moveCount, assertedAmount) << "Should have generated the expected number of moves" << endl
	  << " Moves found: " << endl
	  << boost::algorithm::join(fensFound, "\n");
}