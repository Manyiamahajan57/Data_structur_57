// this code is the conversion of the postfix into the infix expression 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
char* postfixtoinfix(char *exp)
{
    int size = strlen(exp),top=-1;
    // Here we use 2d array because we have to store the expression in the stack so we required multiple expression in the stack
    char stack[size][100];
    for (int i=0 ; i<size ; i++)
    {
        char ch = exp[i];
        if (isalnum(ch))
        {
            char temp[]={ch,'\0'};     // This is used to store the character string in the temp 
            strcpy(stack[++top],temp);  // Thus is used to add the temp stack in the stack top
        }
        else if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        {
            char *s1 = stack[top--];      // This is used to take the top value from the stack
            char *s2 = stack[top--];      // This is used to take the another top value from the stack this is taken as pointer in the reference 
            char temp[100];             
            snprintf(temp,100,"(%s%c%s)",s2,ch,s1);      // This is a format specifier 
            strcpy(stack[++top],temp);     
        }
    }
    char *s = (char*)malloc(strlen(stack[top])+1);  
    strcpy(s,stack[top]); 
    return s ;
}
int main ()
{
    char str[100];
    printf("Enter the postfix expression : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    printf("Conversion of the postfix expression into the infix expression %s : %s ",str,postfixtoinfix(str));
    return 0;
}
// this code is the conversion of the prefix into the infix expression 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
char* prefixtoinfix(char *exp)
{
    int size = strlen(exp),top=-1;
    char stack[size][100];
    for (int i=size-1 ; i>=0 ; i--)
    {
        char ch = exp[i];
        if (isalnum(ch))
        {
            char temp[]={ch,'\0'};
            strcpy(stack[++top],temp);
        }
        else if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        {
            char *s1 = stack[top--];    
            char *s2 = stack[top--];   
            char temp[100];            
            snprintf(temp,100,"(%s%c%s)",s1,ch,s2);       
            strcpy(stack[++top],temp);     
        }
    }
    char *s = stack[top];
    return s ;
}
int main ()
{
    char str[100];
    printf("Enter the postfix expression : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    printf("Conversion of the prefix expression into the infix expression %s : %s ",str,prefixtoinfix(str));
    return 0;
}