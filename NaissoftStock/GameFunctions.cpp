#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

#include "GameFunctions.h"

int Money, StockMoney[MAX_COMPANY], PrevStockMoney[MAX_COMPANY], Stocks, StockDeal, loanMoney;
bool ifGood[MAX_COMPANY];
int month, day, hour;
FILE input, output;

char *CompanyName[MAX_COMPANY] =
{
	"Naissoft",
	"�ޱ׸�����Ʈ����ʵ�",
	"�ϰܳ��",
	"MK Electronics",
	"���뱺��ȸ��",
	"CJ ���ϼտ���",
	"KJS����",
	"����������ȸ��",
	"����߰���",
};

char *Tips[MAX_TIP] =
{
	"�ְ��� �� �� �ż��ϰ� ��� �� �ŵ��ؼ� ������ ������!",
	"������ ���� ���� ���� �Ǿ����!",
	"1�޸��� ������ ���ϴ�. ��� ��ٸ��ٰ� �Ļ��� �� ������ �����ϼ���!",
	"���� ȸ���� �ֽ��� �� �� �ֽ��ϴ�. ȸ�� ����� Ȯ���ϼ���!",
};

char *GoodNews[MAX_NEWS] =
{
	"�� �� ��ǰ, �α���� ��",
	"�� ������ �̲� �� CEO�� �濵ö��...",
	", ȯ�� �޵����� �ְ� ����",
	"�� �ܱ����� ��Ը� ���ڷ� ȣ��"
};

char *BadNews[MAX_NEWS] =
{
	"�� �� ��ǰ �� ����... CEO ���� ����",
	", ���� �߼��δ� �����ϴ� - ������ �м�",
	", ȯ���� ���� �ɰ��� ����",
	" �ֽ� ����.. �ܱ��� ��Ը� �ŵ��� �ְ� �޶�"
};

void init()
{
	Money = DEF_MONEY;
	for (int i = 0; i < MAX_COMPANY; i++) StockMoney[i] = 9000;
	for (int i = 0; i < MAX_COMPANY; i++) ifGood[i] = true;
	Stocks = StockDeal = 0;
	loanMoney = 0;
	ChangeStockMoney();
	hour++;
}

void ShowMain()
{
	gotoxy(0, 1);
	printf(" Stock - Windows��� �ֽ� ����\n ver 1.3.1004\n\n B ���, S �ȱ�, V �ֽ� ���, P �Ͻ� ���� / �޴�");
	gotoxy(0, 4);
	printf("\n ���� �� �� : %d��, ���ƾ� �� �� : %d��\n\n\n\n", Money, loanMoney);
	ShowStockPrice();
}

void ChangeStockMoney()
{
	srand((int)time(NULL));

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		if (ifGood[i] == true)
		{
			if ((rand() % 2) == 0)
			{
				StockMoney[i] += (rand() % 1000);
			}
			else
			{
				StockMoney[i] -= (rand() % 100);
			}
		}
		else
		{
			if ((rand() % 2) == 0)
			{
				StockMoney[i] += (rand() % 500);
			}
			else
			{
				StockMoney[i] -= (rand() % 1000);
			}
		}
		if (StockMoney[i] < 2000) StockMoney[i] = 2000;
		StockMoney[i] = StockMoney[i] / 10 * 10;
	}
}

void load()
{
	int stocks = 0;
	Stock tmp;

	FILE *save = fopen("save.ns3", "rb");
	if (save == NULL)
	{
		init();
		return;
	}

	fscanf(save, "%d ", &stocks);
	stocks = _rotr(stocks, 1);

	for (int i = 0; i < stocks; i++)
	{
		now = head;

		fscanf(save, "%d %d ", &tmp.company, &tmp.price);
		tmp.company = _rotr(tmp.company, 1); tmp.price = _rotr(tmp.price, 1);
		InsertStock(now, &tmp);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		fscanf(save, "%d ", &StockMoney[i]);
		StockMoney[i] = _rotr(StockMoney[i], 1);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		fscanf(save, "%d ", &ifGood[i]);
		ifGood[i] = _rotr(ifGood[i], 1);
	}

	fscanf(save, "%d %d %d %d %d %d %d", &Money, &loanMoney, &Stocks, &StockDeal, &month, &day, &hour);
	Money = _rotr(Money, 1); loanMoney = _rotr(loanMoney, 1); Stocks = _rotr(Stocks, 1);
	StockDeal = _rotr(StockDeal, 1); month = _rotr(month, 1); day = _rotr(day, 1); hour = _rotr(hour, 1);

	fclose(save);
}

