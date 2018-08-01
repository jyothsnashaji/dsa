#include<stdio.h>
#include<stdlib.h>

struct queue
{long int data;
 long int count;
 struct queue *next;
};
struct queue* head;
struct queue* tail;
long int n;


void enqueue(long int k)

{struct queue* p= (struct queue*)malloc(sizeof(struct queue));
 struct queue* l= (struct queue*)malloc(sizeof(struct queue));
 l=head;
    p->next=NULL;
    p->data=k;
    
if (head==NULL)
     {
     head=p;
     tail=p;}
 else
     
   {
    tail->next=p;
    tail=p;}

}



void print_queue()
 {struct queue* l= (struct queue*)malloc(sizeof(struct queue));
  l=head;

  do
  {printf("%ld ",l->data);
   l=l->next;
   }while(l!=NULL);
 printf("\n");
  }  




void dequeue()
{if (head==NULL)
   printf("-1 \n");
 else 
   {printf("%ld\n",head->data);
    if(head==tail)
       {head=NULL;
        tail=NULL;}
   else
   head=head->next;

}}

int main()
{long int k;
 char c;

scanf("%c",&c);
 while(c!='s')
{switch(c)
 {case 'e': scanf("%ld",&k);
            enqueue(k);
            break;
  case 'd':dequeue();
            break;
  case 'p': print_queue();
            break;
  default: break;
  }
 scanf("%c",&c);
 }
 
 return 0;
 }
