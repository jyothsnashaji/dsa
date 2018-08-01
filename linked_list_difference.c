#include<stdio.h>
#include<stdlib.h>

struct list
{long int data;
 struct list *next;
};
struct list* head1;
struct list* head2;

void insert(struct list** head,long int k)
{struct list* p= (struct list*)malloc(sizeof(struct list));
struct list* l= (struct list*)malloc(sizeof(struct list));
    p->next=NULL;
    p->data=k;
 l=*head;
if (l==NULL)
 {
  *head=p;}
 else
{while(l->next!=NULL)
   l=l->next;
   
    l->next=p;}
}

void display(struct list* l)
{while(l->data==0)
  {if(l->next==NULL)
      printf("0");
   l=l->next;}
while(l!=NULL)
 {//s=s*10+l->data;
  printf("%ld",l->data);
  l=l->next;
}
//printf("%ld",s);
}
    

void reverse(struct list** head)
{struct list* prev= (struct list*)malloc(sizeof(struct list));
struct list* present= (struct list*)malloc(sizeof(struct list));
struct list* next= (struct list*)malloc(sizeof(struct list));

prev=NULL;
present=*head;
while(present!=NULL)
{next=present->next;
 present->next=prev;
 prev=present;
 present=next;
}
*head=prev;
}

void find_biggest(struct list** head1p,struct list** head2p)
{struct list* l= (struct list*)malloc(sizeof(struct list));
l=*head1p;

long long int num1=0;
long long int len1,len2,num2=0;

while(l!=NULL)
{num1=num1*10+l->data;
 l=l->next;}
l=*head2p;
while(l!=NULL)
{num2=num2*10+l->data;
 l=l->next;}

if(num2>num1)
{l=*head1p;
 *head1p=*head2p;
 *head2p=l;}

}

void difference_of_digits(struct list* p,struct list* q)
{if(p!=NULL && q!=NULL)
{//printf("..%ld %ld..",p->data,q->data);
if(p->data < q->data)
   {struct list* nextd;
     nextd=p->next;
     if(p->data<q->data)       
    --nextd->data;
    p->data=p->data+10;
    }
    p->data=p->data-q->data;

    p=p->next;
    q=q->next;



    difference_of_digits(p,q);
    }
 
  }




void zero(struct list** head1p,struct list** head2p)
{struct list* l= (struct list*)malloc(sizeof(struct list));


long int len1,len2;

len1=0;
l=*head1p;
while(l!=NULL)
 {++len1;
l=l->next;}

len2=1;
l=*head2p;
while(l->next!=NULL)
 {++len2;
l=l->next;}

if(len1>len2)
{while(len1>len2)
 {struct list* p= (struct list*)malloc(sizeof(struct list));
    p->next=NULL;
    p->data=0; 
    l->next=p;
l=l->next;
    ++len2;}}
}


int main()
{
char c;
 long int k;
 //scanf("%ld",&k);
 /*do
{insert(&head1,k%10);
 k=k/10;}while(k!=0);
scanf("%ld",&k);
do
{insert(&head2,k%10);
 k=k/10;}while(k!=0);
reverse(&head1);
reverse(&head2);*/
c=getchar();
while(c!='\n')
{insert(&head1,c-48);
 c=getchar();}


 c=getchar();
while(c!='\n')
{insert(&head2,c-48);
 c=getchar();}

find_biggest(&head1,&head2);

reverse(&head1);
reverse(&head2);
difference_of_digits(head1,head2);

reverse(&head1);

 display(head1);
  return 0;
  
}


