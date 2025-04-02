#include "TicTacToe.h"
#include <iostream>

// initialize the board display
TicTacToe::TicTacToe() : m_playerTurn(1)
{
	for (int i = 1; i < 10; i++)
	{
		m_board[i] = 1 + i;
	}
}

bool TicTacToe::IsGameOver() const
{
	return CheckWin() || CheckTie();
}

bool TicTacToe::CheckWin() const
{
	// define all possible win conditions 
	int winConditions[8][3] =
	{
		// row
		{1,2,3}, {4, 5, 6}, {7, 8, 9},

		// column
		{1, 4, 7}, {2, 5, 8}, {3, 6, 9},

		// diagonal
		{1,5,9}, {3,5,7}
	};

	// checks each possible pattern for a win condition
	for (const auto& condition : winConditions) 
	{
		char initialMark = m_board[condition[0]];

		if (initialMark != ' ' && initialMark == m_board[condition[1]] && initialMark == m_board[condition[2]])
		{
			return true; 
		}
	}
	return false;
}

bool TicTacToe::CheckTie() const
{
	// if no empty spaces remain = tie
	for (int i = 1; i < 10; ++i) {
		if (m_board[i] != 'X' && m_board[i] != 'O') 
		{
			return false;  
		}
	}
	return true;
}


