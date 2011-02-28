#include<stdio.h>
#include<stdlib.h>

int *Main_list;

int inputlist(int * );
void displaylist(int * , int * );
int secondary_menu(int * , int * );
void append_list(int *, int * );

void main()
{
int choice, retr = 1;
while(retr == 1)
{
printf("\v\v\v\v\v=================================================================================");
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
case 1 : retr=inputlist(Main_list);
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

int inputlist(int *c1)
{
int num;
printf("\n\nHow many elements do you wish to enter?");
printf("\nInput value : ");
scanf("%d", &num);
int *p;
p = &num;
c1 = malloc((num)*sizeof(int));
int i;
for(i=0;i<num;i++)
{
printf("\nInput integer %d : ", i+1);
scanf("%d", &c1[i]);
}
displaylist(c1, p);
if(secondary_menu(c1, p)==1)
return 1;
else
return 0;
}



void displaylist(int *c2, int *len)
{
int i;
printf("\n");
printf("\n\nThe input list is :");
for(i=0;i<(*len);i++)
printf("\t%d", c2[i]);
printf("\n");
}



int secondary_menu(int *c3, int *len)
{
int ch2,retr2=1;
while(retr2==1)
{
printf("\v\v\v\v\v=================================================================================");
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
printf("\n10. Display");
printf("\n11. Main menu");
printf("\n\n=================================================================================");
printf("\nInput choice : ");
scanf("%d", &ch2);
printf("=================================================================================\n");
switch(ch2)
{
case 1 : append_list(c3, len);
	 break;
case 2 : break;
case 3 : break;
case 4 : break;
case 5 : break;
case 6 : break;
case 7 : break;
case 8 : break;
case 9 : break;
case 10 : displaylist(c3, len);
          break;
case 11 : return 1;
default : break;
}
printf("To go back to secondary menu, press 1.");
printf("\nTo return to main menu, press any other key.");
printf("\nInput choice : ");
scanf("%d", &retr2);
}
return 1;
}



void append_list(int *c4, int *len)
{
int n,i;
printf("\n\nHow many elements to you want to add in the list?");
printf("\nInput value : ");
scanf("%d", &n);
for(i=(*len);i<((*len)+n);i++)
{
c4[i] = malloc((1)*sizeof(int));
printf("\nEnter element %d of list : ", i+1);
scanf("%d", &c4[i]);
}
(*len) = (*len) + n;
displaylist(c4, len);
}
