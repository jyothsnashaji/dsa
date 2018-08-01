#include<stdio.h>
#include<stdlib.h>

struct queue
{
long int head;
long int tail;
long int n;
long int *a;
};
struct queue q;

void enqueue(long int k)
{ if ((q.head==0 && q.tail==q.n-1) || (q.head==q.tail+1))
    printf("-2\n");
  else
  { if (q.head==-1)
      {++q.head;
       ++q.tail;
       q.a[q.head]=k;}
    else if (q.tail==q.n-1)
    {q.tail=0;
     q.a[q.tail]=k;}
     else
      {++q.tail;
        q.a[q.tail]=k;}
    }
}

void print_queue()
{long int i;
 for(i=q.head;i<=q.tail;++i)
   printf("%ld ",q.a[i]);
 if(q.tail<q.head)
   {for(i=q.head;i<=q.n-1;++i)
   printf("%ld ",q.a[i]);
   for(i=0;i<=q.tail;++i)
    printf("%ld ",q.a[i]);
    }
    printf("\n");
}
         
void dequeue()
{if (q.head==-1)
  printf("-1\n");
 else
   {if(q.head==q.tail)
    {printf("%ld \n",q.a[q.head]);
    q.head=-1;
    q.tail=-1;
   }
else
{printf("%ld \n",q.a[q.head]);
  if(q.head==q.n-1)
    q.head=0;
  else
   ++q.head;
 }  
 }
 }


int main()
{long int k;
 char c;
 scanf("%ld",&q.n);
 q.a=(long int*)malloc(q.n*sizeof(long int));
 q.head=-1;
q.tail=-1;
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
