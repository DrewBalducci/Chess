/* * * * * * * * * * * * * * * * * * * *
 *
 * chessboard.h - Authored by Drew Balducci - May 09, 2026
 *
 * Chessboard class to handle internal logic of chess game
 *
 * * * * * * * * * * * * * * * * * * * */


enum PieceType {PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum Color {WHITE, BLACK};

struct Piece {
enum PieceType {PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum Color {WHITE, BLACK};

struct Piece {
    Color color;
    PieceType type;
}

struct Square {
    uint8_t row, col;
}

class Chessboard
{
    public:
        Chessboard();
        void reset_board();
        uint64_t valid_moves(Square square);
        uint16_t get_piece_id(Piece piece)

    private:
        Piece board[8][8];
        uint8_t whosTurn = WHITE;

        bool move_piece(Square from, to);
        void set_square(Square square, Piece piece);
        void clr_square(Square square);
        Piece get_piece(Square square);
        uint64_t king_moves(Square square, Color color);
        uint64_t queen_moves(Square square, Color color);
        uint64_t rook_moves(Square square, Color color);
        uint64_t bishop_moves(Square square, Color color);
        uint64_t knight_moves(Square square, Color color);
        uint64_t pawn_moves(Square square, Color color);

}
