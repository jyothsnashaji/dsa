#include<stdio.h>
#include<stdlib.h>

struct table
{long int key;
 struct table* next;
 };


long int* a;
long int m;
struct table* chain;
char c;

void hashtable(long int m)
{
 if(c!='d')
 {a=(long int*)malloc(m*sizeof(long int));
 for(long int i=0;i<m;++i)
  a[i]=-1;
  }
  else
  {chain=(struct table*)malloc(m*sizeof(struct table));
  for(long int i=0;i<m;++i)
   chain[i].next=NULL;
  }
 
  }
void print(long int m)
{if (c!='d')
{for (long int i=0;i<m;++i)
  {
  if (a[i]!=-1)
  printf("%ld(%ld)\n",i,a[i]);
  else
  printf("%ld()\n",i);
  }
  //printf("\n");
 }
else
{for(long int i=0;i<m;++i)
  {struct table *p = &chain[i];
   printf("%ld(",i);
   p=p->next;
   if (p!=NULL)
   {
   do
   { printf("%ld",p->key);
     p=p->next;
     if(p!=NULL)
     printf(" ");
   }while(p!=NULL);
   }
   printf(")\n");
   //break;
  }
  //printf("\n");
 }
}
    
 long int getprime(long int m)
  {long int i,j,k=0;
   for(i=m-1;i>0;--i)
    { for(j=2;j<i/2;++j)
       {if (i%j==0)
         {++k;
          break;}
       }
          
       if(!k)
       return i;
       else
       k=0;
      
     }
   }
 
long int hashf(long int k,long int i)
 {long int r,h;
 switch(c)
 {case 'a': h =((k%m+i)%m);
            break;
  case 'b': h=(k%m+i*i)%m;
            break;
  case 'c':  r=getprime(m);
            h= (k%m + i*(r-k%r))%m;
            break;
  }
  return h;
  }
 
 

void insert(long int k)
{if(c!='d')
{long int h,i=0;
 h=hashf(k,i);
 while((a[h]!=-1) && (i<m))
  {++i;
  h=hashf(k,i);}
   
 if (i==m)
    printf("Table Full\n");
 else
  a[h]=k;
 }
 else
 {long int i=k%m;
  struct table *p=&chain[i];
  while(p->next!=NULL)
   p=p->next;
  struct table *l=(struct table*)malloc(sizeof(struct table));
  l->key=k;
  l->next=NULL;
  p->next=l; 
  
  }
 }
void search(long int k)
{if(c!='d')
{long int h,i=0;
 h=hashf(k,i);
 while((a[h]!=k) && (i<m))
  {++i;
   h=hashf(k,i);}
   
 if (i==m)
    printf("-1\n");
 else
    printf("1\n");
 }
 else
 {long int i=k%m;
  struct table *p=&chain[i];
  p=p->next;
  while(p!=NULL)
   {if (p->key==k)
     {printf("1\n");
      return;}
     p=p->next;
    }
  printf("-1\n");
  }
 }

void delete(long int k)
{if(c!='d')
{long int h,i=0;
 h=hashf(k,i);
 while((a[h]!=k) && (i<m))
  {++i; 
   h=hashf(k,i);}
   
 if (i==m)
    printf("-1\n");
 else
    a[h]=-1;
 }
 else
 {long int i=k%m;
  struct table *p, *l=&chain[i];
  p=l->next;
  while(p!=NULL)
   {
   if (p->key==k)
     {l->next=p->next;
      return;}
      l=p;
     p=p->next;
    }
  printf("-1\n");
  }
 }







int main()
{long int k;
 char c2;
 scanf("%c",&c);
 scanf("%ld",&m);
 //printf("%ld",getprime(m));
hashtable(m);
 scanf("%c",&c2);
 do
 {
  switch(c2)
  {case 'i': scanf("%ld",&k);
             insert(k);
             break;
   case 's': scanf("%ld",&k);
   	     search(k);
             break;
   case 'd': scanf("%ld",&k);
             delete(k);
             break;
   case 'p': print(m);
             break;
   case 't': exit(0);
   }
   scanf("%c",&c2);
 }while(c2!='t');
 
 

 return 0;
 }

