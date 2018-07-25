#include<stdio.h>
#include<stdlib.h>

//Rational Number Arthematic

struct rational
{ int a;
int b;
};
int abs(int x)
{if (x>0)
   return x;
  else
return x*(-1);
}

void makesimple(struct rational *s)
{if((s->a==0)&&(s->b!=0))
s->b=1;
else if((s->a==0)&&(s->b==0))
{return;}
else
{int c=abs(s->a);
 int d=abs(s->b);
int i=2,gcd=1;
while((i<=c)&&(i<=d))
{if((s->a%i==0)&&(s->b%i==0))
gcd=i;
    ++i;
}
s->a/=gcd;
s->b/=gcd;
if(s->a*s->b<0)
 {s->a=abs(s->a)*-1;
  s->b=abs(s->b);}
  
}
}
    
   // printf("%d %d ",s->a,s->b);
   
int findbig(struct rational s[],int n)
    {int i,big=s[0].b;
     
     for(i=0;i<n;++i)
     {if(s[i].b>big)

           big=s[i].b;
     }
     
        return big;
    }
   
   
 void sort(struct rational s[],int n)  
 {int i;
 float big=(findbig(s,n));
 float t[n];

     for(i=0;i<n;++i)
     {t[i]=s[i].a;
    t[i]=t[i]*big/s[i].b;
     }
   
     float key;
     int t1,t2;
    for(int j=1;j<n;++j)
 {key=t[j];
  t1=s[j].a;
  t2=s[j].b;
 i=j-1;
 while((i>=0)&&(t[i]>key))
 {t[i+1]=t[i];
     s[i+1].a=s[i].a;
 s[i+1].b=s[i].b;
 i=i-1;
 }
 t[i+1]=key;
 s[i+1].a=t1;
 s[i+1].b=t2;
 }
 
}

int main()
{struct rational s,s1;


int c;
scanf("%d",&c);
switch (c)
{case 1:
 {scanf("%d %d",&s.a,&s.b);
makesimple(&s);
 printf("%d/%d",s.a,s.b);

 }
 break;
 case 2: 
 {scanf("%d %d",&s.a,&s.b);
  scanf("%d %d",&s1.a,&s1.b);
  if((s.b==0)||(s1.b==0))
  {printf("ERROR");
  exit(0);}
  s.a=s.a*s1.b+s1.a*s.b;
  s.b=s.b*s1.b;
  makesimple(&s);
     printf("%d/%d",s.a,s.b);
 }
  break;
    case 3: 
    {scanf("%d %d",&s.a,&s.b);
  scanf("%d %d",&s1.a,&s1.b);
if((s.b==0)||(s1.b==0))
  {printf("ERROR");
  exit(0);}
  s.a=s.a*s1.a;
  s.b=s.b*s1.b;
  makesimple(&s);
   printf("%d/%d",s.a,s.b);
    }
    break;
case 4:
{int n,i;
scanf("%d ",&n);
struct rational s[n];
for(i=0;i<n;++i)
{scanf("%d %d",&s[i].a,&s[i].b);
 if (s[i].b==0)
  {printf("ERROR");
   exit(0);}}
sort(s,n);

for(i=0;i<n;++i)
{
makesimple(&s[i]);
printf(" %d/%d",s[i].a,s[i].b);}

}
break;
case 5:{
scanf("%d %d",&s.a,&s.b);
makesimple(&s);
printf("%d/%d",s.a,s.b);}
break;
default:printf("ERROR");

}
return 0;

}
