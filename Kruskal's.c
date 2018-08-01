#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct list
{int key,d,w;
 char colour;
 struct list* parent;
 struct list* next;
 };
 
 struct list* adj[10000];
 int n;
 int e;
 int sum;
 
 struct edge
 {int src,dest,w;
 };
 
 struct edge edg[10000];
 
 struct set
 {int parent,rank;};
  
 struct set dset[10000];
 
 
void printedg()
{for(int i=0;i<e;++i)
  {printf("\n %d %d %d",edg[i].src,edg[i].w,edg[i].dest);
  }
}
 
 int find(int x)
 {if (dset[x].parent!=x)
   dset[x].parent=find(dset[x].parent);
  return dset[x].parent;
 }
 
 void unionset(int a,int b)
 {int x=find(a);
  int y=find(b);
  if(dset[x].rank<dset[y].rank)
   dset[x].parent=y;
  else
    {dset[y].parent=x;
     if(dset[x].rank==dset[y].rank)
      ++dset[x].rank;
    }
 }
 
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

void sort()
{for(int i=0;i<e-1;++i)
  for(int j=0;j<e-i-1;++j)
    if(edg[j].w>edg[j+1].w)
      {struct edge temp=edg[j];
       edg[j]=edg[j+1];
       edg[j+1]=temp;
       }
  }

void mst()
{int i;
 for(i=0;i<e;++i)
  {dset[i].parent=i;
   dset[i].rank=0;
   }
 for(i=0;i<e;++i)
  {int x=find(edg[i].src);
   int y=find(edg[i].dest);
   if(x!=y)
   {sum=sum+edg[i].w;
    unionset(x,y);
   }
   
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
  struct list* l;
  for(int i=0;i<n;++i)
 {  
  l=adj[i]->next;
  while(l!=NULL)
  {scanf("%d",&d);
   l->w=d;
   edg[e].src=i;
   edg[e].w=d;
   edg[e].dest=l->key;
   l=l->next;
   ++e;
   }
   
 } 
  sort(); 
  //printedg();
  mst();
  printf("%d",sum);
  return 0;
  
  }
