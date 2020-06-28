#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>


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

struct passger
{
	char name[32];
	long int id;
	int booknum;
	struct passger *next;
};

struct passger *passger();
void passgerdestory(struct passger *p);
void ShowSingleIf(struct trainif *p);
struct trainif *TicketInit();
void destory(struct trainif *p);
void MainMenu();
void MenuChoose(int mychoose, struct trainif *p, struct passger *q);
int QuitSystem(struct trainif *p, struct passger *q);
int InsertInformation(struct trainif *p);
int SerachInformation(struct trainif *p);
int BookTicket(struct trainif *p, struct passger *q);
int ModifyInformation(struct trainif *p);
int ShowInformation(struct trainif *p);
int SaveInformation(struct trainif *p, struct passger *q);

void passgerdestory(struct passger *p)
{
	struct passger *q = p;
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

struct passger *passger()
{
	struct passger *p = NULL;
	p = (struct passger *)malloc(sizeof(struct passger));
	if (NULL == p)
	{
		printf("malloc failed");
		return NULL;
	}

	memset(p, 0, sizeof(struct passger));
	p->next = NULL;

	return p;
}

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

void MenuChoose(int mychoose, struct trainif *p, struct passger *q)
{
	switch (mychoose)
	{
	case 0:
		QuitSystem(p, q);
		break;
	case 1:
		InsertInformation(p);
		break;
	case 2:
		SerachInformation(p);
		break;
	case 3:
		BookTicket(p, q);
		break;
	case 4:
		ModifyInformation(p);
		break;
	case 5:
		ShowInformation(p);
		break;
	case 6:
		SaveInformation(p, q);
		break;
	default:
		break;
	}
}

int QuitSystem(struct trainif *p, struct passger *q)
{
	printf("system quit normally\n");
	passgerdestory(q);
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

int SerachInformation(struct trainif *p)
{
	int x = 0;
	int number = 0;
	char buf[32];
	struct trainif *q = NULL;
	q = p;
	printf("choose the wy:\n");
	printf("1:according the number of train\n");
	printf("2:according to the city");

	do
	{
		scanf("%d", &x);
		while (getchar() != '\n')
			;
	} while (x != 1 && x != 2);

	if (x == 1)
	{
		printf("Input number of the train:\n");
		scanf("%d", &number);
		while (getchar() != '\n')
			;

		while (q != NULL && number != q->trainnum)
		{
			q = q->next;
		}

		ShowSingleIf(q);
	}
	else if (x == 2)
	{
		printf("Input the city of the train\n");
		scanf("%s", buf);
		while (p != NULL && strcasecmp(buf, p->end))
		{
			p = p->next;
		}

		ShowSingleIf(p);
	}

	return 0;
}

int BookTicket(struct trainif *p, struct passger *f)
{
	struct trainif *q = NULL;
	q = p;
	int k = 0;
	int t = 0;
	char c = '\0';
	char buf[32] = {'\0'};
	printf("Please input the city you want togo:");
	scanf("%s", buf);
	while (getchar() != '\n')
		;

	q = q->next;
	if (q == NULL)
	{
		printf("there is no train information\n");
	}

	while (q != NULL)
	{
		if (strcasecmp(buf, q->end) == 0)
		{
			ShowSingleIf(q);
			k++;
		}
		q = q->next;
	}
	printf("your recoder is %d\n", k);
	;

	if (0 != k)
	{
		printf("Do you want to book it y/n:");
		scanf("%c", &c);
		while (getchar() != '\n')
			;
		if ('y' == c)
		{
			struct passger *k = NULL;
			k = (struct passger *)malloc(sizeof(struct passger));
			if (NULL == k)
			{
				printf("malloc failed\n");
				return -1;
			}
			memset(k, 0, sizeof(struct passger));

			printf("please intput your name:");
			scanf("%s", k->name);
			while (getchar() != '\n')
				;

			printf("please input your id:");
			scanf("%ld", &k->id);
			while (getchar() != '\n')
				;

			printf("please input the number of the train:");
			scanf("%d", &t);
			while (getchar() != '\n')
				;

			q = p;
			while (q != NULL && q->trainnum != t)
			{
				q = q->next;
			}

			printf("remain %d tickets\n", q->booknumber);
			printf("Input your book number:");
			scanf("%d", &k->booknum);
			if (q->booknumber > 0)
			{
				printf("lucky you book it success\n");
				q->booknumber--;
				k->next = f->next;
				f->next = k;
			}
			else
			{
				printf("book failed\n");
				free(k);
			}
		}
	}

	return 0;
}

int ModifyInformation(struct trainif *p)
{
	char choose = '\0';
	int trainnum = 0;
	struct trainif *f = p;
	printf("Do you want to modify information:y/n");
	scanf("%c", &choose);
	while (getchar() != '\n')
		;

	if ('y' == choose)
	{
		printf("Please input train num you want to modif:");
		scanf("%d", &trainnum);
		while (getchar() != '\n')
			;
		while (NULL != f && f->trainnum != trainnum)
		{
			f = f->next;
		}

		if (NULL == f)
		{
			printf("please input true train number\n");
			return -1;
		}

		printf("please input new number:");
		scanf("%d", &f->trainnum);
		while (getchar() != '\n')
			;

		printf("Input city you start:");
		scanf("%s", f->start);
		while (getchar() != '\n')
			;

		printf("Input the city you arrive:");
		scanf("%s", f->end);
		while (getchar() != '\n')
			;

		printf("time to take off:");
		scanf("%s", f->starttime);
		while (getchar() != '\n')
			;

		printf("time to arrive:");
		scanf("%s", f->receivetime);
		while (getchar() != '\n')
			;

		printf("input price of new train:");
		scanf("%d", &f->price);
		while (getchar() != '\n')
			;

		printf("input the remian ticket of new train:");
		scanf("%d", &f->booknumber);
		while (getchar() != '\n')
			;

		printf("modifily information successful\n");
	}

	return 0;
}

int ShowInformation(struct trainif *p)
{
	p = p->next;
	if (NULL == p)
	{
		printf("There is no information\n");
	}
	else
	{
		printf("-------------------------------------------------------------------------------------------------------------------:\n");
		printf(":--------------------------------------------BOOK----TICKET--------------------------------------------------------:\n");
		printf(":    number    :  strat city  :  reach city   :   tackofftime    :   receivetime    :  price  :   ticketnumber     :\n");
		printf(":--------------:--------------:---------------:------------------:------------------:---------:--------------------:\n");
		while (p != NULL)
		{
			printf(":%-14d:%-14s:%-15s:%-18s:%-20s:%-9d:%-22d\n", p->trainnum, p->start, p->end, p->starttime, p->receivetime, p->price, p->booknumber);
			p = p->next;
		}
		printf("-------------------------------------------------------------------------------------------------------------------:\n");
	}
	return 0;
}

int SaveInformation(struct trainif *p, struct passger *q)
{
	FILE * fp1;
	FILE * fp2;
	int k = 0;
	fp1 = fopen("traininformation.txt", "w+a");
	fp2 = fopen("passgerformation.txt", "w+a");
	p = p->next;
	q = q->next;
	while( p != NULL)
	{
		fwrite(p, sizeof(struct trainif),1,fp1);
		fprintf(fp1,"\n");
		p = p->next;
		k++;
	}
	printf("Save train informatin:%d\n", k);
	k = 0;
	while(q != NULL)
	{
		fwrite(q, sizeof(struct passger),1,fp2);
		fprintf(fp2, "\n");
		q = q->next;
		k++;
	}
	printf("Save passger informatin:%d\n", k);

	fclose(fp1);
	fclose(fp2);
	return 0;
}

void ShowSingleIf(struct trainif *p)
{
	if (NULL == p)
	{
		printf("Not found the train infformation!\n");
	}
	else
	{
		printf("-------------------------------------------------------------------------------------------------------------------:\n");
		printf(":--------------------------------------------BOOK----TICKET--------------------------------------------------------:\n");
		printf(":    number    :  strat city  :  reach city   :   tackofftime    :   receivetime    :  price  :   ticketnumber     :\n");
		printf(":--------------:--------------:---------------:------------------:------------------:---------:--------------------:\n");
		printf(":%-14d:%-14s:%-15s:%-18s:%-20s:%-9d:%-22d\n", p->trainnum, p->start, p->end, p->starttime, p->receivetime, p->price, p->booknumber);
	}
}

int main(int argc, const char *argv[])
{
	int choose = -1;
	struct trainif *p = NULL;
	struct passger *q = NULL;
	p = TicketInit();
	q = passger();
	if (NULL == p)
	{
		exit(-1);
	}
	if (NULL == q)
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
		MenuChoose(choose, p, q);
	}
	return 0;
}
