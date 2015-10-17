#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

#include "StockFunctions.h"
#include "Stock.h"

int Money, StockPrice[MAX_COMPANY], PrevStockPrice[MAX_COMPANY], Stocks, StockDeal, loanMoney;
bool ifGood[MAX_COMPANY];

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

void ChangeStockPrice()
{
	srand((int)time(NULL));

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		if (ifGood[i] == true)
		{
			if ((rand() % 2) == 0)
			{
				StockPrice[i] += (rand() % 1000);
			}
			else
			{
				StockPrice[i] -= (rand() % 100);
			}
		}
		else
		{
			if ((rand() % 2) == 0)
			{
				StockPrice[i] += (rand() % 500);
			}
			else
			{
				StockPrice[i] -= (rand() % 1000);
			}
		}
		if (StockPrice[i] < 2000) StockPrice[i] = 2000;
		StockPrice[i] = StockPrice[i] / 10 * 10;
	}
}

void ShowStockPrice(int mode)
{
	if (mode == 0)
	{
		for (int i = 0; i < MAX_COMPANY; i++) PrintStockPrice(i);
		return;
	}

	int order[MAX_COMPANY], tmp;
	for (int i = 0; i < MAX_COMPANY; i++) order[i] = StockPrice[i];

	if (mode == 1)
	{
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] > order[j])
				{
					tmp = order[i];
					order[i] = order[j];
					order[j] = tmp;
				}
			}
		}
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] == StockPrice[j])
				{
					PrintStockPrice(j);
					order[i] = 0;
				}
			}
		}
	}
	if (mode == 2)
	{
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] < order[j])
				{
					tmp = order[i];
					order[i] = order[j];
					order[j] = tmp;
				}
			}
		}
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] == StockPrice[j])
				{
					PrintStockPrice(j);
					order[i] = 0;
				}
			}
		}
	}
}

void PrintStockPrice(int i)
{
	printf(" ȸ�� : %-20s �� ���� : %5d��  ", CompanyName[i], StockPrice[i]);
	if (PrevStockPrice[i] < StockPrice[i])
	{
		textcolor(2);
		printf("��%4d�� ", StockPrice[i] - PrevStockPrice[i]);
		textcolor(7);
	}
	else if (PrevStockPrice[i] > StockPrice[i])
	{
		textcolor(14);
		printf("��%4d�� ", -1 * (StockPrice[i] - PrevStockPrice[i]));
		textcolor(7);
	}
	printf("\n");
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
			if (StockPrice[company - 1] <= Money)
			{
				system("cls");
				now = head;

				tmp.company = company - 1;
				tmp.price = StockPrice[company - 1];
				now = InsertStock(now, &tmp);

				Stocks++;
				StockDeal++;
				printf(" %d���� �ְ� ��° �ֽ��� �����Ͽ����ϴ�. �ֽ��� %d���Դϴ�.\n", StockPrice[company - 1], Stocks);
				Money -= StockPrice[company - 1];
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
	printf("\n ���� %s ȸ�� �ֽ��� ���� %d���̰�, �ȸ� %d���� ������ ���� �˴ϴ�.\n", CompanyName[f->company], StockPrice[f->company], StockPrice[f->company] - f->price);
	printf(" �ֽ��� �Ľðڽ��ϱ�? Y / N ");
	char k;
	scanf(" %c", &k);
	if (k == 'Y')
	{
		Money += (StockPrice[f->company]);
		DeleteStock(f);
	}
}

void showStockList()
{
	system("cls");
	int j = 0;
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
}