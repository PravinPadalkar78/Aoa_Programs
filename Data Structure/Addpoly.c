#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int c,e;
   struct node *next;
}node;

typedef struct
{
	node *start;
}LL;
void insertend(LL *l,int cc,int ee)
{
	node *newrec,*p;
	newrec= (node*)malloc(sizeof(node));
	newrec->c=cc;
	newrec->e=ee;
	
	newrec->next=NULL;
	if(l->start==NULL)
	{
		l->start=newrec;	
	}
	else
	{
		p=l->start;
		while(p->next!=NULL)
		  {
			p=p->next;
		  }	
	    p->next=newrec;	
    }
}
void read(LL *l)
{
	int cc,ee,n,i;
	printf("enter number of elements\n");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("enter the coffe and expo\n");
		scanf("%d%d",&cc,&ee);
		insertend(l,cc,ee);
	}
	printf("\n");
}
void Addpoly(LL *l1,LL *l2,LL *l3)
{
	node *p,*q;
	p=l1->start;
	q=l2->start;
	while(p!=NULL&&q!=NULL)
	{
		if(p->e>q->e)
		{
			insertend(l3,p->c,p->e);
			p=p->next;
		}
		else if(q->e>p->e)
		{
			insertend(l3,q->c,q->e);
			q=q->next;
		}
		else
		{
			insertend(l3,p->c+q->c,p->e);
			p=p->next;
			q=q->next;
		}
	}
}
void display(LL *l)
{
	node *p;
	p=l->start;
	if(p==NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	else
	{
		while(p!=NULL)
		{
			printf(" %dX^%d",p->c,p->e);
			p=p->next;
		}
		printf("=0");
		printf("\n");
	}
}
int main()
{
	LL l1,l2,l3;
	l1.start=NULL;
	l2.start=NULL;
	l3.start=NULL;
	read(&l1);
	read(&l2);
	Addpoly(&l1,&l2,&l3);
	display(&l3);
}
