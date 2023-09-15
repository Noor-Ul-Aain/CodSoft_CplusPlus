class TicTacToe
{
private:
	int movesCount;
	char board[3][3];
	char currentPlayer;
	bool gameOver;

public:
	TicTacToe();
	~TicTacToe();

    void printBoard();
    bool isGameOver();
    bool isDraw();
    void play();
	void resetGame();
};
