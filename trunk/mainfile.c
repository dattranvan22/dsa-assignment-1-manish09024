#include<stdio.h>
#include<stdlib.h>

typedef struct
{
int *a;
char **b;
float **c;
} complex;

void inputlist(complex );
void displaylist(complex , int , int );

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
int s1_ch;
printf("\n\nPress 1 for numbers.");
printf("\nPress 2 for characters.");
printf("\nPress 3 for float numbers.");
printf("\nInput choice : ");
scanf("%d", &s1_ch);
int num;
switch(s1_ch)
{
case 1 : printf("\n\nHow many elements do you wish to enter?");
         printf("\nInput value : ");
         scanf("%d", &num);
         c1.a = malloc((num)*sizeof(int));
         int i;
         for(i=0;i<num;i++)
         {
         printf("\nInput value of element %d : ", i+1);
         scanf("%d", &c1.a[i]);
         }
         displaylist(c1, 1, num);
         break;
case 2 : break;
case 3 : break;
default : printf("\nWrong input value!!!!");
          break;
}
}


void displaylist(complex c1, int x, int len)
{
int i;
if(x==1)
{
printf("\n\nThe input list is :");
for(i=0;i<len;i++)
printf(" %d", c1.a[i]);
printf("\n");
}
else if(x==2)
{
}
else
{
}
}
