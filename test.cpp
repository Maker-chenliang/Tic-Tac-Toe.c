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
	if (a == '#')printf("���Ӯ\n");
	if (a == '*')printf("����Ӯ\n");
	if (a == 'Q')printf("ƽ��\n");
	DisplayBoard(board, Row, Col);
}
void choice()
{
	
	printf("1.���� 0.�˳�\n");
	printf("������\n");
}

int main()
{
	int input;
	printf("������\n");
	srand((unsigned int)time(NULL));//������������������
	do
	{
		choice();
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:
			printf("���˳���Ϸ\n");
			break;
		default:printf("����������\n"); break;
		}
	} while (input);
		return 0;
}