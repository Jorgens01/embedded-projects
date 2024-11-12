#include <stdint.h>
#include <stdio.h>

// Array to map types to characters
// TODO: If header file includes increase, switch to extern
static const char piece_chars[] = {'P', 'N', 'B', 'R', 'Q', 'K', 
                      'p', 'n', 'b', 'r', 'q', 'k'};

// Enum to represent boards squares
// We will use little-endian mapping
enum
{
    a1, b1, c1, d1, e1, f1, g1, h1,     // bits 0-7
    a2, b2, c2, d2, e2, f2, g2, h2,     // bits 8-15
    a3, b3, c3, d3, e3, f3, g3, h3,     // bits 16-23
    a4, b4, c4, d4, e4, f4, g4, h4,     // bits 24-31
    a5, b5, c5, d5, e5, f5, g5, h5,     // bits 32-39
    a6, b6, c6, d6, e6, f6, g6, h6,     // bits 40-47
    a7, b7, c7, d7, e7, f7, g7, h7,     // bits 48-55
    a8, b8, c8, d8, e8, f8, g8, h8      // bits 56-63

/*
Visual representation of bit numbers on chess board:

8   56 57 58 59 60 61 62 63    // Black's back rank
7   48 49 50 51 52 53 54 55    // Black's pawn rank
6   40 41 42 43 44 45 46 47
5   32 33 34 35 36 37 38 39
4   24 25 26 27 28 29 30 31
3   16 17 18 19 20 21 22 23
2   08 09 10 11 12 13 14 15    // White's pawn rank
1   00 01 02 03 04 05 06 07    // White's back rank

    a  b  c  d  e  f  g  h

// Compass map
noWe         north         noEa
        +7    +8    +9
            \  |  /
west    -1 <-  0 -> +1    east
            /  |  \
        -9    -8    -7
soWe         south         soEa

a-file             0x0101010101010101
h-file             0x8080808080808080
1st rank           0x00000000000000FF
8th rank           0xFF00000000000000
a1-h8 diagonal     0x8040201008040201
h1-a8 antidiagonal 0x0102040810204080
light squares      0x55AA55AA55AA55AA
dark squares       0xAA55AA55AA55AA55
*/


};

// Piece types an colors
enum PieceType
{
    WHITE_PAWNS, WHITE_KNIGHTS, WHITE_BISHOPS, WHITE_ROOKS, WHITE_QUEENS, WHITE_KING,
    BLACK_PAWNS, BLACK_KNIGHTS, BLACK_BISHOPS, BLACK_ROOKS, BLACK_QUEENS, BLACK_KING
};

typedef struct
{
    // Initialize all bitboards to 0
    uint64_t bitboards[12];
} Board;


// Getting function
int get_bit(const uint64_t bitboard, int square);

// Setting function
void set_bit(uint64_t *bitboard, int square);

// Popping function
void pop_bit(uint64_t *bitboard, int square);


/* For debugging */
// Print whole board representation
void print_board(const Board *board);

/* End of debugging functions */

void initialize_board(Board *board);


