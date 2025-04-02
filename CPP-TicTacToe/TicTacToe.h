#pragma once
#include "Game.h"

class TicTacToe : public Game
{
public:
	TicTacToe();
	bool IsGameOver() const override;
	void TakeTurn() override;
	void Display() const override;
	bool CheckWin() const;
	bool CheckTie() const;

	char m_board[9];
	int m_playerTurn;
};

