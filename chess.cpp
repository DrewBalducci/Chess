/* * * * * * * * * * * * * * * * * * * *
 *
 * chess.cpp - Authored by Drew Balducci - Apr 29, 2026
 *
 * Handle logic of chess game from moves input externally using bitboards
 * Intended to be interfaced later with python or Go/Rust server programs
 *
 * * * * * * * * * * * * * * * * * * * */


// ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** //
//                           Chess                             //
// ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** //

#include "chess.h"
#include "chessboard.h"

Chess::Chess(){
    board = Chessboard();
}

void Chess::reset_board(){
    return;
}

bool Chess::make_move(){
    return false;
}

