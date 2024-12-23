#include "board.hpp"

Board::Board()
{
    // initialize();
}

Board::~Board()
{
}

bool Board::getBit(U64 bitboard, Square square)
{
    return bitboard & (1ULL << static_cast<int>(square));
}

void Board::popBit(U64 &bitboard, Square square)
{
    bitboard &= ~(1ULL << static_cast<int>(square));
}

void Board::setBit(U64 &bitboard, Square square)
{
    bitboard |= (1ULL << static_cast<int>(square));
}

/*
void Board::initialize()
{
    // Initialize black pieces
    bitboards_[static_cast<size_t>(PieceType::BLACK_PAWNS)] = 0x000000000000FF00ULL;
    bitboards_[static_cast<size_t>(PieceType::BLACK_KNIGHTS)] = 0x0000000000000042ULL;
    bitboards_[static_cast<size_t>(PieceType::BLACK_BISHOPS)] = 0x0000000000000024ULL;
    bitboards_[static_cast<size_t>(PieceType::BLACK_ROOKS)] = 0x0000000000000081ULL;
    bitboards_[static_cast<size_t>(PieceType::BLACK_QUEENS)] = 0x0000000000000008ULL;
    bitboards_[static_cast<size_t>(PieceType::BLACK_KING)] = 0x0000000000000010ULL;

    // Initialize white pieces
    bitboards_[static_cast<size_t>(PieceType::WHITE_PAWNS)] = 0x00FF000000000000ULL;
    bitboards_[static_cast<size_t>(PieceType::WHITE_KNIGHTS)] = 0x4200000000000000ULL;
    bitboards_[static_cast<size_t>(PieceType::WHITE_BISHOPS)] = 0x2400000000000000ULL;
    bitboards_[static_cast<size_t>(PieceType::WHITE_ROOKS)] = 0x8100000000000000ULL;
    bitboards_[static_cast<size_t>(PieceType::WHITE_QUEENS)] = 0x0800000000000000ULL;
    bitboards_[static_cast<size_t>(PieceType::WHITE_KING)] = 0x1000000000000000ULL;
} 
*/


U64 Board::getBitboard(PieceType piece) const
{
    return bitboards_[piece];
}

void Board::printBitboard(U64 bitboard)
{
    // Print ranks from top to bottom (8 to 1)
    for (int rank = 0; rank <= 7; rank++) {
        std::cout << 8 - rank << " | "; // Print rank number
        // Print files from left to right (a to h)
        for (int file = 0; file < 8; file++) {
            // Calculate square index
            Square square = Square(rank * 8 + file);
            // Print '1' if bit is set, '.' if not
            std::cout << (getBit(bitboard, square) ? "1 " : ". ");
        }
        std::cout << '\n';
    }
    // Print file labels
    std::cout << "  -------------------------\n";
    std::cout << "    a b c d e f g h\n\n";
}
