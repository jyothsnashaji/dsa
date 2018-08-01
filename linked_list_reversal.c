#include<stdio.h>
#include<stdlib.h>


//reversing a linked list

struct list
{long int data;
 struct list* next;
 };
 struct list* l;
 struct list* first;


 

void insert(long int k)
{struct list* p= (struct list*)malloc(sizeof(struct list));
 p->next=NULL;
 p->data=k;
if(l==NULL)
{
l=p;
first=p;}
else
    {
l->next=p;
 //printf("%ld",first.data);
      l=p;}
 }
 
void reverse()
{struct list* prev= (struct list*)malloc(sizeof(struct list));
struct list* present= (struct list*)malloc(sizeof(struct list));
struct list* next= (struct list*)malloc(sizeof(struct list));

prev=NULL;
present=first;
while(present!=NULL)
{next=present->next;
 present->next=prev;
 prev=present;
 present=next;
}
first=prev;
}

 void display()
 {l=first;
  do
  {printf("%ld ",l->data);
   l=l->next;
   }while(l!=NULL);
  }     
int main()
{char c;
 long int k;
 c=0;
 while(c!='\n')
 {scanf("%ld",&k);
  
insert(k);
  c=getchar();
  }
  reverse();
  display();
  return 0;
  }
