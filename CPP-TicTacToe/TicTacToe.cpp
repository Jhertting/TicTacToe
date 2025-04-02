#include "TicTacToe.h"
#include <iostream>

using namespace std;

// initialize the board display
TicTacToe::TicTacToe() : m_playerTurn(0)
{
	for (int i = 0; i < 9; i++)
	{
		m_board[i] = '1' + i;
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
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},


		// column
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},

		// diagonal
		{0, 4, 8}, {2, 4, 6}
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
	for (int i = 0; i < 9; ++i) {
		if (m_board[i] != 'X' && m_board[i] != 'O') 
		{
			return false;  
		}
	}
	return true;
}

void TicTacToe::TakeTurn()
{
	int position;
	bool validMove = false;

	while (!validMove)
	{
		cout << "Enter a position (1-9): ";
		cin >> position;

		if (cin.fail() || position < 1 || position > 9)
		{
			// handles invalid input 
			cout << "Invalid input. Please enter a number between 1 and 9.\n";
			cin.clear();
		}
		else if (m_board[position - 1] == 'X' || m_board[position - 1] == 'O')
		{
			// handles case where position is already taken
			cout << "That position is already used. Please choose another.\n";
		}
		else
		{
			// mark board with X or O - accepts move
			m_board[position - 1] = (m_playerTurn == 0) ? 'X' : 'O';
			m_playerTurn = 1 - m_playerTurn;
			validMove = true;
		}
	}
}

void TicTacToe::Display() const
{
	// clear board from previous moves
	system("cls");

	cout << "Tic Tac Toe!\n";
	cout << "Player 1 = X | Player 2 = O\n";

	cout << endl;

	// first row
	cout << " " << m_board[0] << " | " << m_board[1] << " | " << m_board[2] << endl;
	cout << "---|---|---" << endl;

	// second row
	cout << " " << m_board[3] << " | " << m_board[4] << " | " << m_board[5] << endl;
	cout << "---|---|---" << endl;

	// third row
	cout << " " << m_board[6] << " | " << m_board[7] << " | " << m_board[8] << endl;

	cout << endl;
}
  

