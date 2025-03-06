#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int operand[100],top=-1;
int prefix(char *exp){
    int size = strlen(exp);
    for (int i=size-1 ; i>=0 ; i--){
        char ch = exp[i];
        if(isdigit(ch)){
            int num=0, place=1;
            while(isdigit(exp[i])){
                num = num  + (exp[i]-'0') * place ;
                i--;
                place = place * 10;
            }
            i++;
            operand[++top]=num;
        }
        else if ( ch == '+' || ch == '-' || ch == '*' || ch=='/' || ch=='^'){
            int z;
            int x = operand[top--];
            int y = operand[top--];
            switch(ch){
                case '+' : z=y+x ; break;
                case '-' : z=y-x ; break;
                case '*' : z=y*x ; break;
                case '/' : z=y/x ; break;
                case '^' : z=pow(y,x) ; break;
             }
            operand[++top]=z;
        }
    }
    return operand[top--];
}
int main ()
{
    int result ;
    char str[100];
    printf("Enter the prefix expression : ");
    gets(str);
    result = prefix(str);
    printf("The result of the expression is : %d",result);
    return 0;
}