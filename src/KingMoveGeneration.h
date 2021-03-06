#ifndef KingMoveGeneration_h
#define KingMoveGeneration_h
	
	#include "SquareAttacked.h"
	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR> inline void generateCastle();
	template <uint32_t COLOR, bool QUIESCENCE> inline void generateAdjacentKingMoves();
	template <uint32_t COLOR, bool QUIESCENCE> inline void generateKingMoves();


	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateKingMoves() {
		generateAdjacentKingMoves<COLOR, QUIESCENCE>();
		if (!QUIESCENCE) {
			generateCastle<COLOR>();
		}
	}

	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateAdjacentKingMoves() {
		uint64_t kings = Board::pieces[KING] & Board::colors[COLOR];
		uint64_t kingsMask = Board::pieces[KING] & Board::colors[COLOR];
		if (kings) {
			uint32_t kingLocation = popBit(kings);
			uint64_t allKingMoves = BitBoard::getAdjacentKingMoves<COLOR>(kingLocation, Board::colors[COLOR]);
			uint64_t captureMoves = Board::colors[OPPOSING_COLOR(COLOR)] & allKingMoves;
			while(captureMoves) {
				uint32_t captureMove = popBit(captureMoves);
				if (squareAttacked<OPPOSING_COLOR(COLOR)>(captureMove, kingsMask)) {
					continue;
				}
				MoveStack::instance->checkAndPushMove(COLOR, CLASSIC, kingLocation, captureMove);
			}
			if (!QUIESCENCE) {
				uint64_t nonCaptureMoves = ~Board::colors[OPPOSING_COLOR(COLOR)] & allKingMoves;
				while(nonCaptureMoves) {
					uint32_t nonCaptureMove = popBit(nonCaptureMoves);
					if (squareAttacked<OPPOSING_COLOR(COLOR)>(nonCaptureMove, kingsMask)) {
						continue;
					}
					MoveStack::instance->checkAndPushMove(COLOR, CLASSIC, kingLocation, nonCaptureMove);
				}
			}
		}
	}

	template <uint32_t COLOR>
	inline void generateCastle() {
		uint64_t rooks = Board::pieces[ROOK] & Board::colors[COLOR];
		uint64_t kings = Board::pieces[KING] & Board::colors[COLOR];
		uint32_t kingLocation = popBit(kings);
		if (Board::currentState->checkers) {
			return;
		}
		if (COLOR == WHITE
			&& (Board::currentState->castlingRights & WHITE_CAN_CASTLE_RIGHT)
			&& !(Board::occupiedSquares & CASTLE_RIGHT_OCCUPIED & row<7>())
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(61)
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(62)) {
			MoveStack::instance->checkAndPushMove(COLOR, CASTLE, kingLocation, 62);
		}
		if (COLOR == WHITE
			&& (Board::currentState->castlingRights & WHITE_CAN_CASTLE_LEFT)
			&& !(Board::occupiedSquares & CASTLE_LEFT_OCCUPIED & row<7>())
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(58)
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(59)) {
			MoveStack::instance->checkAndPushMove(COLOR, CASTLE, kingLocation, 58);
		}
		if (COLOR == BLACK
			&& (Board::currentState->castlingRights & BLACK_CAN_CASTLE_RIGHT)
			&& !(Board::occupiedSquares & CASTLE_RIGHT_OCCUPIED & row<0>())
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(5)
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(6)) {
			MoveStack::instance->checkAndPushMove(COLOR, CASTLE, kingLocation, 6);
		}

		if (COLOR == BLACK
			&& (Board::currentState->castlingRights & BLACK_CAN_CASTLE_LEFT)
			&& !(Board::occupiedSquares & CASTLE_LEFT_OCCUPIED & row<0>())
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(2)
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(3)) {
			MoveStack::instance->checkAndPushMove(COLOR, CASTLE, kingLocation, 2);
		}
	}
#endif