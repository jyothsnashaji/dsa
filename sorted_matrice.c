#include<stdio.h>

/*Every row and column is sorted in
increasing order. Write a program to find whether a given element K is
present in matrix or not in O(M+N)*/

int main()
{int i,j,a[1000][1000];
 int m,n,k;
 scanf("%d %d",&m,&n);
 for(i=0;i<m;++i)
 for(j=0;j<n;++j)
 scanf("%d",&a[i][j]);
scanf("%d",&k);
int f=-1;
i=0;
j=n-1;
while(0<=i && i<=m && 0<=j && j<=n)
{//printf("..%d %d..",i,j);
if (a[i][j]==k)
  {f=1;
  break;}
 if (a[i][j]<k)
     ++i;
 else
    --j;

}
printf("%d ",f);
return 0;
}
