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

    // Pawn attacks generations and precalculated attack tables
    static U64 genWhitePawnAttacks(Square square);
    static U64 genBlackPawnAttacks(Square square);

    /*static constexpr std::array<U64, 64> WHITE_PAWN_A_TABLE = []()
    {
        std::array<U64, 64> table {};
        for (int i = 0; i < 64; i++) {
            table[i] = genWhitePawnAttacks(static_cast<Square>(i));
        }
        return table;
    }();*/


    //static U64 generateKnightAttacks(Square square);

};


#endif // ATTACK_TABLES_HPP_