#include "attack_tables.hpp"

U64 AttackTables::genWhitePawnAttacks(Square square)
{
    U64 position = 1ULL << square;
    U64 attacks = 0ULL;

    // Left diagonal and prevent wrap-around on file h
    attacks |= ( (position >> 7) & ~FILE_A);

    // Right diagonal and prevent wrap-around on file a
    attacks |= ( (position >> 9) & ~FILE_H);
    return attacks;
}

U64 AttackTables::genBlackPawnAttacks(Square square)
{
    U64 position = 1ULL << square;
    U64 attacks = 0ULL;

    // Left diagonal and prevent wrap-around on file h
    attacks |= ( (position << 7) & ~FILE_H);

    // Right diagonal and prevent wrap-around on file a
    attacks |= ( (position << 9) & ~FILE_A);
    return attacks;
}

U64 AttackTables::genKnightAttacks(Square square)
{
    U64 position = 1ULL << square;
    U64 attacks = 0ULL;

    attacks |= ( (position << 6) & ~(FILE_G | FILE_H) );
    attacks |= ( (position << 10) & ~(FILE_A | FILE_B) );
    attacks |= ( (position << 15) & ~(FILE_H) );
    attacks |= ( (position << 17) & ~(FILE_A) );

    attacks |= ( (position >> 6) & ~(FILE_A | FILE_B) );
    attacks |= ( (position >> 10) & ~(FILE_G | FILE_H) );
    attacks |= ( (position >> 15) & ~(FILE_A) );
    attacks |= ( (position >> 17) & ~(FILE_H) );    

    return attacks;
}

U64 AttackTables::genBishopAttacks(Square square)
{
    U64 position = 1ULL << square;
    U64 attacks = 0ULL;
    
    // Northeast
    for (int i = 1; i < 8; i++) {
        if (((position >> (i * 7)) & ~(FILE_A)) == 0) break;
        attacks |= position >> (i * 7);
    }

    // Northwest
    for (int i = 1; i < 8; i++) {
        if (((position >> (i * 9)) & ~(FILE_H)) == 0) break;
        attacks |= position >> (i * 9);
    }

    // Southeast
    for (int i = 1; i < 8; i++) {
        if (((position << (i * 7)) & ~(FILE_H)) == 0) break;
        attacks |= position << (i * 7);
    }

    // Southwest
    for (int i = 1; i < 8; i++) {
        if (((position << (i * 9)) & ~(FILE_A)) == 0) break;
        attacks |= position << (i * 9);
    }

    return attacks;
    
}

U64 AttackTables::genRookAttacks(Square square)
{

    // Calculate rank and file masks
    U64 rankMask = rankMasks[square / 8];
    U64 fileMask = fileMasks[square % 8];

    // Combine and exclude the current square
    U64 position = 1ULL << square;
    U64 attacks = (rankMask | fileMask) & ~position;

    return attacks;
}

U64 AttackTables::genQueenAttacks(Square square)
{
    U64 attacks = 0ULL;
    U64 rook_attacks = genRookAttacks(square);
    U64 diagonal_attacks = genBishopAttacks(square);

    return attacks = rook_attacks | diagonal_attacks;
}
