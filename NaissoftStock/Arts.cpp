#include "Arts.h"

#include <stdio.h>
#include <Windows.h>

void startLogo()
{
	setcursortype(NOCURSOR);

	Sleep(700);
	textcolor(8);
	gotoxy(31, 10), printf("�� 2015 Naissoft");
	Sleep(70);
	textcolor(7);
	gotoxy(31, 10), printf("�� 2015 Naissoft");
	Sleep(70);
	textcolor(15);
	gotoxy(31, 10), printf("�� 2015 Naissoft");
	Sleep(1000);
	textcolor(7);
	gotoxy(31, 10), printf("�� 2015 Naissoft");
	Sleep(70);
	textcolor(8);
	gotoxy(31, 10), printf("�� 2015 Naissoft");
	Sleep(70);
	system("cls");
	textcolor(7);
	Sleep(300);

	setcursortype(NORMALCURSOR);
}

void printMainMenu()
{
	printf("\n\n\t\t\t      Stock! - �ֽ� ����");
	printf("\n\n\t\t\t      �� 2015 Naissoft.");
	printf("\n\n\n\t\t\t�׸��� ������ �ֽñ� �ٶ��ϴ�.");
	printf("\n\n\t\t\t    �� ���� �����ϱ� : 1��");
	printf("\n\n\t\t\t    ��  �� �� �� ��  : 2��");
	printf("\n\n\t\t\t    ��  ��       ��  : 3��");
}