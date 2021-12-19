#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

struct Team
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

Team TeamBook[16]; // Global Variable for storing all details about teams

// randomizer function
void randomizer(Team *A, int size)
{
  for (int i = 0; i < size; i++)
  {
    A->key = i + 1;
    char name[15];
    for (char c : name)
    {
      c = (char)(rand() % 'z') + 'a';
    }
    strcpy(A->name, name);
    A->strongPlayer = (rand() % 11) + 1;
    A->weakPlayer = 11 - A->strongPlayer;
    A->teamOpinion = (double)(A->strongPlayer * 100) / 11;
    A->publicOpinion = (double)((rand() % 100) + 1);
    A->matchesWon = 0;
    A->matchesLost = 0;
  }
}
// function to enter details by yourself
void entryYourself(int size)
{
  for (int i = 0; i < size; i++)
  {
    system("cls");
    TeamBook[i].key = i + 1;
    printf("Enter details of %d team mmenber\n", TeamBook[i].key);
    printf("\tEnter the name of team\n", &TeamBook[i].name);
    printf("\tEnter no of string players\n", &TeamBook[i].strongPlayer);
    printf("\tEnter no Public Opinion \n", &TeamBook[i].publicOpinion);
    TeamBook[i].weakPlayer = 11 - TeamBook[i].strongPlayer;
    TeamBook[i].teamOpinion = (double)(TeamBook[i].strongPlayer * 100) / 11;
    TeamBook[i].matchesWon = 0;
    TeamBook[i].matchesLost = 0;
  }
}
// function to enter details by computer itself
void entryComputer(int size)
{
  randomizer(&TeamBook, size);
}
// Details Entry
void enterDetails()
{
  int a;
  system("cls");
  printf("\tEnter the number of teams ( Power of 2 ) and below 16 only !\n");
  scanf("%d", &a);
  if (log2(a) <= 4)
  {
    char ch;
    system("cls");
    printf("\tWant to enter the details by yourself\n \tor\n \twant the Computer to do it\n");
    printf("\t Enter Y(yourself) or C(Computer)\n ");
    scanf("%c", &ch);
    switch (ch)
    {
    case 'Y':
      entryYourself(a);
      break;
    case 'C':
      entryComputer(a);
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
  printf(" SL.no \t Name\t SP   WP   TO   PO   MW    ML\n");
  for (int i = 0; i < 16; i++)
  {
    printf(" %d\t%s\t%d%d%f%f%d%d", TeamBook[i].key, TeamBook[i].name, TeamBook[i].strongPlayer, TeamBook[i].weakPlayer, TeamBook[i].teamOpinion, TeamBook[i].publicOpinion, TeamBook[i].matchesWon, TeamBook[i].matchesLost);
  }
}
// void DisplayResults();
// void schedulerMatches();
int main()
{
  while (1)
  {
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
      printf("Hello\n");
      // schedulerMatches();
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