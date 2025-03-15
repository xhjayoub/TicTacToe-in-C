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
	} while (b[x][y] == 1 || b[x][y] == 2);
	b[x-1][y-1] = player;
}


int main()
{
	printf("TicTacToe !\n");

	int board[3][3];
	print_board(board);
	getPlayerInput(board, 1);
	print_board(board);

	return 0;
}
