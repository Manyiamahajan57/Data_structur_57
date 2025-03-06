// application to convert the infix expression into the postfix 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <malloc.h>
// This function is used to check the precedence of the operators 
int precedence(char opr)
{
    switch(opr)
    {
        case '+':
        case '-':
        return 1 ;
        break;
        case '*':
        case '/':
        return 2;
        break;
        case '^':
        return 3;
        break;
        default:
        return -1;
    }
}

char* infixconversiontopostfix(char *exp)  // this will be taken in char* because to use malloc function 
{
    int size = strlen(exp);
    char operators[size];
   
    char* str = (char*)malloc(size+1);
    int top=-1,index=0;
    for (int i=0 ; i<size ; i++)
    {
        char ch = exp[i];
        if (isdigit(ch) || isalpha(ch))   
        {
            str[index++]=ch;          
        }
        else if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        {
            if(top==-1)
            {
                operators[++top]=ch;
            }
            else
            {
                while (top!=-1 && precedence(ch)<=precedence(operators[top]))
                {
                    str[index++]=operators[top--];
                }
                operators[++top]=ch;
            }
        }
        else if (ch=='(')
        {
            operators[++top]=ch;
        }
        else if (ch==')')
        {
            while (operators[top]!='(')
            {
               str[index++]=operators[top--];
            }
            top--;   // this is used to remove the whole expression term ()..
        }
    }
    while (top!=-1)
    {
        str[index++]=operators[top--];
    }
    str[index]='\0';
    return str;
}
int main ()
{
    char exp[100];
    printf("Enter the infix expression : ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = 0;
    printf("Postfix form of infix expression is %s is %s\n",exp,infixconversiontopostfix(exp));
    return 0;
}

// application to convert the infix into the prefix 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <malloc.h>
char* strrev(char* s){
    char* s1 = (char*)malloc(strlen(s)+1);
    int i,j;
    for(i=strlen(s)-1, j=0; i>=0; i--, j++){
        s1[j]=s[i];
    }
    s1[j]='\0';
    return s1;
}
// This function is used to check the precedence of the operators 
int precedence(char opr)
{
    switch(opr)
    {
        case '+':
        case '-':
        return 1 ;
        break;
        case '*':
        case '/':
        return 2;
        break;
        case '^':
        return 3;
        break;
        default:
        return -1;
    }
}

char* infixtoprefix(char *exp) 
{
    int size = strlen(exp);
    char operators[size];
   
    char* str = (char*)malloc(size+1);
    int top=-1,index=0;
    for (int i=size-1 ; i>=0 ; i--)
    {
        char ch = exp[i];
        if (isdigit(ch) || isalpha(ch))   
        {
            str[index++]=ch;          
        }
        else if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        {
            if(top==-1)
            {
                operators[++top]=ch;
            }
            else
            {
                while (top!=-1 && precedence(ch)<=precedence(operators[top]))
                {
                    str[index++]=operators[top--];
                }
                operators[++top]=ch;
            }
        }
        else if (ch==')')
        {
            operators[++top]=ch;
        }
        else if (ch=='(')
        {
            while (operators[top]!=')')
            {
               str[index++]=operators[top--];
            }
            top--;
        }
    }
    while (top!=-1)
    {
        str[index++]=operators[top--];
    }
    str[index]='\0';
    return strrev(str);
}
int main ()
{
    char exp[100];
    printf("Enter the infix expression : ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = 0;
    printf("prefix form of infix expression is %s is %s\n",exp,infixtoprefix(exp));
    return 0;
}