#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree
{long int key;
 struct tree* left;
 struct tree* right;
 };
 
struct tree* getparent(struct tree* bst,struct tree* bt,struct tree* parent)
{if(bst!=NULL)
  {if(bst==bt)
    return parent;
   else if(bt->key<=bst->key)
    getparent(bst->left,bt,bst);
   else
    getparent(bst->right,bt,bst);
  }
  else 
   return parent;
 }
 
 
 void insert(struct tree** bst,long int k)
 { struct tree* b=*bst;
  if(b==NULL)
  {struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
   temp->key=k;
   temp->left=NULL;
   temp->right=NULL;
   *bst=temp;}
  else if(k<=b->key)
   insert(&(b->left),k);
  else
   insert(&(b->right),k);
   
 }
 
 void search(struct tree* bst,long int k)
 {if(bst!=NULL)
  {if(bst->key==k)
    printf("FOUND\n");
   else if(k<=bst->key)
    search(bst->left,k);
   else
    search(bst->right,k);
  }
  else 
   printf("NOT FOUND\n");
 }
 
 void findMin(struct tree* bst)
 {if(bst==NULL)
   printf("NIL\n");
  else
  if(bst->left!=NULL)
   findMin(bst->left);
  else
   printf("%ld\n",bst->key);
 }
 
 void findMax(struct tree* bst)
 {if(bst==NULL)
  printf("NIL\n");
  else
  if(bst->right!=NULL)
  findMax(bst->right);
  else
  printf("%ld\n",bst->key);
 }
 
 void predecessor(struct tree* bst,long int k)
{ if(bst!=NULL)
 {struct tree* root=bst;
  while(bst->key!=k)
  {if(k<=bst->key)
    bst=bst->left;
   else
    bst=bst->right;
   }
  if(bst->left!=NULL)
    findMax(bst->left);
  else
    {struct tree* parent;
     parent=getparent(root,bst,NULL);
     while(parent!=NULL && parent->left==bst)
      {bst=parent;
       parent=getparent(root,bst,NULL);
       }
      if(parent==NULL)
       printf("NIL\n");
      else
       printf("%ld \n",parent->key);
     }
}
else
printf("NOT FOUND\n");
}
 
 
 void successor(struct tree* bst,long int k)
 {if(bst!=NULL)
 {struct tree* root=bst;
  while(bst->key!=k)
  {if(k<=bst->key)
    bst=bst->left;
   else
    bst=bst->right;
   }
  if(bst->right!=NULL)
    findMin(bst->right);
  else
    {struct tree* parent;
     parent=getparent(root,bst,NULL);
     while(parent!=NULL && parent->right==bst)
      {bst=parent;
       parent=getparent(root,bst,NULL);
       }
      if(parent==NULL)
       printf("NIL\n");
      else
       printf("%ld \n",parent->key);
     }
}
else 
printf("NOT FOUND\n");
}
 

 
 
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
 void findnode(struct tree** bst,long int k);
  void delete(struct tree** bst,long int k)
 {
  struct tree* b=*bst;
 
  if(b->left==NULL && b->right==NULL)
   {*bst=NULL;
   }
  else if(b->left==NULL)
   { b=b->right;
     *bst=b;
     }
  else if(b->right==NULL)
   { b=b->left;
     *bst=b;
    }
  else
   {struct tree* pred;
    pred=b->left;
    while(pred!=NULL && pred->right!=NULL)
     pred=pred->right;
     struct tree* temp=pred;
     findnode(bst,pred->key);
     temp->left=(*bst)->left;
     temp->right=(*bst)->right;
     *bst=temp;
   
    }
  //inorder(*bst);
  }
 
 void findnode(struct tree** bst,long int k)
 {struct tree* b=*bst;
   if (b->key==k)
    delete(bst,k);
   else  
   if(k<=b->key)
    findnode(&(b->left),k);
   else
    findnode(&(b->right),k);
 }
 
 
 
int main()
{char c[5];
long int k;
struct tree* bst=NULL;
scanf("%s",c);
 do
 {
  if(strcmp(c,"insr")==0)
   {scanf("%ld",&k);
    //printf("%ld ",bst);
    insert(&bst,k);
    //printf("%ld ",bst);
    }
  else
   if(strcmp(c,"srch")==0)
    {scanf("%ld",&k);
     search(bst,k);}
  else
   if(strcmp(c,"minm")==0)
    {findMin(bst);
     }
  else
   if(strcmp(c,"maxm")==0)
    {findMax(bst);
     }
  else
   if(strcmp(c,"pred")==0)
    {scanf("%ld",&k);
     //printf("%ld ",bst->key);
     predecessor(bst,k);
     }
  else
   if(strcmp(c,"succ")==0)
    {scanf("%ld",&k);
     successor(bst,k);
     }
  else
   if(strcmp(c,"delt")==0)
    {scanf("%ld",&k);
     findnode(&bst,k);
     }
  else
   if(strcmp(c,"inor")==0)
    {inorder(bst);
     printf("\n");}
  else
   if(strcmp(c,"prer")==0)
    {preorder(bst);
     printf("\n");}
  else
    if(strcmp(c,"post")==0)
     {postorder(bst);
      printf("\n");}
   else
     break;
   scanf("%s",c);
   }while(strcmp(c,"stop")!=0);
   
 return 0;
 }     
