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
	printf("�������\n");
	printf("��ֱ������к���:");
	int x = 0,y = 0;
	while (1) {
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '#'; break;
			}
			else { printf("λ���Ѿ���ռ�ã�����������\n"); }
		}
		else { printf("����Խ�磬����������\n"); }
	}
}

void computermove(char board[Row][Col], int row, int col)
{
	printf("��������\n");
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
	//��
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col - 2;j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 2] == board[i][j + 1] && board[i][j]!=' ')
				return board[i][j];
		}
	}
	//��
	for (int i = 0; i < row-2; i++)
	{
		for (int j = 0; j < col;j++)
		{
			if (board[i][j] == board[i+1][j] && board[i+2][j] == board[i+1][j] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	//���Խ��� ���ϵ�����
	for (int i = 0; i < row - 2; i++)
	{
		for (int j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i + 1][j+1] && board[i + 2][j+2] == board[i + 1][j+1] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	//���Խ��� ���µ�����
	for (int x = row - 1; x >= 2; x--)
	{
		for (int ol = 0; ol < col-2; ol++) {
			if (board[x][ol] == board[x - 1][ol + 1] && board[x - 2][ol + 2] == board[x - 1][ol + 1] && board[x][ol] != ' ')
				return board[x][ol];
		}
	}
	//ƽ��
	if (Isfull(board,row,col)) { return 'Q'; }
	//��Ϸ����
	return 'C';
}