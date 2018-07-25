#include<stdio.h>

/*Given a sorted rotated array of N distinct integers, search a given
element in this array in O(logN)*/

int pivot(int a[],int b, int e)
{int p=0;
while(b<=e)
 {int mid=(b+e)/2;
  if(a[mid-1]<=a[mid] && a[mid] > a[mid+1])
    { return mid+1;
       break;}

 p= pivot(a,b,mid-1);
if (p==0)
 p=pivot(a,mid+1,e);
return p;
}}

int search(int a[],int b,int e,int k)
 {int p=-1;
if (b<=e)
{ int mid=(b+e)/2;
 
 if (a[mid]==k)
  return mid;
 else if(a[mid]>k)
   p= search(a,b,mid-1,k);
else
  p=  search(a,mid+1,e,k);}
 return p;
 
}
int main()
{int n,i,k,p;
 int a[1000000];
 scanf("%d",&n);
 for(i=0;i<n;++i)
 scanf("%d",&a[i]);
scanf("%d",&k);
p=pivot(a,0,n-1);

if(search(a,0,p-1,k)<0 && search(a,p,n-1,k)<0)
printf("-1");
else if (search(a,0,p-1,k)>=0)
 printf("%d",search(a,0,p-1,k));
else if (search(a,p,n-1,k)>=0)
 printf("%d",search(a,p,n-1,k));
return 0;
}
