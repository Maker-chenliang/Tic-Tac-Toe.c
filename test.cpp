#include"game.h"

void game()
{
	char board[Row][Col] = { 0 };
	InitBoard(board,Row,Col);
	DisplayBoard(board, Row, Col);
	char ret;
	while(1) {
		playermove(board, Row, Col);
		if (ret=Iswin(board, Row, Col) != 'C')break;
		DisplayBoard(board, Row, Col);
		Sleep(900);
		computermove(board, Row, Col);
		if (ret=Iswin(board, Row, Col) != 'C')break;

		DisplayBoard(board, Row, Col);
	}
	char a;
	a = Iswin(board, Row, Col);
	if (a == '#')printf("玩家赢\n");
	if (a == '*')printf("电脑赢\n");
	if (a == 'Q')printf("平局\n");
	DisplayBoard(board, Row, Col);
}
void choice()
{
	
	printf("1.游玩 0.退出\n");
	printf("请输入\n");
}

int main()
{
	int input;
	printf("三子棋\n");
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	do
	{
		choice();
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:
			printf("已退出游戏\n");
			break;
		default:printf("请重新输入\n"); break;
		}
	} while (input);
		return 0;
}