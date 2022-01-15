#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

struct Team // user defined data structure for storing all the details.
{
  int key;
  char name[100];
  int strongPlayer;
  int weakPlayer;
  float teamOpinion;
};
Team TeamBook[16];                              // Global Variable for storing all details about teams
char ScharSet[] = "abcdefghijklmnopqrstuvwxyz"; // used to create random names
char CcharSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // used to create random names
int m;

void randomizer(Team *A, int pos)
{
  A->key = pos;
  char name[10];
  int index = (rand() % 24) + 1;
  name[0] = CcharSet[index];
  for (int i = 1; i < 9; i++)
  {
    index = (rand() % 24) + 1;
    name[i] = ScharSet[index];
  }
  strcpy(A->name, name);
  A->strongPlayer = (rand() % 9) + 1;
  A->weakPlayer = 11 - A->strongPlayer;
  A->teamOpinion = (double)(A->strongPlayer * 100) / 11;
  return;
}

void entryYourself(int size)
{
  for (int i = 0; i < size; i++)
  {
    char name[10];
    system("cls");
    TeamBook[i].key = i + 1;
    printf("Enter details of %d team member\n", i + 1);
    printf("\tEnter the name of team\n");
    scanf(" %s", &name);
    strcpy(TeamBook[i].name, name);
    printf("\tEnter no of strong players\n");
    scanf(" %d", &TeamBook[i].strongPlayer);
    TeamBook[i].weakPlayer = 11 - TeamBook[i].strongPlayer;
    TeamBook[i].teamOpinion = (double)(TeamBook[i].strongPlayer * 100) / 11;
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
  system("cls");
  printf("\tEnter the number of teams ( Power of 2 ) and below 16 only !\n");
  scanf("%d", &m);
  printf("%d", m);
  if (m <= 16)
  {
    char ch;
    system("cls");
    printf("\tWant to enter the details by yourself\n \tor\n \twant the Computer to do it\n");
    printf("\t Enter Y(yourself) or C(Computer)\n ");
    scanf(" %c", &ch);
    printf("%c", ch);
    switch (ch)
    {
    case 'y':
    case 'Y':
      entryYourself(m);
      break;
    case 'c':
    case 'C':
      entryComputer(m);
      break;
    default:
      printf("Invalid input\n\tEXITING!!! .....\n");
      break;
    }
  }
  else
    printf("Can't Scheduled matches for %d numbers of teams\n", m);
  return;
}

void displayDetails(Team a[], int size)
{
  int teams = 0;

  printf("\t\nSL.no\tName\t\t\tSP\tWP\tTO\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d\t%s\t\t%d\t%d\t%0.2f", // to display only 2point, we use %0.2f
           a[i].key + 1,
           a[i].name,
           a[i].strongPlayer,
           a[i].weakPlayer,
           a[i].teamOpinion);
    printf("\n");
  }
  getch();
}

int sortbyteamOpinion(const void *p, const void *q)
{
  return ((struct Team *)p)->teamOpinion < ((struct Team *)q)->teamOpinion;
}

void schedulerMatches(Team[], int, int);

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
    printf("\t3.Schedule and view WINNER : Type \'3\'\n ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      memset(TeamBook, 0, sizeof(TeamBook));
      enterDetails();
      break;
    case 2:
    {

      displayDetails(TeamBook, m);
    }
    break;
    case 3:
      schedulerMatches(TeamBook, 0, m);
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

void schedulerMatches(Team a[], int round, int size)
{
  if (size == 1) // last case,exit after this
  {
    printf("\t\n**********%s wins the tournament**********\n", a[0].name);
    return;
  }
  else
  {
    qsort(a, size, sizeof(Team), sortbyteamOpinion);
    displayDetails(a, size);
    printf("\t\n********************\n\tROUND %d !!!!!!\n********************\n", round + 1);
    int dd = 0;
    if (size % 2 == 0)
      dd = size / 2;
    else
      dd = ceil((double)size / 2);
    Team newTeamBook[dd];
    memset(newTeamBook, 0, sizeof(newTeamBook));
    int x = 0;
    if (size % 2 == 0)
    {
      for (int i = 0; i < size; i += 2)
      {
        printf("\t\n\n%s vs %s", a[i].name, a[i + 1].name);
        if ((rand() % 2) == 0)
        {
          printf("\t\n%s wins.\n", a[i].name);
          newTeamBook[x] = a[i];
          newTeamBook[x].strongPlayer = rand() % 9;
          newTeamBook[x].weakPlayer = 11 - newTeamBook[x].strongPlayer;
          newTeamBook[x].teamOpinion = (double)(newTeamBook[x].strongPlayer * 100) / 11;
          x++;
        }
        else
        {
          printf("\t\n%s wins.\n", a[i + 1].name);
          newTeamBook[x] = a[i + 1];
          newTeamBook[x].strongPlayer = rand() % 9;
          newTeamBook[x].weakPlayer = 11 - newTeamBook[x].strongPlayer;
          newTeamBook[x].teamOpinion = (double)(newTeamBook[x].strongPlayer * 100) / 11;
          x++;
        }
        // start here , here you have to match two
        // teams and store them in newly created
        // array i.e newTeamBook
        //
      }
    }
    else
    {
      newTeamBook[x] = a[0]; // team qualifies to next round
      newTeamBook[x].strongPlayer = rand() % 9;
      newTeamBook[x].weakPlayer = 11 - newTeamBook[x].strongPlayer;
      newTeamBook[x].teamOpinion = (double)(newTeamBook[x].strongPlayer * 100) / 11;
      x++;

      for (int i = 1; i < size; i += 2)
      {
        if (x > dd - 1)
          break;
        printf("\t\n\n%s vs %s", a[i].name, a[i + 1].name);
        if ((rand() % 2) == 0)
        {
          printf("\t\n%s wins.\n", a[i].name);
          newTeamBook[x] = a[i];
          newTeamBook[x].strongPlayer = rand() % 9;
          newTeamBook[x].weakPlayer = 11 - newTeamBook[x].strongPlayer;
          newTeamBook[x].teamOpinion = (double)(newTeamBook[x].strongPlayer * 100) / 11;
          x++;
        }
        else
        {
          printf("\t\n%s wins.\n", a[i + 1].name);
          newTeamBook[x] = a[i + 1];
          newTeamBook[x].strongPlayer = rand() % 9;
          newTeamBook[x].weakPlayer = 11 - newTeamBook[x].strongPlayer;
          newTeamBook[x].teamOpinion = (double)(newTeamBook[x].strongPlayer * 100) / 11;
          x++;
        }
      }
    }

    schedulerMatches(newTeamBook, round + 1, dd);
    memset(newTeamBook, 0, sizeof(newTeamBook));
    // after creation of newlyTeamBook
    // pass that array in
    // schedulermatches() function
    // it will run until size of team is 1.
  }

  getch();
  return;
}
