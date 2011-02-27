#include<stdio.h>
#include<stdlib.h>

typedef struct
{
int **a;
char **b;
float **c;
} complex;

void inputlist(complex );

void main()
{
int choice = 1, retr = 1;
complex P1;
complex P2;
while(retr == 1)
{
printf("\n=================================================================================");
printf("\n					MENU					   ");
printf("\n=================================================================================");
printf("\n\n1. Input a list");
printf("\n2. Perform operations on default list");
printf("\n3. Exit");
printf("\n\n=================================================================================");
printf("\nInput choice : ");
scanf("%d", &choice);
printf("=================================================================================\n");
switch(choice)
{
case 1 : inputlist(P1);
         break;
case 2 : break;
case 3 : exit(0);
default : printf("\n\nWRONG INPUT VALUE!!!!");
          break;
}
printf("To go back to the menu, press 1... ");
scanf("%d", &retr);
}
}

void inputlist(complex c1)
{
}
