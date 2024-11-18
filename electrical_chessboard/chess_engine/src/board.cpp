#include "board.hpp"

Board::Board()
{
    initialize();
}

Board::~Board()
{
}

bool Board::getBit(U64 bitboard, Square square)
{
    return (bitboard & (1ULL << static_cast<int>(square))) != 0;
}

void Board::popBit(U64 bitboard, Square square)
{
    if (getBit(bitboard, square)) {
        bitboard ^= (1ULL << static_cast<int>(square));
    }
}

void Board::setBit(U64 bitboard, Square square)
{
    bitboard |= (1ULL << static_cast<int>(square));
}

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

void Board::print() const
{
    std::cout << '\n';
    
    for (int rank = 0; rank < 8; ++rank) {
        std::cout << ' ' << 8 - rank << ' ';
        
        for (int file = 0; file < 8; ++file) {
            Square square = static_cast<Square>(rank * 8 + file);
            char piece_to_print = '.';
            
            for (size_t piece = 0; piece < PIECE_CHARS_.size(); ++piece) {
                if (getBit(bitboards_[piece], square)) {
                    piece_to_print = PIECE_CHARS_[piece];
                    break;
                }
            }
            
            std::cout << ' ' << piece_to_print;
        }
        std::cout << '\n';
    }
    
    std::cout << "\n a b c d e f g h\n";
}

U64 Board::getBitboard(PieceType piece) const
{
    return bitboards_[static_cast<size_t>(piece)];
}
