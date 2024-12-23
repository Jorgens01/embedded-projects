#include "board.hpp"
#include "attack_tables.hpp"
#include <iostream>

int main()
{
    Board board;

    
    U64 bitboard_b = AttackTables::genQueenAttacks(d4);

    board.printBitboard(bitboard_b);


    return 0;
}