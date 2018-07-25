#include<stdio.h>

void merge3(int a[],int s,int s1,int s2,int e)
{if (s<=s1 && s1<=s2 && s2<=e)
 {int A[100000],i,j,k,l=s;
  i=s;
  j=s1+1;
  k=s2+1;
  
/*for(int i=s;i<=e;++i)
 printf("/%d/",a[i]);*/

while(i<=s1 && j<=s2 && k<=e)
  {if(a[i]<a[j])
      if(a[i]<a[k])
         A[l++]=a[i++];
	else
	 A[l++]=a[k++];
   else
      if(a[j]<a[k])
         A[l++]=a[j++];
      else
	A[l++]=a[k++];
}
if(i>s1)
{while((j<=s2) && (k<=e))
{ if(a[j]<a[k])
 { A[l++]=a[j++];
// printf("%d %d ",a[k],A[i]);
  
 }
  else
  {A[l++]=a[k++];
  //printf("%d %d ",a[k],A[j]);
  }
}
//printf("\n %d %d %d \n ",i,j,k);

 if(j<=s2)
 { while(j<=s2)
   A[l++]=a[j++];}
  else
   {while(k<=e)
    A[l++]=a[k++];}
}


else if (k>e)
{while((i<=s1) && (j<=s2))
{ if(a[i]<a[j])
 { A[l++]=a[i++];
// printf("%d %d ",a[k],A[i]);
  
 }
  else
  {A[l++]=a[j++];
  //printf("%d %d ",a[k],A[j]);
  }
}
//printf("\n %d %d %d \n ",i,j,k);

 if(i<=s1)
 { while(i<=s1)
   A[l++]=a[i++];}
  else
   {while(j<=s2)
    A[l++]=a[j++];}
}
else
{while((i<=s1) && (k<=e))
{ if(a[i]<a[k])
 { A[l++]=a[i++];
// printf("%d %d ",a[k],A[i]);
  
 }
  else
  {A[l++]=a[k++];
  //printf("%d %d ",a[k],A[j]);
  }
}
//printf("\n %d %d %d \n ",i,j,k);

 if(i<=s1)
  {while(i<=s1)
    A[l++]=a[i++];}
  else
  { while(k<=e)
   A[l++]=a[k++];}
}
for(i=s;i<=e;++i)
a[i]=A[i];

/*for(int i=s;i<=e;++i)
 printf("...%d ...",a[i]);*/
 }
}


void mergesort(int a[],int start,int end)
{if(start<end)
{int third=(end-start)/3;
 mergesort(a,start,start+third);
 mergesort(a,start+third+1,start+2*third);
mergesort(a,start+2*third+1,end);
merge3(a,start,start+third,start+2*third,end);

}}

int main()
{FILE *fp,*fpr;
 int a[1000000],num;
int n=0;
char c;
/* fp=fopen("in","wb");
 do
{ scanf("%d",&a[n]);
fprintf(fp,"%d ",a[n]);
++n;
c=getchar();
}while(c!='\n');
fclose(fp);*/
n=0;
fpr=fopen("in","rb");

while(fscanf(fpr,"%d",&num)!=EOF)
{a[n]=num;
++n;
}

fclose(fpr);
mergesort(a,0,n-1);

fp=fopen("out","wb");
for(int i=0;i<n;++i)
 fprintf(fp,"%d ",a[i]);
fclose(fp);
/*fp=fopen("out","rb");
for(int i=0;i<n;++i)
{fscanf(fp,"%d",&num);
 a[i]=num;}
fclose(fp);

for(int j=0;j<n;++j)
printf("%d ",a[j]);*/
return 0;
}
