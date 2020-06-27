#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MainMenu();
void MenuChoose(int mychoose);
int QuitSystem();
int InsertInformation();
int SerachInformation();
int BookTicket();
int ModifyInformation();
int ShowInformation();
int SaveInformation();

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

void MenuChoose(int mychoose)
{
  switch (mychoose)
	{
	  case 0:
      QuitSystem();
			break;
    case 1:
		  InsertInformation();
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
  return 0;
}

int InsertInformation()
{
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
	while(1)
	{
	  MainMenu();
		scanf("%d",&choose);
		while(getchar() != '\n')
		{
		}
	  MenuChoose(choose);
	}
	return 0;
}



