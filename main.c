#include <stdio.h>

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

int main()
{
	printf("TicTacToe !\n");

	int board[3][3];
	board[0][0] = 1;
	board[1][0] = 2;
	print_board(board);
	
	return 0;
}
