#ifndef CONSTANTS_H_IN
#define CONSTANTS_H_IN

#include <stdio.h>

// Unicode
#define B_PAWN_UCS 0x2659
#define B_ROOK_UCS 0x2656
#define B_KNIGHT_UCS 0x2658
#define B_BISHOP_UCS 0x2657
#define B_QUEEN_UCS 0x2655
#define B_KING_UCS 0x2654

#define W_PAWN_UCS 0x265F
#define W_ROOK_UCS 0x265C
#define W_KNIGHT_UCS 0x265E
#define W_BISHOP_UCS 0x265D
#define W_QUEEN_UCS 0x265B
#define W_KING_UCS 0x265A

// Board
//#define W_SQUARE_COL 0
//#define B_SQUARE_COL
#define SQUARE_HEIGHT 4
#define SQUARE_WIDTH 8
#define BOARD_BORDER_WIDTH (SQUARE_WDITH * 1)
#define BOARD_BORDER_HEIGHT (SQUARE_HEIGHT * 1)
#define BOARD_WIDTH (SQUARE_WIDTH * 8)
#define BOARD_HEIGHT (SQUARE_HEIGHT * 8)

// Debug helpers
#define PRINT_PIECE( COL, PIECE ) printf( "%lc\n", COL##_##PIECE##_UCS );

static inline void print_pieces()
{
	PRINT_PIECE( B, PAWN );
	PRINT_PIECE( B, ROOK );
	PRINT_PIECE( B, KNIGHT );
	PRINT_PIECE( B, BISHOP );
	PRINT_PIECE( B, QUEEN );
	PRINT_PIECE( B, KING );

	PRINT_PIECE( W, PAWN );
	PRINT_PIECE( W, ROOK );
	PRINT_PIECE( W, KNIGHT );
	PRINT_PIECE( W, BISHOP );
	PRINT_PIECE( W, QUEEN );
	PRINT_PIECE( W, KING );
}

#endif // CONSTANTS_H_IN
