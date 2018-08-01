#include<stdio.h>
#include<stdlib.h>

struct pq
{long int data;
 long int pr;
};

long int n;
struct pq pq1[1000000];

void swap(struct pq *a,struct pq  *b)
{struct pq temp=*b;
  *b=*a;
  *a=temp;
  }
  void print(struct pq p[])
{for (int i=1;i<=n;++i)
  printf("...%ld(%ld)...",pq1[i].data,pq1[i].pr);   }
  
   long int parent(long int i)
  {return i/2;}
   
   
   void min_heapify(struct pq pq1[],long int i)
{long int l,r,smallest;
 l=2*i;
 r=2*i+1;
 if (l<=n && pq1[l].pr<pq1[i].pr)
  smallest=l;
 else
  smallest=i;
   if (r<=n && pq1[r].pr<pq1[smallest].pr)
  smallest=r;
  

 if (smallest!=i)
  { swap(&pq1[i],&pq1[smallest]);
   min_heapify(pq1,smallest);
   }
   }
  
   void heapdecreasekey(struct pq pq1[],long int i,long int p)
 {pq1[i].pr=p;
  
  while(i>1 && pq1[i/2].pr>pq1[i].pr)
  { swap(&pq1[i],&pq1[i/2]);
    
    i=i/2;}
    }
void insert(struct pq pq1[],long int k,long int p)
{
  
long int i;
for(i=n/2;i>1;--i)
  min_heapify(pq1,i);

 ++n;
 pq1[n].pr=0;
 pq1[n].data=k;

 heapdecreasekey(pq1,n,p);
 //print(pq1);
}
 

   
void extract_min(struct pq pq1[])
{if (n<1)
  printf("EMPTY\n");
  else
   {printf("%ld(%ld)\n",pq1[1].data,pq1[1].pr);
   pq1[1].data=pq1[n].data;
   pq1[1].pr=pq1[n].pr;
    --n;
    min_heapify(pq1,1);
    //print(pq1);
 }
 
}
  void get_min()
  {if (n<1)
  printf("EMPTY\n");
  else
  printf("%ld(%ld)\n",pq1[1].data,pq1[1].pr);}
  
  void decrease_priority(struct pq pq1[],long int k,long int p)
  {long int i;
   for(i=1;i<=n;++i)
    {if(pq1[i].data==k)
      {
       heapdecreasekey(pq1,i,p);
       break;}}}
       

       
       
       

int main()
{long int k,p;
 char c;
 n=0;
// pq1=(struct pq*)malloc(sizeof(struct pq));

 scanf("%c",&c);
 while(c!='s')
{switch(c)
 {case 'a': scanf("%ld",&k);
            scanf("%ld",&p);
//printf("//%ld//",pq1[2].data);
            insert(pq1,k,p);
//printf("//%ld//",pq1[2].data);
            //print(pq1);
            break;
  case 'e':extract_min(pq1);
            break;
  case 'g': get_min();
            break;
  case 'd':scanf("%ld",&k);
           scanf("%ld",&p);
           decrease_priority(pq1,k,p);
           //print(pq1);
  default: break;
  }
//printf("@@%ld@@\n",pq1[2].data);
 scanf("%c",&c);
 }
 
 return 0;
 }
