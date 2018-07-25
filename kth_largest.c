#include<stdio.h>

//Kth largest element in an unsorted array of size
//N in O(N + K log(N) ) time.


int left(int i)
{return 2*i;}

int right(int i)
{return 2*i+1;
}

void maxheap(int a[],int n,int i)
{int l,r,largest;
 l=left(i);
 r=right(i);
if(l<=n || r<=n)
{
 largest=i;
 if(l<=n && a[i]<a[l])
   largest=l;
 if(r<=n && a[r]>a[largest])
   largest=r;
if(largest!=i)
 {int t=a[i];
  a[i]=a[largest];
  a[largest]=t;
maxheap(a,n,largest);
}
}}

int extract(int a[],int n)
{if (n>1)
  {int max=a[1];
   a[1]=a[n];
   --n;
   maxheap(a,n,1);
  return max;}}


int main()
{int a[1000000],i,n,k,max;
 scanf("%d",&n);
 for(i=1;i<=n;++i)
 scanf("%d",&a[i]);
 scanf("%d",&k);
for(i=n/2;i>0;--i)
 maxheap(a,n,i);
 
for(i=0;i<k;++i)
 max= extract(a,n);

 printf("%d ",max);
return 0;
}
