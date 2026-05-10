/* * * * * * * * * * * * * * * * * * * *
 *
 * chessboard.h - Authored by Drew Balducci - May 09, 2026
 *
 * Chessboard class to handle internal logic of chess game
 *
 * * * * * * * * * * * * * * * * * * * */

#pragma once
#include <stdint.h>

enum PieceType {EMPTY = 0, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum Color {NONE = 0, WHITE, BLACK};

struct Piece {
    Color color;
    PieceType type;
};

struct Square {
    uint8_t row, col;
};

class Chessboard
{
    public:
        Chessboard();
        void reset_board();
        uint64_t valid_moves(Square square);
        uint16_t get_piece_id(Piece piece);

    private:
        Piece board[8][8];
        Color whosTurn = WHITE;

        bool move_piece(Square from, Square to);
        void set_square(Square square, Piece piece);
        void clr_square(Square square);
        Piece get_piece(Square square);
        bool move_here(Square square, Color color);
        bool take_here(Square square, Color color);
        bool move_check(Square square, Color color, uint64_t &validMoves);
        uint64_t king_moves(Square square, Color color);
        uint64_t queen_moves(Square square, Color color);
        uint64_t rook_moves(Square square, Color color);
        uint64_t bishop_moves(Square square, Color color);
        uint64_t knight_moves(Square square, Color color);
        uint64_t pawn_moves(Square square, Color color);

};
