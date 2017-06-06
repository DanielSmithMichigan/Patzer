#ifndef Search_cpp
#define Search_cpp
	#include "Search.h"

	Search *Search::instance = new Search();

	Search::Search() {
	}

	Search::~Search() {

	}

	uint32_t Search::iterativeDeepening(string fen, int maxDepth) {
		int currentDepth = 1;
		uint32_t bestMove;
		while(true) {
			if (currentDepth > maxDepth) {
				return bestMove;
			}
			Fen::import(fen);
			MoveStack::instance->reset();
			bestMove = MoveGenerationController::instance->getBestMove(currentDepth++);
			MoveGenerationController::instance->showStats();
		}
		return bestMove;
	}
#endif