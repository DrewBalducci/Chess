/* * * * * * * * * * * * * * * * * * * *
 *
 * chessboard.cpp - Authored by Drew Balducci - May 09, 2026
 *
 * Chessboard class to handle internal logic of chess game
 *
 * * * * * * * * * * * * * * * * * * * */

#include "chessboard.h"

Chessboard::Chessboard(){
    reset_board();
}
void Chessboard::reset_board(){
    for (uint8_t ii=0; ii<8; ii++){
        set_square( {1,ii}, {WHITE,PAWN} );
        set_square( {7,ii}, {BLACK,PAWN} );
    }
    set_square( {0,4}, {WHITE,KING} );
    set_square( {7,4}, {BLACK,KING} );

    set_square( {0,3}, {WHITE,QUEEN} );
    set_square( {7,3}, {BLACK,QUEEN} );
        
    set_square( {0,0}, {WHITE,ROOK} );
    set_square( {7,0}, {BLACK,ROOK} );
    set_square( {0,7}, {WHITE,ROOK} );
    set_square( {7,7}, {BLACK,ROOK} );
        
    set_square( {0,1}, {WHITE,KNIGHT} );
    set_square( {7,1}, {BLACK,KNIGHT} );
    set_square( {0,6}, {WHITE,KNIGHT} );
    set_square( {7,6}, {BLACK,KNIGHT} );

    set_square( {0,2}, {WHITE,BISHOP} );
    set_square( {7,2}, {BLACK,BISHOP} );
    set_square( {0,5}, {WHITE,BISHOP} );
    set_square( {7,5}, {BLACK,BISHOP} );
}

uint64_t Chessboard::valid_moves(Square square){
    Piece piece = get_piece(square);
    switch (piece.type){
        case KING:
            return king_moves(square, piece.color);
        case QUEEN:
            return queen_moves(square, piece.color);
        case ROOK:
            return rook_moves(square, piece.color);
        case BISHOP:
            return bishop_moves(square, piece.color);
        case KNIGHT:
            return knight_moves(square, piece.color);
        case PAWN:
            return pawn_moves(square, piece.color);
        default:
            return 0;
    }
}

uint16_t Chessboard::get_piece_id(Piece piece){
    uint16_t pieceVal = piece.type;
    pieceVal += piece.color << 8;
    return pieceVal; // Lower byte is the piece 0-5 and top byte is color 0-1
}


bool Chessboard::move_piece(Square from, Square to){
    uint64_t squareInt = (1 << from.col) << (8 * from.row);
    if (squareInt & valid_moves(from)){
        Piece piece = get_piece(from);
        set_square(to, piece);
        clr_square(from);
        return true;
    } else {
        return false;
    }
}
void Chessboard::set_square(Square square, Piece piece){
    board[square.row][square.col] = piece;
}
void Chessboard::clr_square(Square square){
    set_square(square, {});
}
Piece Chessboard::get_piece(Square square){
    return board[square.row][square.col];
}
uint64_t Chessboard::king_moves(Square square, Color color){
    uint64_t validMoves = 0;
    int row, col;
    Piece piece;
    for (int rowOffset=-1; rowOffset<=1; rowOffset++){
        row = square.row + rowOffset;
        if (row < 0 || row > 7) continue;     //Continue statement mainly to reduce nesting 
        for (int colOffset=-1; colOffset<=1; colOffset++){
            col = square.col + colOffset;
            if (rowOffset == 0 && colOffset == 0) continue;
            if (col < 0 || col > 7) continue;
            piece = get_piece({row, col});
            if (piece.type == EMPTY || piece.color != color){
                validMoves += (1 << col) << (8 * row);
            }
        }
    }
    return validMoves;
}
uint64_t Chessboard::queen_moves(Square square, Color color){
    uint64_t validMoves = 0;
    return validMoves;
}
uint64_t Chessboard::rook_moves(Square square, Color color){
    uint64_t validMoves = 0;
    return validMoves;
}
uint64_t Chessboard::bishop_moves(Square square, Color color){
    uint64_t validMoves = 0;
    return validMoves;
}
uint64_t Chessboard::knight_moves(Square square, Color color){
    uint64_t validMoves = 0;
    return validMoves;
}
uint64_t Chessboard::pawn_moves(Square square, Color color){
    uint64_t validMoves = 0;
    return validMoves;
}
