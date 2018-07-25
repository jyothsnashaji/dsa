#include<stdio.h>

//quick sort with median as pivot. median chosen in O(n) time

void swap(int *a, int *b)
{int t;
 t=*a;
 *a=*b;
  *b=t;
  }

int partition(int a[], int l,int r)
{int x=a[r];
  int i=l-1;
 for(int j=l;j<r;++j)
 {if (a[j]<x)
   {i=i+1;
   swap(&a[j],&a[i]);
   }
   }
   swap(&a[i+1],&a[r]);
   return i+1;
 }
int findmedian(int a[],int l,int r,int k)
{ for(;;)
  {int p=partition(a,l,r);
   int len=p-l+1;
    if (len==k)
     return p;
    else if (k<=len)
      r=p-1;
     else
      {k=k-len;
      l=p+1;}
  }
  }
  
int count=0;
void quicksort(int a[],int l,int r)
{if (l<r)
 {int q;
 if ((r-l+1)%2==0)
   q=findmedian(a,l,r,(r-l+1)/2);
   else
   q=findmedian(a,l,r,(r-l+1)/2+1);
 if(count<3)
   {printf("%d \n",a[q]);  
    ++count;}
  
   quicksort(a,l,q-1);
   quicksort(a,q+1,r);
   }
   }




int main()
{int a[1000000],i,n;
 scanf("%d",&n);
 for(i=0;i<n;++i)
  scanf("%d",&a[i]);
quicksort(a,0,n-1);              //findmedian(a,0,n-1,n/2+1); for odd and findmedian(a,0,n-1,n/2+1); for even
for(i=0;i<n;++i)
 printf("%d ",a[i]);
 //printf("%d ",findmedian(a,0,n,n/2));
 return 0;
}
