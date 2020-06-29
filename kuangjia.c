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