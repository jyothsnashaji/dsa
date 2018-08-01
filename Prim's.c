#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct adjlist
{int key,d,w;
 struct adjlist* parent;
 struct adjlist* next;
 };
 
 struct adjlist* adj[10000];
 int n;
 int n2;
 int e;
 int sum=0;
 int head=0;


void sort()
{int i,j=0;
 struct adjlist* temp[n];
 for(i=head;i<n;++i)
 temp[j++]=adj[i];
  n2=j;
 

 
 for( i=0;i<n2-1;++i)
 { 
 for(int j=0;j<n2-i-1;++j)
    {
    if(temp[j]->d > temp[j+1]->d)
      {struct adjlist* t=temp[j];
       temp[j]=temp[j+1];
       temp[j+1]=t;
       
       }
    }
  }
 for(int i=head;i<n;++i)
  {adj[i]=temp[i-head];
  //printf("//%d %d//",adj[i]->key,adj[i]->d);
  }
       
}
void insert(struct adjlist** head,long int k)
{struct adjlist* p= (struct adjlist*)malloc(sizeof(struct adjlist));
struct adjlist* l= (struct adjlist*)malloc(sizeof(struct adjlist));
struct adjlist* prev= (struct adjlist*)malloc(sizeof(struct adjlist));
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


 int checkbelong(int x)
 {for(int i=head;i<n;++i)
   if(adj[i]->key==x)
     return 1;
  return 0;
 }
 
 struct adjlist* extract_min()
 { if(head==n-1)
   {head=-1;
    return adj[n-1];
    }
   else
    {++head;
     return adj[head-1];
     }
  }
 
/*int getweight(int x,int y)
{for(int i=0;i<e;++i)
  if(edg[i].src==x && edg[i].dest==y)
    return edg[i].w;
 } */

 void mst()
 {adj[0]->d=0;
  
  int i,j;
  
  while(head!=n-1)
  {
   struct adjlist* l=extract_min();
   
  
   for(i=0;i<n;++i)
    {if(l->key==adj[i]->key)
      break;
     }
   l=adj[i]->next;
  // printf("\nkey: %d d: %d",adj[i]->key,adj[i]->d); 
   
   while(l!=NULL)
   {int f=checkbelong(l->key);
    
    
    for(j=0;j<n;++j)
       {if(l->key==adj[j]->key)
          break;
        }
     //printf("\nbefore key:%d d:%d f:%d w:%d",adj[j]->key,adj[j]->d,f,w);
    if(f==1 && l->w<adj[j]->d)
     {
      adj[j]->d=l->w;
      //printf("\nafter key: %d d: %d",adj[j]->key,adj[j]->d); 
      sort();
      //printf("\nhead: %d",adj[head]->key);
     }
    l=l->next;
    }
   }
 }
 
 
 int main()
{int d,start;
char ch=0;
 scanf("%d",&n);
 ch=getchar();
 for(int i=0;i<n;++i)
 {struct adjlist* temp=(struct adjlist*)malloc(sizeof(struct adjlist));
  temp->key=i;
  temp->next=NULL; 
  temp->d=32567;
  
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
  struct adjlist* l;
  for(int i=0;i<n;++i)
 {  
  l=adj[i]->next;
  while(l!=NULL)
  {scanf("%d",&d);
   l->w=d;
   
   l=l->next;
   ++e;
   }
   
 } 
   n2=n;
   //sort();
  //printedg();
 mst();
  for(int i=0;i<n;++i)
   sum=sum+adj[i]->d;
  printf("%d",sum);
  return 0;
  
  }
