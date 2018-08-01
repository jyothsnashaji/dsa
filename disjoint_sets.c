#include<stdio.h>
#include<stdlib.h>


struct tree
{int key,rank;
 struct tree* parent;
 };
struct tree* foresta[100000];
struct tree* forestb[100000];
struct tree* forestc[100000];
struct tree* forestd[100000];
int a;
int b;
int c;
int d;
int countf;
int i;
struct tree* find(struct tree* x)
{++countf;
 if(x!=x->parent)
 return find(x->parent);
  else
  return x;
}

struct tree* find1(struct tree* x)
{++countf;
 if(x!=x->parent)
 x->parent= find1(x->parent);
  return x->parent;
}

void make_set(int x)
{int k=0;
 if(foresta[x]!=NULL)
 {if(foresta[x]->key==x)
   k=-1;}
 if(k==-1)
  printf("PRESENT\n");
 else
{struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
 temp->key=x;
 temp->rank=0;
 temp->parent=temp;
 foresta[x]=temp;
 
 struct tree* temp1=(struct tree*)malloc(sizeof(struct tree));
 temp1->key=x;
 temp1->rank=0;
 temp1->parent=temp1;
 forestb[x]=temp1;
 
 struct tree* temp2=(struct tree*)malloc(sizeof(struct tree));
 temp2->key=x;
 temp2->rank=0;
 temp2->parent=temp2;
 forestc[x]=temp2;
 
 struct tree* temp3=(struct tree*)malloc(sizeof(struct tree));
 temp3->key=x;
 temp3->rank=0;
 temp3->parent=temp3;
 forestd[x]=temp3;
 
 printf("%d \n",foresta[x]->key);
 ++i;
}
}
void union_set(int x,int y)
{struct tree *treex,*treey;

//a no path compression or rank
countf=0;
 
  {if(foresta[x]==NULL || foresta[x]->key!=x)
     {++countf;
     }
      }
  
   {if(foresta[x]==NULL || foresta[y]->key!=y)
       {++countf;
   }
     }
  if(countf)
   printf("ERROR\n");
   else{
    //printf("??$%d %d??",a,countf);
    countf=0;
    treex=find(foresta[x]);
    treey=find(foresta[y]);
    if(treex!=treey)
    {
    a=a+countf;
    countf=0;
    find(foresta[y])->parent=treex;}

  printf("%d ",treex->key);
    
   
   //b rank
  countf=0;
  treex=find(forestb[x]);
  treey=find(forestb[y]);
 if(treex!=treey)
{
  b=b+countf;
  countf=0;
 
   
  
  if(treex->rank >= treey->rank)
   {forestb[treey->key]->parent=treex;
   {if(treex->rank==treey->rank)
      ++forestb[treex->key]->rank;
    }
    }
  else
    {//printf("pp");
    forestb[treex->key]->parent=treey;
    
    }
  
  
  treex=find(forestb[treex->key]);
  treey=find(forestb[treey->key]);}
  printf("%d ",treex->key);
  
  //c path compression
  
  
  countf=0;
  treex=find1(forestc[x]);
  treey=find1(forestc[y]);
 if(treex!=treey)
{
  c=c+countf;
 //printf("countf: %d ",countf);
  countf=0;
  
   find1(forestc[y])->parent=treex;
}  printf("%d ",treex->key);
  
 //both rank and path compression
 
 
 
 //now j k contains structures to be combined
  countf=0;      
  treex=find1(forestd[x]);
  treey=find1(forestd[y]);
if (treex!=treey)
{
  
 
 struct tree* t;
  if(treex->rank >= treey->rank)
   {forestd[treey->key]->parent=treex;
    t=treex;
    
   {if(treex->rank==treey->rank)
      ++forestd[treex->key]->rank;
    }
    }
  else
    {//printf("pp");
    forestd[treex->key]->parent=treey;
    t=treey;
    }
    d=d+countf;
countf=0;
  
/*for(k=0;k<i;++k)
 {if(find(forestd[k])==treex || find(forestd[k])==treey)
   forestd[k]->parent=t;
   }*/

  printf("%d\n",t->key);
  }
else
 printf("%d\n",treex->key);
}
}

int main()
{
 char ch;
 int x,y,k;
 scanf("%c",&ch);
 
 for(;;)
 {switch(ch)
  {case 'm': scanf("%d",&x);
            make_set(x);
            //printf("hello");
            break;
   case 'f': scanf("%d",&x);
             countf=0;
             {if(foresta[x]==NULL || foresta[x]->key!=x)
              ++countf;
              
             }
             if(countf)
             printf("NOT FOUND\n");
             else
            {countf=0;
             printf("%d ",find(foresta[x])->key);
             a=a+countf;
             countf=0;
             printf("%d ",find(forestb[x])->key);
             b=b+countf;
             countf=0;
             printf("%d ",find1(forestc[x])->key);
             //printf("countf: %d ",countf); 
             c=c+countf;
             countf=0;
             printf("%d\n",find1(forestd[x])->key);
             d=d+countf;
             countf=0;
             }
             break;
   case 'u': //printf("hello1");
             scanf("%d %d",&x,&y);
                         
             union_set(x,y);
             //printf("hello1");
             break;
   case 's':printf("%d %d %d %d",a,b,c,d);
            return 0;
   }
   scanf("%c",&ch);
   }
   }
