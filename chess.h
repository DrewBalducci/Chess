/* * * * * * * * * * * * * * * * * * * *
 *
 * chess.h - Authored by Drew Balducci - Apr 29, 2026
 *
 * Definition of chess class. Handles overhead of game and coordinating
 * players while logic is handled by chessboard class
 *
 * * * * * * * * * * * * * * * * * * * */


#include "chessboard.h"
#include <stdint.h>

#define ROW_1   0xFF
#define ROW_2   ROW_1 << 8
#define ROW_3   ROW_2 << 8
#define ROW_4   ROW_3 << 8
#define ROW_5   ROW_4 << 8
#define ROW_6   ROW_5 << 8
#define ROW_7   ROW_6 << 8
#define ROW_8   ROW_7 << 8

#define COL_A   0x0101010101010101
#define COL_B   COL_A << 1
#define COL_C   COL_B << 1
#define COL_D   COL_C << 1
#define COL_E   COL_D << 1
#define COL_F   COL_E << 1
#define COL_G   COL_F << 1
#define COL_H   COL_G << 1




class Chess
{
public:
    Chess();
    bool make_move();

private:
    Chessboard board;
    void reset_board();

};






