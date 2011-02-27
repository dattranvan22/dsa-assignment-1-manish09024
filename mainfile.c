#include<stdio.h>
#include<stdlib.h>

typedef struct
{
int *a;
char *b;
float *c;
} complex;

int inputlist(complex );
void displaylist(complex , int , int );
int secondary_menu(complex c1);
void Fflush(void);

void main()
{
int choice, retr = 1;
complex P1;
while(retr == 1)
{
printf("\n=================================================================================");
printf("\n					MENU");
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
case 1 : retr=inputlist(P1);
         break;
case 2 : break;
case 3 : exit(0);
default : printf("\n\nWRONG INPUT VALUE!!!!");
          break;
}
if(retr==0)
{
printf("To go back to the menu, press 1... ");
scanf("%d", &retr);
}
}
}

int inputlist(complex c1)
{
int s1_ch;
printf("\n\nPress 1 for numbers.");
printf("\nPress 2 for characters.");
printf("\nPress 3 for float numbers.");
printf("\nInput choice : ");
scanf("%d", &s1_ch);
int num, retr3;
switch(s1_ch)
{
case 1 : printf("\n\nHow many elements do you wish to enter?");
         printf("\nInput value : ");
         scanf("%d", &num);
         c1.a = malloc((num)*sizeof(int));
         int i;
         for(i=0;i<num;i++)
         {
         printf("\nInput integer %d : ", i+1);
         scanf("%d", &c1.a[i]);
         }
         displaylist(c1, 1, num);
	 retr3=secondary_menu(c1);
         break;
case 2 : printf("\n\nHow many elements do you wish to enter?");
         printf("\nInput value : ");
         scanf("%d", &num);
	 c1.b = malloc((num)*sizeof(char));
         int j;
	 Fflush();
         for(j=0;j<num;j++)
	 {
	 printf("\nInput character %d : ", j+1);
	 scanf("%c", &c1.b[j]);
	 Fflush();
	 }
	 displaylist(c1, 2, num);
	 retr3=secondary_menu(c1);
	 break;
case 3 : printf("\n\nHow many elements do you wish to enter?");
         printf("\nInput value : ");
         scanf("%d", &num);
	 c1.c = malloc((num)*sizeof(float));
         int k;
         for(k=0;k<num;k++)
	 {
	 printf("\nInput float number %d : ", k+1);
	 scanf("%f", &c1.c[k]);
	 }
	 displaylist(c1, 3, num);
	 retr3=secondary_menu(c1);
	 break;
default : printf("\nWrong input value!!!!");
          break;
}
if(retr3==1)
return 1;
else
return 0;
}



void displaylist(complex c1, int x, int len)
{
int i;
if(x==1)
{
printf("\n");
printf("\n\nThe input list is :");
for(i=0;i<len;i++)
printf("\t%d", c1.a[i]);
printf("\n");
}
else if(x==2)
{
printf("\n");
printf("\n\nThe input list is :");
for(i=0;i<len;i++)
printf("\t%c", c1.b[i]);
printf("\n");
}
else
{
printf("\n");
printf("\n\nThe input list is :");
for(i=0;i<len;i++)
printf("\t\t%0.2f", c1.c[i]);
printf("\n");
}
}



int secondary_menu(complex c1)
{
int ch2,retr2=1;
while(retr2==1)
{
printf("\n\n\n=================================================================================");
printf("\n				SECONDARY MENU");
printf("\n=================================================================================");
printf("\n\n1.  Append");
printf("\n2.  Insert");
printf("\n3.  Extend");
printf("\n4.  Remove");
printf("\n5.  Pop");
printf("\n6.  Index");
printf("\n7.  Count");
printf("\n8.  Sort");
printf("\n9.  Reverse");
printf("\n10. Main menu");
printf("\n\n=================================================================================");
printf("\nInput choice : ");
scanf("%d", &ch2);
printf("=================================================================================\n");
switch(ch2)
{
case 1 : break;
case 2 : break;
case 3 : break;
case 4 : break;
case 5 : break;
case 6 : break;
case 7 : break;
case 8 : break;
case 9 : break;
case 10 : return 1;
default : break;
}
printf("To go back to secondary menu, press 1.");
printf("\nTo return to main menu, press any other key.");
printf("\nInput choice : ");
scanf("%d", &retr2);
}
return 1;
}



void Fflush(void)
{
while(getchar()!='\n');
}
