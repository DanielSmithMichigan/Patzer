#ifndef Move_h
#define Move_h
	#define MOVE(from,to,captured,enPassant,firstMove,promotedPiece,castle) ( from | (to << 8) | (captured << 16) | (enPassant << 20) | (firstMove << 21) | (promotedPiece << 22) | (castle << 26))
	// #define MOVE(x1,y1,x2,y2) ( x1 | (y1 << 4) | (x2 << 8) | (y2 << 12))
	#define FROM(m) ((m) & 0xFF)
	#define TO(m) ((m>>8) & 0xFF)
	#define PROMOTEDPIECE(m) ((m >> 22) & 0xF)
	#define FIRST_MOVE(m) ((m >> 21) & 0x1)
	#define CAPTURED_PIECE(m) ((m >> 16) & 0xF)
#endif