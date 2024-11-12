#include "board.h"

// Helper functions
int get_bit(const uint64_t bitboard, int square)
{
    return (bitboard & (1ULL << square)) ? 1 : 0;
}

// Set bit to the pointed bitboard
void set_bit(uint64_t *bitboard, int square)
{
    *bitboard |= (1ULL << square);
}

void pop_bit(uint64_t *bitboard, int square)
{
    get_bit(*bitboard, square) ? *bitboard ^= (1ULL << square) : 0;
}

void print_board(const Board *board)
{
    printf("\n");

    int square, rank, file, piece;
    char piece_to_print;

    // Loop ranks
    for (rank = 0; rank < 8; rank++)
    {
        // Print ranks
        printf(" %d ", 8 - rank);

        // Loop files
        for (file = 0; file < 8; file++)
        {
            // Convert into square index
            square = rank * 8 + file;
            piece_to_print = '.'; // Print empty square

            for (piece = 0; piece < 12; piece++)
            {
                if (get_bit(board->bitboards[piece], square))
                {
                    piece_to_print = piece_chars[piece];
                    break;
                }
            }
            printf(" %c", piece_to_print); // Print the piece
        }

        // Print new line
        printf("\n");
    }

    // Also print board files at the bottom of the board
    printf("\n    a b c d e f g h\n");
}

void initialize_board(Board *board)
{
    // Initialize white pieces
    board->bitboards[BLACK_PAWNS] = 0x000000000000FF00;
    board->bitboards[BLACK_KNIGHTS] = 0x0000000000000042;
    board->bitboards[BLACK_BISHOPS] = 0x0000000000000024;
    board->bitboards[BLACK_ROOKS] = 0x0000000000000081;
    board->bitboards[BLACK_QUEENS] = 0x0000000000000008;
    board->bitboards[BLACK_KING] = 0x0000000000000010;

    // Initialize black pieces
    board->bitboards[WHITE_PAWNS] = 0x00FF000000000000;
    board->bitboards[WHITE_KNIGHTS] = 0x4200000000000000;
    board->bitboards[WHITE_BISHOPS] = 0x2400000000000000;
    board->bitboards[WHITE_ROOKS] = 0x8100000000000000;
    board->bitboards[WHITE_QUEENS] = 0x0800000000000000;
    board->bitboards[WHITE_KING] = 0x1000000000000000;
}
