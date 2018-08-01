#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct adjlist
{int key,d,v;
 struct adjlist* next;
 };
 
 struct adjlist* adj[10000];
 
 int n;
struct edges
{int src,dest,w;
};

struct edges edg[10000];
int e;

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

void printedg()
{for(int i=0;i<e;++i)
  {printf("\n %d %d %d",edg[i].src,edg[i].w,edg[i].dest);
  }
}

int getweight(int x,int y)
{for(int i=0;i<e;++i)
  if(edg[i].src==x && edg[i].dest==y)
    return edg[i].w;
 } 


void short_tree()
{int i,s,j;

    adj[0]->d=0;
  
 for(i=1;i<n;++i)
 {
    adj[i]->d=32760;
   adj[i]->v=0;
  }

 for(j=0;j<n;++j)
 {int t;
  s=32760;
  for(i=0;i<n;++i)
   {if(adj[i]->d<s && adj[i]->v==0)
     {s=adj[i]->d;
       t=i;}
    }
 // printf("\n key:%d d:%d",adj[t]->key,adj[t]->d);
   struct adjlist* l=adj[t]->next;
   while(l!=NULL)
   {int w=getweight(adj[t]->key,l->key);
     if(adj[l->key]->d > w+adj[t]->d)
      adj[l->key]->d=w+adj[t]->d;
     l=l->next;
    }
    adj[t]->v=1;
  }

}









int main()
{int i,j;

 scanf("%d",&n);
 scanf("%d",&e);
  for( i=0;i<e;++i)
 scanf("%d %d %d",&edg[i].src,&edg[i].dest,&edg[i].w);
  j=-1;
  for(i=0;i<e;++i)
   {if(j!=edg[i].src)
     {++j;
      struct adjlist* temp=(struct adjlist*)malloc(sizeof(struct adjlist));
      adj[j]=temp;
      adj[j]->key=j;
      }
     insert(&adj[j],edg[i].dest);
   }
  // printedg();
    
     
  
 short_tree();   
 for(i=0;i<n;++i)
 {struct adjlist* l=adj[i]->next;
  while(l!=NULL)
  {if(adj[l->key]->d > adj[i]->d +getweight(adj[i]->key,l->key))
   {printf("1");
    return 0;
    }
   l=l->next;
   }
  }
  printf("-1");
  return 0;
  } 
    
 
 
 
 
  
  


