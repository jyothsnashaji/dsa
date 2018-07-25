#include<stdio.h>
#include<string.h>

//Reversing a strng recursively without extra space

void swap (char *a, char *b)
{ *a+=*b;
   *b=*a-*b;
 *a-=*b;}
void reverse (char s[],long int n, long int i)
{if (i>0)
{  if(n%2)
    { swap(&s[n/2-i],&s[n/2+i]);
     reverse(s,n,--i);
   }

else

   { swap(&s[n/2-i],&s[n/2+i-1]);
     reverse(s,n,--i);
  }
}
else
 printf("\n %s \n",s);
}


int main()
{
long int n;
char s[1000000];
scanf("%[^\n]s",&s);
n=strlen(s);

reverse(s,n,n/2);

return 0;
}

