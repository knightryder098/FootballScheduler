#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Team // user defined data structure for storing all the details.
{
  int key;
  char name[100];
  int strongPlayer;
  int weakPlayer;
  float teamOpinion;
  float publicOpinion;
  int matchesWon;
  int matchesLost;
};
char ScharSet[] = "abcdefghijklmnopqrstuvwxyz"; // used to create random names
char CcharSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // used to create random names
Team TeamBook[16];                              // Global Variable for storing all details about teams

// randomizer function
void randomizer(Team *A, int pos)
{
  A->key = pos;
  char name[10];
  int index = (rand() % 26) + 1;
  name[0] = CcharSet[index];
  for (int i = 1; i < 10; i++)
  {
    index = (rand() % 26) + 1;
    name[i] = ScharSet[index];
  }
  strcpy(A->name, name);
  A->strongPlayer = (rand() % 11) + 1;
  A->weakPlayer = 11 - A->strongPlayer;
  A->teamOpinion = (double)(A->strongPlayer * 100) / 11;
  A->publicOpinion = (double)((rand() % 100) + 1);
  A->matchesWon = 0;
  A->matchesLost = 0;
  return;
}
// function to enter details by yourself
void entryYourself(int size)
{
  for (int i = 0; i < size; i++)
  {
    system("cls");
    TeamBook[i].key = i + 1;
    printf("Enter details of %d team mmenber\n");
    printf("\tEnter the name of team\n");
    scanf(" %s", &TeamBook[i].name);
    printf("\tEnter no of string players\n");
    scanf(" %d", &TeamBook[i].strongPlayer);
    printf("\tEnter no Public Opinion \n");
    scanf(" %f", &TeamBook[i].publicOpinion);
    TeamBook[i].weakPlayer = 11 - TeamBook[i].strongPlayer;
    TeamBook[i].teamOpinion = (double)(TeamBook[i].strongPlayer * 100) / 11;
    TeamBook[i].matchesWon = 0;
    TeamBook[i].matchesLost = 0;
  }
}
// function to enter details by computer itself
void entryComputer(int size)
{
  for (int i = 0; i < size; i++)
  {
    randomizer(&TeamBook[i], i);
  }
}
// Details Entry
void enterDetails()
{
  int a;
  system("cls");
  printf("\tEnter the number of teams ( Power of 2 ) and below 16 only !\n");
  scanf("%d", &a);
  printf("%d", a);
  if (log2(a) <= 4)
  {
    char ch;
    system("cls");
    printf("\tWant to enter the details by yourself\n \tor\n \twant the Computer to do it\n");
    printf("\t Enter Y(yourself) or C(Computer)\n ");
    scanf(" %c", &ch);
    printf("%c", ch);
    switch (ch)
    {
    case 'Y':
      entryYourself(a);
      break;
    case 'C':
      entryComputer(a);
      break;
    default:
      printf("Invalid input\n\tEXITING!!! .....\n");
      break;
    }
  }
  else
    printf("Can't Scheduled matches for %d numbers of teams\n", a);
  return;
}
void displayDetails()
{
  printf("SL.no\tName\t\t\tSP\tWP\tTO\tPO\tMW\tML\n");
  for (int i = 0; *TeamBook[i].name != '\0'; i++)
  {
    printf("%d\t%s\t\t%d\t%d\t%0.2f\t%0.2f\t%d\t%d", // to display only 2point, we use %0.2f
           TeamBook[i].key + 1,
           TeamBook[i].name,
           TeamBook[i].strongPlayer,
           TeamBook[i].weakPlayer,
           TeamBook[i].teamOpinion,
           TeamBook[i].publicOpinion,
           TeamBook[i].matchesWon,
           TeamBook[i].matchesLost);
    printf("\n");
  }
  getch();
}
// sorting function and its required functions
bool sortbyplayer(Team *a, Team *b)
{
  return (a->strongPlayer > b->strongPlayer);
}
Team partition(team a[], int low, int high)
{
}
void customSort(Team a[], int low, int high)
{
  if (low < high)
  {
    int pi = partion(a, low, high);
    customSort(a, low, pi - 1);
    customSort(a, pi + 1, high);
  }
}
////////////////////////////////////////////////////////////////////////////
// void DisplayResults();
void schedulerMatches()
{
  int teams = 0;
  for (teams; *TeamBook[teams].name != '\0'; teams++)
    ;
  if (teams % 2 == 0)
  {
    // even no of teams
    printf("EVEN");
    customSort(TeamBook, 0, teams - 1);
  }
  else
  {
    // odd number of teams
    printf("ODD");
  }
  getch();
}
int main()
{
  while (1)
  {
    system("cls");
    int choice;
    printf("\tWelcome to Football Game Scheduler\t\n");
    printf("\t\tCHOICES\t\t\n");
    printf("\t1.Enter Teams Details : Type \'1\'\n ");
    printf("\t2.Display Teams Details : Type \'2\'\n ");
    printf("\t3.Start matching 0f Teams : Type \'3\'\n ");
    printf("\t4.Results of Scheduled Matches : Type \'4\'\n ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      enterDetails();
      break;
    case 2:
      displayDetails();
      break;
    case 3:
      // printf("Hello\n");
      schedulerMatches();
      break;
    case 4:
      printf("Hello\n");
      // DisplayResults();
      break;
    default:
    {
      printf("\tInvalid Choices.\n");
      printf("\tCLosing !!!!...\n");
      break;
    }
    }
  }
  return 0;
}