#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int operand[100],top=-1;
int postfix(char *exp){
    int size = strlen(exp);
    for (int i=0 ; i<size ; i++){
        char ch = exp[i];
        if(isdigit(ch)){
            int num = 0;
            while(isdigit(exp[i])){
                num = num * 10 + exp[i] - '0';
                i++;
            }
            i--;
            operand[++top]=num;
        }
        else if (ch =='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            int x = operand[top--];
            int y = operand[top--];
            int z ;
            switch(ch){
                case '+' :  z=y+x;       break;
                case '-' :  z=y-x;       break;
                case '*' :  z=y*x;       break;
                case '/' :  z=y/x;       break;
                case '^' :  z=pow(y,x);  break;
            }
            operand[++top]=z;
        }
    }
    return operand[top--];
}
int main (){
    int result;
    char str[100];
    printf("Enter Postfix expression : ");
    gets(str);
    result = postfix(str);
    printf("The Result of the Expression is : %d\n",result);
    return 0;
}