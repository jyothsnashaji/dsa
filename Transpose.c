#include <stdio.h>

//Find transpose of a matrice recursively and prints result spirally

void swap(int *a, int *b)
{
*a=*a+*b;
*b=*a-*b;
*a=*a-*b;
}
void transpose(long int n,long int i,long int j,long int a[][n])
{
    if (i<n)
    {
    if (i>j)
    {   
        swap(&a[i][j],&a[j][i]);
     
    transpose(n,i,++j,a);}
     else
      transpose(n,++i,0,a);}
 
}

int main() 
{ long int n,i,j,p,k=0;
scanf("%ld",&n);
long int a[n][n];
{for(i=0;i<n;++i)
for(j=0;j<n;++j)
scanf("%ld",&a[i][j]);}
if (n==1)
{ printf("%ld",a[0][0]);
exit(0);}
transpose(n,0,1,a);


if(n==2)
p=1;
else
p=(n+1)/2;

while(k<n-p)
{
    for(i=k,j=k;j<n-k-1;++j)
printf("%ld ", a[i][j]);

for(i=k;i<n-k-1;++i)
printf("%ld ", a[i][j]);

for(j=n-k-1;j>k;--j)
printf("%ld ", a[i][j]);

for(i=n-k-1;i>k;--i)
printf("%ld ", a[i][j]);


++k;}
if (n%2)
printf("%ld",a[n-2][n-2]);
	return 0;
}


