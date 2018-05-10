#include <stdio.h>  
#include <stdlib.h>  
#include<graphics.h>
#include <time.h>
#include <conio.h>
#include<string.h>
int count;
int result[100][8][8];

int check(int row, int j, int(*chess)[8]) {
	int i, k;
	for (i = 0; i<8; i++)
		if (*(*(chess + i) + j) == 1)
			return 0;
	for (i = row, k = j; i >= 0 && k >= 0; i--, k--)
		if (*(*(chess + i) + k) == 1)
			return 0;
	for (i = row, k = j; i<8 && k<8; i++, k++)
		if (*(*(chess + i) + k) == 1)
			return 0;
	for (i = row, k = j; i<8 && k >= 0; i++, k--)
		if (*(*(chess + i) + k) == 1)
			return 0;
	for (i = row, k = j; i >= 0 && k<8; i--, k++)
		if (*(*(chess + i) + k) == 1)
			return 0;
	return 1;
}

void al(int row, int n, int(*chess)[8]) {
	int chess2[8][8], i, j;
	for (i = 0; i<8; i++)
		for (j = 0; j<8; j++)
			chess2[i][j] = chess[i][j];

	if (row == 8) {
		count++;
		for (i = 0; i<8; i++) {
			for (j = 0; j<8; j++)
				result[count - 1][i][j] = chess2[i][j];
			printf("\n");
		}
	}
	else {
		for (j = 0; j<n; j++) {
			if (check(row, j, chess2)) {
				for (i = 0; i<8; i++)
					chess2[row][i] = 0;
				chess2[row][j] = 1;
				al(row + 1, n, chess2);
			}
		}
	}
}
void print(int k)
{
	int top = 20, left = 20, i, j;
	char str[4];
	char s1[50] = "第";
	_itoa(k + 1, str, 10);
	strcat(s1, str);
	strcat(s1, "种情况");
	outtextxy(20, 20, "8皇后演示效果，按任意键可查看下一结果！");
	outtextxy(20, 40, s1);
	for (i = 0; i<8; i++) {
		left = 20;
		top += 50;
		for (j = 0; j<8; j++)
		{
			if ((i + j) % 2 == 0)
				setfillcolor(WHITE);
			else
				setfillcolor(BLACK);
			if (result[k][i][j] == 1)
				setfillcolor(RED);
			solidrectangle(left, top, left + 50, top + 50);
			left += 50;
		}
	}
	system("pause");
	cleardevice();
}

void main()
{
	int i, j, chess[8][8] = { 0 }, choice;
	int left, right, top, buttokkm;
	char col[10] = "";
	al(0, 8, chess);
	initgraph(500, 500);
	setbkcolor(BROWN);
	cleardevice();
	for (i = 0; i<92; i++)
		print(i);

}