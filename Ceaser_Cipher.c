#include<stdio.h>
#include<ctype.h>
#include<string.h>

//To Encrypt or Decrypt a word by shifting the alphabets by k

int main()
{long int n;
int c,k,i;


scanf("%d",&c);
if (c>2)
{ printf("ERROR");
 exit(0);}

scanf ("%ld",&n);
char s[n];

scanf(" %[^\n]s",&s);

scanf("%d",&k);

k=k%26;
switch(c)
{case 1:
{for(i=0;i<n;++i)

{  
   if(isupper(s[i])!=0)
   {if (s[i]+k>'Z')
         s[i]=k-26+s[i];
        else
         s[i]+=k;}


 else if(islower(s[i])!=0)
       {if (s[i]+k>'z')
         s[i]=k-26+s[i];
        else
         s[i]+=k;}
     
     
}} break;
case 2:{
for(i=0;i<n;++i)

{  
   if(isupper(s[i])!=0)
 {if (s[i]-k<'A')
         s[i]=26-k+s[i];
        else
         s[i]-=k;}


 else if(islower(s[i])!=0)
      {if (s[i]-k<'a')
         s[i]=26-k+s[i];
        else
         s[i]-=k;}
break;
default: printf("ERROR");


}}

}
printf("%s \n ",s);
return 0;
}

                                                                                                                             


