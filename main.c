#include <stdio.h>
#include <stdlib.h>

void print_board(int b[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("|");
			if (*(*(b + i) + j) == 1)
				printf("X");
			else if (*(*(b + i) + j) == 2)
				printf("O");
			else
				printf(" ");
			printf("|");
		}
		printf("\n");
	}
}
void getInt(const char* s,int *n, int inf, int ins) 
{
	do {
		printf("%s : ", s);
		scanf("%d", n);
	} while (*n < inf || *n > ins);
}

void getPlayerInput(int b[3][3], int player)
{
	int x, y;
	do {
		getInt("Line", &x, 1, 3);
		getInt("Colon", &y, 1, 3);
	} while (b[x-1][y-1] == 1 || b[x-1][y-1] == 2);
	b[x-1][y-1] = player;
}

int checkLineWinner(int b[3][3], int l)
{
	if (b[l][0] == b[l][1] && b[l][1] == b[l][2] && (b[l][0] == 1 || b[l][0] == 2))
		return b[l][0];
	return 0;
}
int checkColonWinner(int b[3][3], int c)
{
	if (b[0][c] == b[1][c] && b[1][c] == b[2][c] && (b[0][c] == 1 || b[0][c] == 2))
		return b[0][c];
	return 0;
}
int checkDiagoWinner(int b[3][3])
{
	// Check first Diagonal
	if ((b[0][0] == 1 || b[0][0] == 2) && (b[0][0] == b[1][1] && b[1][1] == b[2][2]))
		return b[0][0];
	else if ((b[0][2] == 1 || b[0][2] == 2) && (b[0][2] == b[1][1] && b[1][1] == b[2][0]))
		return b[0][2];
	else
		return 0;
}

int checkWinner(int b[3][3])
{
	int Lwinner;
	int Cwinner;
	int i = 0;
	while (i<3) {
		Lwinner = checkLineWinner(b, i);
		Cwinner = checkColonWinner(b, i);
		if (Lwinner != 0) {
			return Lwinner;
		}
		if (Cwinner !=0) {
			return Cwinner;
		}
		i++;
	}

	return checkDiagoWinner(b);
}

void displayWinner(int n) 
{
	printf("\n");
	if (n == 1)
		printf("X wins !\n");
	else if (n == 2)
		printf("O wins !\n");
	else
		printf("Draw\n");
}

int main()
{
	printf("TicTacToe !\n");
	int board[3][3];
	int player = 1;
	int winner = 0;
	int i = 0;
	
	while (i<9) {
		system("clear");
		print_board(board);
		printf("\n\n");
		printf("Player %d turn :\n", player);
		getPlayerInput(board, player);
		printf("\n");
		
		if (player == 1)
			player = 2;
		else
			player = 1;


		if (i>3)
			winner = checkWinner(board);
		if (winner != 0)
			break;
		// Check for winner after x turns
		i++;
	}
	system("clear");
	print_board(board);
	displayWinner(winner);
	return 0;
}
