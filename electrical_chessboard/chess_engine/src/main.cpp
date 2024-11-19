#include "board.hpp"
#include "attack_tables.hpp"
#include <iostream>

int main()
{
    Board board;

    // Create bitboard of pawn attacks
    U64 bitboard = AttackTables::genWhitePawnAttacks(a4);

    board.printBitboard(bitboard);

    U64 bitboard_b = AttackTables::genBlackPawnAttacks(h4);

    board.printBitboard(bitboard_b);


    return 0;
}