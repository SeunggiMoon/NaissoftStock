//
// Stock
// (c) 2015 Naissoft.
//

#include "GameFunctions.h"

int main(void)
{
	int i, j, cnt, company, stocknum, loanmoney;
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int menu;
	char c, ch, pausemenu;

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

	system("title �ֽ� ����");

	printf("\n\n\t\t\t      Stock! - �ֽ� ����");
	printf("\n\n\t\t\t      �� 2015 Naissoft.");
	printf("\n\n\n\t\t\t�׸��� ������ �ֽñ� �ٶ��ϴ�.");
	printf("\n\n\t\t\t    �� ���� �����ϱ� : 1��");
	printf("\n\n\t\t\t    ��  �� �� �� ��  : 2��");
	printf("\n\n\t\t\t    ��  ��       ��  : 3��");
	scanf("%d", &menu);

	InitStock();
	init();
	i = j = cnt = month = day = hour = company = 0;

	switch (menu)
	{
	case 1:
		ChangeStockMoney();
		save();
		break;
	case 2:
		load();
		break;
	case 3:
		exit(0);
		break;
	default:
		break;
	}
	
	system("cls");
	while (true)
	{
		if (Money <= 0)
		{
			printf("\n �Ļ�... 3000�� ������ �帮�ڽ��ϴ�.");
			getchar();
			loan(3000);
			system("cls");
		}
		ShowMain();
		ShowStockPrice(viewmode);

		printf("\n %d�� %d�� %d��", month + 1, day + 1, hour);
		printf("\n\n 1�޸��� ������ ���ϴ�. ���� �� ������ %d���Դϴ�.\n %d�� ���ҽ��ϴ�.\n", (15000 + (Money / 100)), days[month] - day);

		c = '\0';

		if (timemode == 0)
		{
			if (kbhit()) c = getch();
		}
		else if (timemode == 1)
		{
			c = getch();
		}

		switch (c)
		{
		case 'b':
		case 'B':
			system("cls");
			titleLine("�ֽ� ���");
			printf(" �ֽ� ���� :\n\n");
			for (int i = 0; i < MAX_COMPANY; i++)
			{
				printf(" %d : %-20s, ���� : %d��\n", i + 1, CompanyName[i], StockMoney[i]);
			}

			printf("\n ��� ȸ���� �ֽ��� �����Ͻðڽ��ϱ�?\n ����Ϸ��� 0�� �����ϼ���.\n");
			scanf("%d", &company);

			if (company != 0)
			{
				printf("\n �� ���� �����Ͻðڽ��ϱ�?\n");
				scanf("%d", &stocknum);

				buyStock(stocknum, company);

				Sleep(500);
			}
			system("cls");
			break;
		case 'v':
		case 'V':
			system("cls");
			j = 0;
			if (Stocks <= 0)
			{
				printf("\n �ֽ��� �����ϴ�.\n");
			}
			else
			{
				titleLine("�ֽ� ��� ����");

				for (int i = 0; i < MAX_COMPANY; i++)
				{
					printf("\n %s �ֽ�\n", CompanyName[i]);
					j = 1;
					for (now = head->next; now; now = now->next)
					{
						if (now->company == i)
						{
							printf("\n %d. ���� : %d��", j, now->price);
							j++;
						}
					}
					printf("\n");
				}
			}
			printf("\n ���ư����� Enter�� ��������.");
			getchar();
			system("cls");
			break;
		case 27:
			system("cls");
			titleLine("�Ͻ� ����");
			printf(" 1. ��  ��\n\n 2. ��  ��\n\n 3. ��  ��\n\n 4. ��  ��\n\n 5. ������\n\n Q ���ư���");

			scanf(" %c", &pausemenu);
			switch (pausemenu)
			{
			case '1':
				system("cls");
				titleLine("��  ��");
				printf("\n �ֽ��� ��ų� �� Ƚ�� : %d\n ���� ���� �� : %d��\n �ֽ� ���� : %d\n\n ���ư����� �ƹ� Ű�� ��������.\n", StockDeal, Money, Stocks);
				getch();
				system("cls");
				ShowMain();
				break;
			case '2':
				system("cls");
				titleLine("��  ��");
				printf("\n �󸶸� ��������ðڽ��ϱ�?");
				scanf("%d", &loanmoney);

				loan(loanmoney);
				break;
			case '3':
				payback();
				break;
			case '4':
				system("cls");
				save();
				printf("\n ������ ����Ǿ����ϴ�.");
				Sleep(500);
				break;
			case '5':
				system("cls");
				printf("\n �����Ͻðڽ��ϱ�? ������� ���� ������ ������ϴ�.\n Y / N");
				if (getch() == 'Y') exit(0);
				break;
			case 'Q':
			case 'q':
				break;
			default:
				break;
			}
			system("cls");
			Sleep(100);
			break;
		case 's':
		case 'S':
			i = 1;
			while (i != 0)
			{
				system("cls");
				titleLine("�ֽ� �ȱ�");
				printf("\n [ �� �ֽ��� ������ ]\n\n");
				j = 1;
				for (now = head->next; now; now = now->next)
				{
					printf("\n %d. ȸ�� : %-20s, ���� : %d��", j, CompanyName[now->company], now->price);
					j++;
				}
				printf("\n ���ư����� 0�� �����ϼ���.\n");
				scanf("%d", &i);
				if (i != 0) sellStock(i);
			}
			system("cls");
			break;
		case 'T':
		case 't':
			int select;
			system("cls");
			titleLine("��  ��");
			printf(" 1. ���� ��� ��ȯ\n 2. �ð� �帧 ��� ��ȯ\n Q ���ư���");
			scanf("%d", &select);

			switch (select)
			{
			case 1:
				viewmode++;
				if (viewmode > 2) viewmode = 0;
				switch (viewmode)
				{
				case 0:
					printf(" ���� ����� �⺻ ���� ��ȯ�Ǿ����ϴ�.");
					break;
				case 1:
					printf(" ���� ����� �������� ���� ��ȯ�Ǿ����ϴ�.");
					break;
				case 2:
					printf(" ���� ����� �������� ���� ��ȯ�Ǿ����ϴ�.");
					break;
				}
				break;
			case 2:
				timemode++;
				if (timemode > 1) timemode = 0;
				switch (timemode)
				{
				case 0:
					printf(" �ð� �帧�� �ڵ����� ��ȯ�Ǿ����ϴ�.");
					break;
				case 1:
					printf(" �ð� �帧�� �������� ��ȯ�Ǿ����ϴ�.");
					break;
				}
				break;
			default:
				break;
			}
			Sleep(300);
			system("cls");
			break;
		case 'W':
		case 'w':
			if (timemode == 1)
			{
				cnt += 20;
				Sleep(300);
			}
			break;
		default:
			break;
		}
		for (i = 0; i < MAX_COMPANY; i++)
			PrevStockMoney[i] = StockMoney[i];

		if (cnt % 20 == 0)
		{
			ChangeStockMoney();
			hour++;
		}

		if (cnt % 60 == 0) showTipNews();

		if (hour == 1)
		{
			for (int i = 0; i < MAX_COMPANY; i++)
			{
				if (rand() % 2 == 0) ifGood[i] = true;
				else ifGood[i] = false;
			}
		}
		if (hour > 23)
		{
			hour = 0;
			interest();
			day++;
		}
		if (day > days[month] - 1)
		{
			day = 0;
			month++;
			Money -= ((15000 + (Money / 100)) / 10) * 10;
		}
		if (month > 11) month = 0;

		if (timemode == 0)
		{
			clearbuffer();
			Sleep(DELAY);
			cnt++;
		}
		else if (timemode == 1)
		{
			clearbuffer();
			Sleep(DELAY);
		}
	}
	getchar();
	UnInitStock();
	return 0;
}