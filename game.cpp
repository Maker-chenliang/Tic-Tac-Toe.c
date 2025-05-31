#include"game.h"
void InitBoard(char board[Row][Col],int row, int col)
{
	int i=0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[Row][Col], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
			printf("\n");
			if (i < row - 1)
			{
				int j = 0;
				for (j = 0; j < col; j++) {
					printf("---");
					if (j < col - 1)printf("|");
				}
				printf("\n");
			}
			
		

	}
	printf("\n");
}

void playermove(char board[Row][Col], int row, int col)
{
	printf("玩家下棋\n");
	printf("请分别输入行和列:");
	int x = 0,y = 0;
	while (1) {
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '#'; break;
			}
			else { printf("位置已经被占用，请重新输入\n"); }
		}
		else { printf("坐标越界，请重新输入\n"); }
	}
}

void computermove(char board[Row][Col], int row, int col)
{
	printf("电脑下棋\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '*'; break;
		}
	}
}
int Isfull(char board[Row][Col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
		
	}
	return 1;
}
char Iswin(char board[Row][Col], int row, int col)
{
	//行
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col - 2;j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 2] == board[i][j + 1] && board[i][j]!=' ')
				return board[i][j];
		}
	}
	//列
	for (int i = 0; i < row-2; i++)
	{
		for (int j = 0; j < col;j++)
		{
			if (board[i][j] == board[i+1][j] && board[i+2][j] == board[i+1][j] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	//主对角线 左上到右下
	for (int i = 0; i < row - 2; i++)
	{
		for (int j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i + 1][j+1] && board[i + 2][j+2] == board[i + 1][j+1] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	//负对角线 左下到右上
	for (int x = row - 1; x >= 2; x--)
	{
		for (int ol = 0; ol < col-2; ol++) {
			if (board[x][ol] == board[x - 1][ol + 1] && board[x - 2][ol + 2] == board[x - 1][ol + 1] && board[x][ol] != ' ')
				return board[x][ol];
		}
	}
	//平局
	if (Isfull(board,row,col)) { return 'Q'; }
	//游戏继续
	return 'C';
}