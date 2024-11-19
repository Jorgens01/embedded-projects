#include "attack_tables.hpp"
/*
U64 AttackTables::generateKnightAttacks(Square square)
{
    U64 attacks = 0ULL;

    // Shifting and masking to generate moves
    attacks |= ( (static_cast<int>(square) << 6) & ~(FILE_G | FILE_H) );
    attacks |= ( (static_cast<int>(square) << 10) & ~(FILE_A | FILE_B) );
    attacks |= ( (static_cast<int>(square) << 15) & ~FILE_H);
    attacks |= ( (static_cast<int>(square) << 17) & ~FILE_A);

    attacks |= ( (static_cast<int>(square) >> 6) & ~(FILE_A | FILE_B) );
    attacks |= ( (static_cast<int>(square) >> 10) & ~(FILE_G | FILE_H) );
    attacks |= ( (static_cast<int>(square) >> 15) & ~FILE_A);
    attacks |= ( (static_cast<int>(square) >> 17) & ~FILE_H);
    
    return attacks;
}
*/

U64 AttackTables::genWhitePawnAttacks(Square square)
{
    U64 position = 1ULL << static_cast<int>(square);
    U64 attacks = 0ULL;

    // Left diagonal and prevent wrap-around on file h
    attacks |= ( (position >> 7) & ~FILE_A);

    // Right diagonal and prevent wrap-around on file a
    attacks |= ( (position >> 9) & ~FILE_H);
    return attacks;
}

U64 AttackTables::genBlackPawnAttacks(Square square)
{
    U64 position = 1ULL << static_cast<int>(square);
    U64 attacks = 0ULL;

    // Left diagonal and prevent wrap-around on file h
    attacks |= ( (position << 7) & ~FILE_H);

    // Right diagonal and prevent wrap-around on file a
    attacks |= ( (position << 9) & ~FILE_A);
    return attacks;
}