void save()
{
	int stocks = 0;
	FILE *save = fopen("save.ns3", "wb");

	for (now = head->next; now; now = now->next) stocks++;
	fprintf(save, "%d ", _rotl(stocks, 1));

	for (now = head->next; now; now = now->next)
		fprintf(save, "%d %d ", _rotl(now->company, 1), _rotl(now->price, 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(StockMoney[i], 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(ifGood[i], 1));

	fprintf(save, "%d %d %d %d %d %d %d", _rotl(Money, 1), _rotl(loanMoney, 1), _rotl(Stocks, 1), _rotl(StockDeal, 1),
		_rotl(month, 1), _rotl(day, 1), _rotl(hour, 1));

	fclose(save);
}

void ShowStockPrice()
{
	for (int i = 0; i < MAX_COMPANY; i++)
	{
		printf(" ȸ�� : %-20s �� ���� : %5d��  ", CompanyName[i], StockMoney[i]);
		if (PrevStockMoney[i] < StockMoney[i])
		{
			textcolor(2);
			printf("��%4d�� ", StockMoney[i] - PrevStockMoney[i]);
			textcolor(7);
		}
		else if (PrevStockMoney[i] > StockMoney[i])
		{
			textcolor(14);
			printf("��%4d�� ", -1 * (StockMoney[i] - PrevStockMoney[i]));
			textcolor(7);
		}
		printf("\n");
	}
}

void loan(int lmoney)
{
	loanMoney += lmoney;
	Money += lmoney;
}

void interest()
{
	loanMoney += (loanMoney * 0.05);
}

void payback()
{
	Money -= loanMoney;
	loanMoney = 0;
}

void buyStock(int stocknum, int company)
{
	for (int i = 0; i < stocknum; i++)
	{
		if (company <= MAX_COMPANY)
		{
			if (StockMoney[company - 1] <= Money)
			{
				system("cls");
				now = head;

				tmp.company = company - 1;
				tmp.price = StockMoney[company - 1];
				now = InsertStock(now, &tmp);

				Stocks++;
				StockDeal++;
				printf(" %d���� �ְ� ��° �ֽ��� �����Ͽ����ϴ�. �ֽ��� %d���Դϴ�.\n", StockMoney[company - 1], Stocks);
				Money -= StockMoney[company - 1];
				printf(" ���� ���� %d���Դϴ�.\n", Money);
			}
			else
			{
				printf(" ���� �����մϴ�. �ֽ��� �� �� �����ϴ�.\n");
				break;
			}
		}
	}
}

void sellStock(int i)
{
	Stock *f = FindStock(i - 1);
	printf("\n ���� %s ȸ�� �ֽ��� ���� %d���̰�, �ȸ� %d���� ������ ���� �˴ϴ�.\n", CompanyName[f->company], StockMoney[f->company], StockMoney[f->company] - f->price);
	printf(" �ֽ��� �Ľðڽ��ϱ�? Y / N ");
	char k;
	scanf(" %c", &k);
	if (k == 'Y')
	{
		Money += (StockMoney[f->company]);
		DeleteStock(f);
	}
}

void showTipNews()
{
	gotoxy(0, 7);
	for (int i = 0; i < 80; i++) printf(" ");
	gotoxy(0, 7);
	if (rand() % 3 == 0)
		printf(" �� : %s", Tips[rand() % MAX_TIP]);
	else
	{
		int comp = rand() % MAX_COMPANY;
		if (ifGood[comp] == true) printf(" NEWS : %s%s", CompanyName[comp], GoodNews[rand() % MAX_NEWS]);
		else printf(" NEWS : %s%s", CompanyName[comp], BadNews[rand() % MAX_NEWS]);
	}
}