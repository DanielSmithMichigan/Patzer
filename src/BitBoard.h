#ifndef BitBoard_h
#define BitBoard_h
	#include "Utility.h"
	#include <stdint.h>
	#include <iostream>

	using namespace std;

	namespace BitBoard {
		extern uint64_t RookOccupancyMasks[64];
		extern uint64_t BishopOccupancyMasks[64];
		extern uint64_t RookMagics[64];
		extern uint64_t BishopMagics[64];
		extern uint64_t *RookPointers[64];
		extern uint64_t *BishopPointers[64];
		extern uint64_t RookAttacks[102400];
		extern uint64_t BishopAttacks[5248];
		extern uint64_t RookShifts[64];
		extern uint64_t BishopShifts[64];

		void InitBitBoards();
		void InitRookBitBoards();
		void InitBishopBitBoards();
	}
#endif