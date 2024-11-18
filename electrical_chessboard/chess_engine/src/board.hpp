#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <cstdint>
#include <array>
#include <string_view>
#include <iostream>

/**
 * @brief Represents squares on the chess board using little-endian rank-file mapping
 * 
 * The mapping follows this pattern:
 * 8 | 56 57 58 59 60 61 62 63
 * 7 | 48 49 50 51 52 53 54 55
 * 6 | 40 41 42 43 44 45 46 47
 * 5 | 32 33 34 35 36 37 38 39
 * 4 | 24 25 26 27 28 29 30 31
 * 3 | 16 17 18 19 20 21 22 23
 * 2 | 08 09 10 11 12 13 14 15
 * 1 | 00 01 02 03 04 05 06 07
 *   -------------------------
 *     a  b  c  d  e  f  g  h
 */

enum class Square : uint8_t 
{
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
};

/**
 * @brief Represent different piece types and their colors
 */

enum class PieceType : uint8_t 
{
    WHITE_PAWNS, WHITE_KNIGHTS, WHITE_BISHOPS, WHITE_ROOKS, WHITE_QUEENS, WHITE_KING,
    BLACK_PAWNS, BLACK_KNIGHTS, BLACK_BISHOPS, BLACK_ROOKS, BLACK_QUEENS, BLACK_KING
};

/**
 * @brief Type alias for bitboard representation as we will use it a lot
 */

using U64 = uint64_t;



/**
 * @brief Main class for board representation
 */
class Board
{
private:
    /* data */
    std::array<U64, 12> bitboards_;
    
    // Piece representations by chars
    static constexpr std::array<char, 12> PIECE_CHARS_ = 
    {
        'P', 'N', 'B', 'R', 'Q', 'K',
        'p', 'n', 'b', 'r', 'q', 'k'
    };

    // Bitboard constants

public:
    Board();
    ~Board();

    /**
     * @brief Gets the value of specific bit in a bitboard
     * @param bitboard: The bitboard to check
     * @param square: The square to check
     * @return true if bit is set, false otherwise
     */
    static inline bool getBit(U64 bitboard, Square square);

    /**
     * @brief Clears a bit in specific bitboard
     * @param bitboard to modify
     * @param square to clear
     */
    static inline void popBit(U64 bitboard, Square square);

    /**
     * @brief Sets a bit in specified bitboard
     * @param bitboard to modify
     * @param square to set
     */
    static inline void setBit(U64 bitboard, Square square);

    void initialize();

    void print() const;

    U64 getBitboard(PieceType piece) const;
};



#endif // BOARD_HPP_
