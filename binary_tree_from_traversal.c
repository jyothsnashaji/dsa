#include<stdio.h>
#include<stdlib.h>


struct tree
{long int key;
 struct tree* left;
 struct tree* right;
 };
 

long int* pre;
long int* in;
long int n;

void inorder(struct tree* bst)
{  if(bst!=NULL)
   {inorder(bst->left);
    printf("%ld ",bst->key);
    inorder(bst->right);
    }
   
   }
 
 void preorder(struct tree* bst)
 {if(bst!=NULL)
  {printf("%ld ",bst->key);
   preorder(bst->left);
   preorder(bst->right);
   }
  
 }
 
 void postorder(struct tree* bst)
 {if(bst!=NULL)
  {postorder(bst->left);
   postorder(bst->right);
   printf("%ld ",bst->key);
   }
  
 }  

void make_bt(struct tree** bt,long int start,long int end)
{static int i=0;
if(start>end)
 *bt=NULL;
else
{int j,flag=0;
 struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
     temp->key=pre[i];
     temp->left=NULL;
     temp->right=NULL;
     *bt=temp;
     ++i;
 if(start!=end)
 {
 for (j=start;j<=end;++j)
  {if(in[j]==pre[i-1])
    {
     ++flag;
     break;
    }
  }
 if(flag==1)
  {
   make_bt(&((*bt)->left),start,j-1);
   make_bt(&((*bt)->right),j+1,end);
   }
 }  
}
}

//long int count;
void print(struct tree* bt)
{printf("(");
 if(bt!=NULL)
 
 {printf("%ld ",bt->key);
  print(bt->left);
  print(bt->right);
  }
 printf(")");
 }



int main()
{long int i;
 struct tree* bt=NULL;
 scanf("%ld",&n);
 pre=(long int*)malloc(n*sizeof(long int));
 in=(long int*)malloc(n*sizeof(long int));
 
 for(i=0;i<n;++i)
  scanf("%ld",&pre[i]);
  
 for(i=0;i<n;++i)
  scanf("%ld",&in[i]);
  
  /* for(i=0;i<n;++i)
  printf("%ld ",pre[i]);
  for(i=0;i<n;++i)
  printf("%ld ",in[i]);*/
 
  
//count=0;  
make_bt(&bt,0,n-1);

/*preorder(bt);
printf("\n");
inorder(bt);
printf("\n");
postorder(bt);
printf("\n");*/
print(bt);

return 0;
}
 
