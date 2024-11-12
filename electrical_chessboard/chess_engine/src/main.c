#include "board.h"

#include <stdio.h>

int main()
{
    /* Create a struct of a board*/
    Board board = {0};

    initialize_board(&board);

    print_board(&board);
    
    
    return 0;
}