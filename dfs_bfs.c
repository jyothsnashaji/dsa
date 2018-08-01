#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list
{int key,d;
 char colour;
 struct list* parent;
 struct list* next;
 };
 
 struct list* adj[10000];
 struct list* q[10000];
 struct list* s[10000];
 int head=-1;
 int tail=-1;
 int n;
 int k;
 int top=-1;
 
 void push(struct list* l)
 {++top;
  s[top]=l;
 }
 
 struct list* pop()
 {--top;
   return s[top+1];}


void enqueue(struct list* k)
{ if ((head==0 && tail==n-1) || (head==tail+1))
    printf("-2\n");
  else
  { if (head==-1)
      {++head;
       ++tail;
       q[head]=k;}
    else if (tail==n-1)
    {tail=0;
     q[tail]=k;}
     else
      {++tail;
        q[tail]=k;}
    }
}

/*void print_queue()
{long int i;
 for(i=head;i<=tail;++i)
   printf("%d ",q[i]->key);
 if(tail<head)
   {for(i=head;i<=n-1;++i)
   printf("%d ",q[i]->key);
   for(i=0;i<=tail;++i)
    printf("%d ",q[i]->key);
    }
    printf("\n");
}*/
         
struct list* dequeue()
{int t=head;
 if (head==-1)
  printf("-1\n");
 else
   {if(head==tail)
    {
    head=-1;
    tail=-1;
   
    return q[t];
   }
else
{
  if(head==n-1)
    head=0;
  else
   ++head;
   return q[t];
 }  
 }
 }

void bfs(int start,int k)
{int j,i=0;
//printf("hello1");
 for(i=0;i<n;++i)
  {adj[i]->colour='W';
   adj[i]->d=32567;
   }
//printf("hello2");
 adj[start]->colour='G';
 adj[start]->d=0;
//printf("hello3");
 enqueue(adj[start]);
 printf("%d ",adj[start]->key);

 
 while(head!=-1)
 {struct list* l=dequeue();
  for(i=0;i<n;++i)
    if(l->key==i)
       break;
  l=adj[i]->next;
  while(l!=NULL)
  {for(j=0;j<n;++j)
    if(l->key==j)
       break;
   if(adj[j]->colour=='W')
  { printf("%d ",j);
    if(j==k)
     {head=-1;
      return;}
   adj[j]->colour='G';
   adj[j]->d=adj[i]->d+1;
   enqueue(adj[j]);}
   l=l->next;
  }
  adj[i]->colour='B';
 }
 }


/*void display(struct list* l)
{
while(l!=NULL)
 {//s=s*10+l->data;
  printf("%d ",l->key);
  l=l->next;
}
//printf("%ld",s);
}


void printadj()
{for(int i=0;i<n;++i)
  {printf("\n");
  display(adj[i]);}
}*/

void insert(struct list** head,long int k)
{struct list* p= (struct list*)malloc(sizeof(struct list));
struct list* l= (struct list*)malloc(sizeof(struct list));
struct list* prev= (struct list*)malloc(sizeof(struct list));
    p->next=NULL;
    p->key=k;
 l=*head;
 prev=*head;
 l=l->next;
if (l==NULL)
 {
  (*head)->next=p;}
 else
{while(l!=NULL && l->key<p->key)
   {prev=l;
   l=l->next;}
   prev->next=p;
   p->next=l;
    }
}


int ex;

void dfs_visit(struct list* l)

{int i,j;

 for(i=0;i<n;++i)
   if(l->key==i)
     break;

 adj[i]->colour='G';
 printf("%d ",i);
  if(i==k)
  ex=1;

 struct list *t;
 t=adj[i]->next;
 while(t!=NULL)
 { for(j=0;j<n;++j)
   if(t->key==j)
     break;

  if(adj[j]->colour=='W')
  {if(!ex)
   dfs_visit(adj[j]);}
  t=t->next;
 }

  
 adj[i]->colour='B';
 //printf("%d ",adj[i]->key);
}



void dfs(int start)
{

 for(int i=0;i<n;++i)
  adj[i]->colour='W';
  ex=0;
 dfs_visit(adj[start]);
 
 }

void dfs_stack(int start)
{int j,i=0;

 for(i=0;i<n;++i)
  {adj[i]->colour='W';
   
   }

 adj[start]->colour='G';
 
 push(adj[start]);


 
 while(top!=-1 )
 {struct list* l=pop();
  
  for(i=0;i<n;++i)
    if(l->key==i)
       break;
 
 printf("%d ",i);
  if(i==k)
   {top=-1;
    return;}
  l=adj[i]->next;
  while(l!=NULL)
  {for(j=0;j<n;++j)
    if(l->key==j)
       break;
  //printf("hello");
   if(adj[j]->colour=='W')
  { //printf("// pushing j %d//\n",j);
    
   adj[j]->colour='G';
   push(adj[j]);
   }
   l=l->next;
  }
  adj[i]->colour='B';
 }
 }



int main()
{int d,start;
char ch=0;
 scanf("%d",&n);
 ch=getchar();
 for(int i=0;i<n;++i)
 {struct list* temp=(struct list*)malloc(sizeof(struct list));
  temp->key=i;
  temp->next=NULL; 
  adj[i]=temp;
   ch=getchar();
 while(ch!='\n')
  { d=0;
   while(ch!='\n' && ch!=' ')
   {d=10*d+ch-48;
    ch=getchar();}
   insert(&adj[i],d);
   if(ch!='\n')
    ch=getchar();}
  
 } 
   //printadj();  
     
     
 char s[10];
 scanf("%s",s);
 for(;;)
 {if(strcmp(s,"bfs")==0)
    {scanf("%d %d",&start,&k);
      //printf("hello");
     bfs(start,k);
     printf("\n");
    }
  else if(strcmp(s,"dfs")==0)
    {scanf("%d %d",&start,&k);
     dfs_stack(start);
     printf("\n");}
  else
   return 0;
  scanf("%s",s);
  }
  }
  
