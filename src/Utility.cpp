#include "Utility.h"
void showBitBoard(uint64_t bitboard) {
	cout << "@@@@@@@@@@@@@ BITBOARD @@@@@@@@@@@@" << endl;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (bitboard & getPieceBoard(x, y)) {
				cout << "X";
			} else {
				cout << "0";
			}
		}
		cout << endl;
	}
	cout << "@@@@@@@@@@@@@ BITBOARD @@@@@@@@@@@@" << endl;
}
void showMoveBoard(uint32_t move) {
	cout << "@@@@@@@@@@@@@ MOVEBOARD @@@@@@@@@@@@" << endl;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (xyToInt(x, y) == FROM(move)) {
				cout << "F";
			} else if (xyToInt(x, y) == TO(move)) {
				cout << "T";
			} else {
				cout << "0";
			}
		}
		cout << endl;
	}
	cout << "@@@@@@@@@@@@@ MOVEBOARD @@@@@@@@@@@@" << endl;
}