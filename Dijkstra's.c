#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct adjlist
{int key,d,v,w;
 struct adjlist* next;
 };
 
 struct adjlist* adj[10000];
 
 int n;


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






void short_tree(int start)
{int i,s,j;
 for(i=0;i<n;++i)
 {if(adj[i]->key==start)
    adj[i]->d=0;
  else
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
   {
     if(adj[l->key]->d > l->w +adj[t]->d)
      adj[l->key]->d=l->w+adj[t]->d;
     l=l->next;
    }
    adj[t]->v=1;
  }

}









int main()
{int d,start,k;
char ch=0;
 scanf("%d",&n);
 ch=getchar();
 for(int i=0;i<n;++i)
 {struct adjlist* temp=(struct adjlist*)malloc(sizeof(struct adjlist));
  temp->key=i;
  temp->next=NULL; 
  temp->d=32760;
  
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
   
   }
   
 } 
 
 //printedg();
 
 char s[10];
 scanf("%s",s);
 for(;;)
 {if(strcmp(s,"apsp")==0)
    {scanf("%d",&start);
     short_tree(start);
     for(int i=0;i<n;++i)
     {if(adj[i]->d==32760)
       printf("INF ");
      else printf("%d ",adj[i]->d);}
     printf("\n");
    }
  else if(strcmp(s,"sssp")==0)
    {scanf("%d %d",&start,&k);
     short_tree(start);
     
     d=adj[k]->d;
     if(d==32760 || d<0)
      printf("UNREACHABLE\n");
     else
     printf("%d\n",d);}
  else
   return 0;
  scanf("%s",s);
  }
  }
  


