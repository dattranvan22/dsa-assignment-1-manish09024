#include<stdio.h>
#include<stdlib.h>

struct complex
{
int data;
struct complex *link;
} *first=NULL, *last=NULL;

int *Main_list;

int inputlist(int * );
int inputlist1();


void displaylist(int * , int * );
void displaylist1();


int secondary_menu(int * , int * );
int secondary_menu1();


void append_list(int * , int * );
void add_node(int );


void extend_list(int * , int * );
void extend_ll_list();


void insert_list(int * , int * );
void insert_ll_list(int , int );


void remove_item(int * , int * );


void pop_item(int * , int * );
void pop_ll_item();


void index_item(int * , int * );


void count_item(int * , int * );
void count_ll_item(int );


void sort_list(int * , int * );
void sort_ll_list();


void reverse_list(int * , int * );



void main()
{
int choice, retr = 1;
while(retr == 1)
{
printf("\v\v\v\v\v=================================================================================");
printf("\n					MENU");
printf("\n=================================================================================");
printf("\n\n1. Input a list and perform operations using arrays");
printf("\n2. Input a list and perform operations using linked lists");
printf("\n3. Exit");
printf("\n\n=================================================================================");
printf("\nInput choice : ");
scanf("%d", &choice);
printf("=================================================================================\n");
switch(choice)
{
case 1 : retr = inputlist(Main_list);
         break;
case 2 : retr = inputlist1();
	 break;
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



int inputlist1()
{
int num,flag=0;
int ch=1;
struct complex *n;
while(ch==1)
{
if(flag==0)
{
printf("\nEnter the value of the element : ");
scanf("%d", &num);
n=malloc(sizeof(struct complex));
n->data=num;
n->link=NULL;
first=n;
last=n;
flag=1;
displaylist1();
}
else
{
printf("\nEnter the value of the element : ");
scanf("%d", &num);
n=malloc(sizeof(struct complex));
n->data=num;
n->link=NULL;
last->link=n;
last=n;
displaylist1();
}
printf("\n\nInput 1 to add more elements.");
printf("\nInput : ");
scanf("%d",&ch);
}
if(secondary_menu1()==1)
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
case 5 : pop_item(c3, len);
	 break;
case 6 : index_item(c3, len);
	 break;
case 7 : count_item(c3, len);
	 break;
case 8 : sort_list(c3, len);
	 break;
case 9 : reverse_list(c3, len);
	 break;
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



int secondary_menu1()
{
int ch2, retr2=1, val1;
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
case 1 : printf("\nInput the value of the element you want to append : ");
	 scanf("%d", &val1);
	 add_node(val1);
	 displaylist1();
	 break;
case 2 : extend_ll_list();
	 break;
case 3 : printf("\nEnter value to insert : ");
	 int v,p;
	 scanf("%d", &v);
	 printf("\nAt what position do you want to enter the element : ");
	 scanf("%d", &p);
	 insert_ll_list(v, p);
	 break;
case 4 : break;
case 5 : pop_ll_item();
	 break;
case 6 : break;
case 7 : printf("\nEnter value whose occurences you want to find : ");
	 int v0;
	 scanf("%d", &v0);
	 count_ll_item(v0);
	 break;
case 8 : sort_ll_list();
	 break;
case 9 : break;
case 10 : displaylist1();
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



void add_node(int num)
{
struct complex *n;
n=malloc(sizeof(struct complex));
n->data=num;
n->link=NULL;
if(first==NULL)
{
first=n;
last=first;
}
else
{
last->link=n;
last=n;
}
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



void extend_ll_list()
{
int num;
printf("\n\nHow many elements do you wish to enter?");
printf("\nInput value : ");
scanf("%d", &num);
int a[num];
int i;
for(i=0;i<num;i++)
{
printf("\nInput value %d : ", i+1);
scanf("%d", &a[i]);
}
for(i=0;i<num;i++)
add_node(a[i]);
displaylist1();
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



void insert_ll_list(int num, int pos)
{
int c=1;
struct complex *temp,*n;
n=malloc(sizeof(struct complex));
for(temp=first;temp!=NULL;temp=temp->link)
{
if(pos==1)
{
n->data=num;
n->link=first;
first=n;
displaylist1();
break;
}
else if(pos==c+1)
{
n->data=num;
n->link=temp->link;
temp->link=n;
displaylist1();
break;
}
else
c++;
}
printf("\nThe input position is incorrect!!!\n");
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



void pop_item(int *c8, int *len)
{
if((*len)>0)
{
printf("\nThe last element of the list has been popped...\n");
(*len) = (*len) - 1;
displaylist(c8, len);
}
else
{
printf("\n!!!UNDERFLOW!!!");
printf("\nEmpty list!! No element to pop!!!\n");
}
}



void pop_ll_item()
{
struct complex *tmp;
for(tmp=first;tmp!=NULL;tmp=tmp->link)
{
if(tmp->link==last)
{
tmp->link=NULL;
last=tmp;
break;
}
if(first==last)
{
first=NULL;
last=NULL;
break;
}
}
displaylist1();
}



void index_item(int *c9, int *len)
{
int i, val, flag=0;
printf("\nEnter value to be searched in the list : ");
scanf("%d", &val);
for(i=0;i<(*len);i++)
{
if(c9[i]==val)
{
flag = 1;
break;
}
else
flag = 0;
}
if(flag!=0)
printf("\nElement found at position %d...\n", i+1);
else
printf("\nElement not in list...!!!\n");
}



void count_item(int *c9, int *len)
{
int i, val, cnt=0;
printf("\nEnter value of the element whose total number of occurences");
printf("\nis to be found in the list : ");
scanf("%d", &val);
for(i=0;i<(*len);i++)
{
if(c9[i]==val)
cnt++;
}
if(cnt!=0)
printf("\nThe element appeared %d times in the list...\n", cnt);
else
printf("\nThe input element does not exist in the list...\n");
}



void count_ll_item(int num)
{
struct complex *temp;
int len=0;
for(temp=first;temp!=NULL;temp=temp->link)
{
if(temp->data==num)
len++;
}
if(len!=0)
{
displaylist1();
printf("\nThe number of occurences are : %d\n", len);
}
else
printf("\nThe element does not exist in the list!!!\n");
}



void sort_list(int *c8, int *len)
{
int temp, i, swapflag;
do
{
swapflag = 0;
for(i=0;i<(*len)-1;i++)
{
if(c8[i]>c8[i+1])
{
temp =  c8[i];
c8[i] = c8[i+1];
c8[i+1] = temp;
swapflag = 1;
}
}
}while(swapflag == 1);
printf("\nThe list has been sorted...");
displaylist(c8, len);
}



void sort_ll_list()
{
struct complex *temp1,*temp2;
int temp;
for(temp1=first;temp1->link!=NULL;temp1=temp1->link)
{
for(temp2=temp1->link;temp2!=NULL;temp2=temp2->link)
{
if((temp2->data)<(temp1->data))
{
temp=temp1->data;
temp1->data=temp2->data;
temp2->data=temp;
}
}
}
printf("\nThe list has been sorted...");
displaylist1();
}



void reverse_list(int *c7, int *len)
{
int temp, i, j;
if((*len)%2!=0)
{
for(i=0,j=(*len)-1;i<((*len)-1)/2,j>((*len)-1)/2;i++,j--)
{
temp = c7[i];
c7[i] = c7[j];
c7[j] = temp;
}
}
else
{
for(i=0,j=(*len)-1;i<(*len)/2,j>=(*len)/2;i++,j--)
{
temp = c7[i];
c7[i] = c7[j];
c7[j] = temp;
}
}
printf("\nThe list has been reversed...");
displaylist(c7, len);
}



void displaylist(int *c2, int *len)
{
if((*len)>0)
{
int i;
printf("\n");
printf("\n\nThe list of elements is :");
for(i=0;i<(*len);i++)
printf("\t%d", c2[i]);
printf("\n");
}
else
printf("\nThe list is empty!!!!\n");
}



void displaylist1()
{
struct complex *tmp;
if(first!=NULL)
{
printf("\n\nThe List is : ");
for(tmp=first;tmp!=NULL;tmp=tmp->link)
{
if(tmp->link!=NULL)
printf("%d -> ",tmp->data);
else
printf("%d", tmp->data);
}
printf("\n");
}
else
printf("\nThe list is empty!!!!\n");
}
