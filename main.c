#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trainif
{
	int trainnum;
	char start[32];
	char end[32];
	char starttime[10];
	char receivetime[10];
	int price;
	int booknumber;
	struct trainif *next;
};

struct trainif *TicketInit();
void destory(struct trainif *p);
void MainMenu();
void MenuChoose(int mychoose, struct trainif *p);
int QuitSystem(struct trainif *p);
int InsertInformation(struct trainif *p);
int SerachInformation();
int BookTicket();
int ModifyInformation();
int ShowInformation();
int SaveInformation();

struct trainif *TicketInit()
{
	struct trainif *p = NULL;

	p = (struct trainif *)malloc(sizeof(struct trainif));
	if (NULL == p)
	{
		perror("malloc");
		return NULL;
	}
	memset(p, 0, sizeof(struct trainif));
	p->next = NULL;

	return p;
}

void destory(struct trainif *p)
{
	struct trainif *q = p;
	while (p->next != NULL)
	{
		p = p->next;
		free(q);
		q = p;
	}
	free(p);
	p = NULL;
	q = NULL;
}

void MainMenu()
{
	printf(":--------------------------------------------------:\n");
	printf("                  Booking Tickets                  :\n");
	printf(":--------------------------------------------------:\n");
	printf(":          0:Quit the system                       :\n");
	printf(":          1:Insert a train information            :\n");
	printf(":          2:Serach a train information            :\n");
	printf(":          3:Book a train ticket                   :\n");
	printf(":          4:Modify the train information          :\n");
	printf(":          5:Show the train information            :\n");
	printf(":          6:Save information to file              :\n");
	printf(":--------------------------------------------------:\n");
	printf("      please choose <0~6>:                            ");
}

void MenuChoose(int mychoose, struct trainif *p)
{
	switch (mychoose)
	{
	case 0:
		QuitSystem(p);
		break;
	case 1:
		InsertInformation(p);
		break;
	case 2:
		SerachInformation();
		break;
	case 3:
		BookTicket();
		break;
	case 4:
		ModifyInformation();
		break;
	case 5:
		ShowInformation();
		break;
	case 6:
		SaveInformation();
		break;
	default:
		break;
	}
}

int QuitSystem(struct trainif *p)
{
	printf("system quit normally\n");
	destory(p);
	exit(1); //正常退出
	return 0;
}

int InsertInformation(struct trainif *p)
{
	struct trainif *q = NULL;
	struct trainif *f = NULL;
	q = p;
	while (NULL != q->next)
	{
		q = q->next;
	}

	f = (struct trainif *)malloc(sizeof(struct trainif));
	if (NULL == f)
	{
		perror("malloc");
		return -1;
	}

	printf("please input the number of train<0-return>");
	scanf("%d", &f->trainnum);
	while (getchar() != '\n')
		;

	printf("Input the city where the trai will start:");
	scanf("%s", f->start);
	while (getchar() != '\n')
		;

	printf("Input the city where the train reach:");
	scanf("%s", f->end);
	while (getchar() != '\n')
		;

	printf("Input the time which the train take off:");
	scanf("%s", f->starttime);
	while (getchar() != '\n')
		;

	printf("Input the time which the train receive:");
	scanf("%s", f->receivetime);
	while (getchar() != '\n')
		;

	printf("Input the price of the train:");
	scanf("%d", &f->price);
	while (getchar() != '\n')
		;

	printf("Input the number of book tickets:");
	scanf("%d", &f->booknumber);
	while (getchar() != '\n')
		;

	f->next = q->next;
	q->next = f;

	return 0;
}

int SerachInformation()
{
	return 0;
}

int BookTicket()
{
	return 0;
}

int ModifyInformation()
{
	return 0;
}

int ShowInformation()
{
	return 0;
}

int SaveInformation()
{
	return 0;
}

int main(int argc, const char *argv[])
{
	int choose = -1;
	struct trainif *p = NULL;
	p = TicketInit();
	if (NULL == p)
	{
		exit(-1);
	}
	while (1)
	{
		MainMenu();
		scanf("%d", &choose);
		while (getchar() != '\n')
		{
		}
		MenuChoose(choose, p);
	}
	return 0;
}
