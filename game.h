#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define Row 5//�Զ������̵�����
#define Col 5//�Զ������̵�����
void InitBoard(char board[Row][Col], int row, int col);
void DisplayBoard(char board[Row][Col], int row, int col);
void playermove(char board[Row][Col], int row, int col);
void computermove(char board[Row][Col], int row, int col);
char Iswin(char board[Row][Col], int row, int col);