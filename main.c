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
	int booknumber;
	struct trainif *next;
};

struct trainif *TicketInit();
int TicketInsert(struct trainif *p);
void MainMenu();
void MenuChoose(int mychoose, struct trainif *p);
int QuitSystem();
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
	p->next = NULL;

	return p;
}

int TicketInsert(struct trainif *p)
{
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
		QuitSystem();
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

int QuitSystem()
{
	printf("system quit normally\n");
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
