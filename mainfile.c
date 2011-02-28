#include<stdio.h>
#include<stdlib.h>

int *Main_list;

int inputlist(int * );
void displaylist(int * , int * );
int secondary_menu(int * , int * );
void append_list(int * , int * );
void extend_list(int * , int * );
void insert_list(int * , int * );
void remove_item(int * , int * );



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



int secondary_menu(int *c3, int *len)
{
int ch2,retr2=1;
while(retr2==1)
{
printf("\v\v\v\v\v=================================================================================");
printf("\n				SECONDARY MENU");
printf("\n=================================================================================");
printf("\n\n1.  Append");
printf("\n2.  Extend");
printf("\n3.  Insert");
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
case 2 : extend_list(c3, len);
	 break;
case 3 : insert_list(c3, len);
	 break;
case 4 : remove_item(c3, len);
	 break;
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
int i=(*len);
c4[i] = (int)malloc((1)*sizeof(int));
printf("\nEnter element to input in the list : ");
scanf("%d", &c4[i]);
(*len) = (*len) + 1;
displaylist(c4, len);
}



void extend_list(int *c5, int *len)
{
int n,i;
printf("\n\nHow many elements to you want to add in the list?");
printf("\nInput value : ");
scanf("%d", &n);
for(i=(*len);i<((*len)+n);i++)
{
c5[i] = (int)malloc((1)*sizeof(int));
printf("\nEnter element %d of list : ", i+1);
scanf("%d", &c5[i]);
}
(*len) = (*len) + n;
displaylist(c5, len);
}



void insert_list(int *c6, int *len)
{
int val, pos;
printf("\nValue of element to be inserted : ");
scanf("%d", &val);
printf("\nPosition of element in list (taking zero as 1st element) : ");
scanf("%d", &pos);
if(pos==(*len))
{
c6[pos] = (int)malloc((1)*sizeof(int));
c6[pos] = val;
(*len) = (*len) + 1;
displaylist(c6, len);
}
else if(pos<(*len) && pos>-1)
{
c6[pos] = val;
displaylist(c6, len);
}
else
printf("\n\n\nWrong position entered!!!\n\n\n");
}



void remove_item(int *c7, int *len)
{
int val, i, j, tmp, flag, pos;
printf("\nThis will delete the first occurence of the element in the list...");
printf("\nEnter the value of the element : ");
scanf("%d", &val);
for(i=0;i<(*len);i++)
{
if((c7[i]==val) && (i<(*len)-1))
{
pos = i;
for(j=i;j<(*len)-1;j++)
c7[j] = c7[j+1];
(*len) = (*len)-1;
flag = 1;
break;
}
else if((c7[i]==val) && (i==(*len)-1))
{
(*len) = (*len)-1;
flag = 1;
pos = i;
break;
}
else
flag = 0;
}
if(flag==1)
{
printf("\n\nElement found and deleted at position %d...\n", pos+1);
displaylist(c7, len);
}
else
printf("\n\nElement not in list...!!!\n");
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
