#ifndef Utility_h
#define Utility_h
	#include <stdint.h>
	#include <iostream>
	#include "Move.h"
	#include "Globals.h"
	using namespace std;
	inline int xyToInt(int x, int y) {
		return y * 8 + x;
	}
	inline uint64_t getPieceBoard(int i) {
		return 0x8000000000000000 >> i;
	}
	inline uint64_t getPieceBoard(int x, int y) {
		return getPieceBoard(xyToInt(x, y));
	}
	inline uint32_t getEnPassantLocation(const uint32_t &from, const uint32_t &to) {
		return xyToInt(to - ROWS(GET_ROW(to)), GET_ROW(from));
	}
	void showBitBoard(uint64_t bitboard);
	void showMoveBoard(uint32_t move);
#endif