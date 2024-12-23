#ifndef ATTACK_TABLES_HPP_
#define ATTACK_TABLES_HPP_

#include "board.hpp"
#include <array>
#include <cstdint>

class AttackTables
{
private:
    

public:

    // Bitboard constants masking
    static constexpr U64 FILE_A = 0x0101010101010101ULL;
    static constexpr U64 FILE_B = 0x0202020202020202ULL;
    static constexpr U64 FILE_H = 0x8080808080808080ULL;
    static constexpr U64 FILE_G = 0x4040404040404040ULL;
    static constexpr U64 RANK_8 = 0xFF00000000000000ULL;
    static constexpr U64 RANK_1 = 0x00000000000000FFULL;

    // Precomputed masks for ranks and files
    static constexpr U64 rankMasks[8] = {
        0xFFULL, 0xFF00ULL, 0xFF0000ULL, 0xFF000000ULL,
        0xFF00000000ULL, 0xFF0000000000ULL, 0xFF000000000000ULL, 0xFF00000000000000ULL
    };
    static constexpr U64 fileMasks[8] = {
        0x0101010101010101ULL, 0x0202020202020202ULL, 0x0404040404040404ULL,
        0x0808080808080808ULL, 0x1010101010101010ULL, 0x2020202020202020ULL,
        0x4040404040404040ULL, 0x8080808080808080ULL
    };


    // Pawn attacks generations and precalculated attack tables
    static U64 genWhitePawnAttacks(Square square);
    static U64 genBlackPawnAttacks(Square square);

    static U64 genKnightAttacks(Square square);
    static U64 genBishopAttacks(Square square);
    static U64 genRookAttacks(Square square);
    static U64 genQueenAttacks(Square square);

};


#endif // ATTACK_TABLES_HPP_