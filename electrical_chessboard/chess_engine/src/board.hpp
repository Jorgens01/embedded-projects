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

enum Square : uint8_t 
{
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1

};

/**
 * @brief Represent different piece types and their colors
 */

enum PieceType : uint8_t 
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
    static bool getBit(U64 bitboard, Square square);

    /**
     * @brief Clears a bit in specific bitboard
     * @param bitboard to modify
     * @param square to clear
     */
    static void popBit(U64 &bitboard, Square square);

    /**
     * @brief Sets a bit in specified bitboard
     * @param bitboard to modify
     * @param square to set
     */
    static void setBit(U64 &bitboard, Square square);

    /* Initialize normal game of chess 
    void initialize();
    */


    /* Get specific bitboard */
    U64 getBitboard(PieceType piece) const;

    static void printBitboard(U64 bitboard);
};



#endif // BOARD_HPP_
