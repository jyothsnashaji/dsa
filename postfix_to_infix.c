#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 struct string
{char ch;
struct string *next;
struct string *prev;
}  *stack[1000000];
long int top=1000000;
typedef struct string string;
 
void push(string *str)
{stack[top] = str;
 top--;
}
 
string *pop()
{string *p;
p = stack[++top];
return p;
}

int st[1000000];
int top2=0;

void push_c(int n)
{st[top2]=n;
 top2++;}
 
int pop_c()
{int n=st[--top2];
return n;}


void display(string *temp)
{
	if (temp != NULL)
	{
		display(temp->prev);
		if(temp->ch >36 && temp->ch <48)
		printf("%c",temp->ch);
		else
		printf("%d",temp->ch);
		display(temp->next);
	}
}


void convert(char p[])
{
	string *op1,  *op2;
	
	long int i;
	int num=0;
	for (i=0;p[i]!='\0';i++)
       {if (isdigit(p[i]))
        {do
          {num=num*10+p[i]-48;
           ++i;}while(isdigit(p[i]));
           string *temp= (string*)malloc(sizeof(string));
          temp->ch = (int)num;
      	  temp->next = NULL;
	  temp->prev = NULL;
	  push(temp);
          num=0;
         }
      
	
	else if(!isspace(p[i]))
	{string *temp= (string*)malloc(sizeof(string));
		op1 = pop();
		op2 = pop();
		
		temp->ch =(char)p[i];
		temp->next = op1;
		temp->prev = op2;
		push(temp);
	}
	}
	 display(pop());
}
 
void evaluate(char p[])
{long int i;
 int num1,num2,num=0;
 for(i=0;p[i]!='\0';++i)
  {if (isdigit(p[i]))
        {do
          {num=num*10+p[i]-48;
           ++i;}while(isdigit(p[i]));
    push_c(num);
    
    num=0;
         }
    
    
   else if(!isspace(p[i]))
   {num1=pop_c();
    num2=pop_c();
   /* printf("...%d...\n",num1);
    printf("..%d..\n",num2);*/
    switch(p[i])
    {case '+' : push_c(num1+num2);
                break;
     case '-' : push_c(num2-num1);
                break;
     case '*' : push_c(num1*num2);
                break;
     case '/' : push_c(num2/num1);
                break;
     case '%' : push_c(num2%num1);
                break;
     }
    }
    }
    printf("\n%d",pop_c());
} 
 



   
 
int main()
{long int len=0,num=0;
      char c;
  char *p=(char*)malloc(sizeof(char));
      c=getchar();
     while(c!='\n')
       {p[len++]=c;
        c=getchar();
        }
    p[len]='\0'; 

   
      convert(p);
     evaluate(p);
       return 0;
}
