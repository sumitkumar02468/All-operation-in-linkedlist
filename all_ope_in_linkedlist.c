#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
//This function use to create new linkedlist.
struct node *createll(struct node *head,int n)
{
if(n==0)
return head;
printf("Enter your data\n");
scanf("%d",&head->data);
struct node *nnode,*ptr;
ptr=head;
for(int i=1;i<n;i++)
{
nnode=(struct node*)malloc(sizeof(struct node));
nnode->next=NULL;
scanf("%d",&nnode->data);
ptr->next=nnode;
ptr=ptr->next;
}
ptr=head;
return head;
}
//This function use to print new linkedlist.
void printll(struct node *head)
{
while(head!=NULL)
{
printf("%d ",head->data);
head=head->next;
}
}
//This function use to insert new node in linkedlist.
struct node *insNode(struct node *head)
{
int pos=0,n=1;
printf("Enter the position of linkedlist, where you want to insert a new node\n");
scanf("%d",&pos);
struct node *ptr,*nnode;
ptr=head;
if(pos==1)
{
nnode=(struct node*)malloc(sizeof(struct node));
printf("Enter your data\n");
scanf("%d",&nnode->data);
nnode->next=ptr;
head=nnode;
}
else
{
while(n<pos-1)
{
ptr=ptr->next;
n++;
}
nnode=(struct node*)malloc(sizeof(struct node));
printf("Enter your data\n");
scanf("%d",&nnode->data);
nnode->next=ptr->next;
ptr->next=nnode;
}
ptr=head;
return head;
}
//This function use to delete node from linkedlist.
struct node *deleteNode(struct node *head)
{
struct node *ptr,*ptr2;
int pos=0,i=1;
printf("Enter the position of node, whict you want to delete\n");
scanf("%d",&pos);
ptr=head;
if(pos==1)
{
head=ptr->next;
free(ptr);
}
else
{
ptr=head;
ptr2=ptr->next;;
while(i<pos-1)
{
ptr=ptr->next;
ptr2=ptr->next;
i++;
}
ptr->next=ptr2->next;
free(ptr2);
}
ptr=head;
return head;
}
//This function use to edit a node in linkedlist.
struct node *editNode(struct node *head)
{
struct node *ptr;
int pos=0,n=1;
printf("Enter the position of node, which you want to edit\n");
scanf("%d",&pos);
ptr=head;
while(n<pos)
{
ptr=ptr->next;
n++;
}
printf("Enter your new data\n");
scanf("%d",&ptr->data);
ptr=head;
return head;
}

void main()
{
struct node *createll(struct node *head,int n);
struct node *deleteNode(struct node *head);
struct node *editNode(struct node *head);
struct node *insNode(struct node *head);
void printll(struct node *head);
int n,choice=0;
struct node *head,*ptr,*nnode;
head=(struct node*)malloc(sizeof(struct node));
do
{
printf("\n1. CREATE LINKEDLIST\n2. PRINT LINKEDLIST\n3. EDIT NODE\n4. DELETE NODE\n5. INSERT NODE\n");
printf("Enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
printf("Enter how many node you want to create\n");
scanf("%d",&n);
ptr=createll(head,n);
}
break;
case 2:
printll(ptr);
break;
case 3:
ptr=editNode(ptr);
break;
case 4:
ptr=deleteNode(ptr);
break;
case 5:
ptr=insNode(ptr);
break;
default:
{
printf("Enter a valid choice\n");
exit(0);
}
}
}while(choice<6);
}
