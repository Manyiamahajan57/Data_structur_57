// This is the second appliaction of the stack : evaluation of the expression
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This is the decleration of stacks
int operands[100], top1 = -1;
char operators[100], top2 = -1;

// This is the function to check the precedence of the operator
int precedence(char opr)
{
    switch (opr)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return 0;
    }
}

// This function is used to repeat the process
void doprocess()
{
    int x = operands[top1--];
    int y = operands[top1--];
    char opr = operators[top2--];
    int z;
    switch (opr)
    {
    case '+':
        z = y + x;
        break;
    case '-':
        z = y - x;
        break;
    case '*':
        z = y * x;
        break;
    case '/':
        z = y / x;
        break;
    case '^':
        z = pow(y, x);
        break;
    }
    operands[++top1] = z;
}

// This is the function to check the postfix expression
int postfix(char *exp)
{
    int size = strlen(exp);
    for (int i = 0; i < size; i++)
    {
        char ch = exp[i];
        if (isdigit(ch))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + exp[i] - '0';
                i++;
            }
            i--;
            operands[++top1] = num;
        }
        else if (ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '^')
        {
            int x = operands[top1--];
            int y = operands[top1--];
            int z;
            switch (ch)
            {
            case '+':
                z = y + x;
                break;
            case '-':
                z = y - x;
                break;
            case '*':
                z = y * x;
                break;
            case '/':
                z = y / x;
                break;
            case '^':
                z = pow(y, x);
                break;
            }
            operands[++top1] = z;
        }
    }
    return operands[top1--];
}

// This is the function to check the prefix expression
int prefix(char *exp)
{
    int size = strlen(exp);
    for (int i = size - 1; i >= 0; i--)
    {
        char ch = exp[i];
        if (isdigit(ch))
        {
            int num = 0, place = 1;
            while (isdigit(exp[i]))
            {
                num = num + (exp[i] - '0') * place;
                i--;
                place = place * 10;
            }
            i++;
            operands[++top1] = num;
        }
        else if (ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '^')
        {
            int x = operands[top1--];
            int y = operands[top1--];
            int z;
            switch (ch)
            {
            case '+':
                z = y + x;
                break;
            case '-':
                z = y - x;
                break;
            case '*':
                z = y * x;
                break;
            case '/':
                z = y / x;
                break;
            case '^':
                z = pow(y, x);
                break;
            }
            operands[++top1] = z;
        }
    }
    return operands[top1--];
}

// This is the function to check the infix expression
int infix(char *exp)
{
    int size = strlen(exp);
    for (int i = 0; i < size; i++)
    {
        char ch = exp[i];
        if (isdigit(ch))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + exp[i] - '0';
                i++;
            }
            i--;
            operands[++top1] = num;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (top2 == -1)
                operators[++top2] = ch;
            else
            {
                while (top2 != -1 && precedence(ch) <= precedence(operators[top2]))
                {
                    doprocess();
                }
                operators[++top2] = ch;
            }
        }
        else if (ch == '(')
        {
            operators[++top2] = ch;
        }
        else if (ch == ')')
        {
            while (operators[top2] != '(')
            {
                doprocess();
            }
            top2--;
        }
    }
    while (top2 != -1)
    {
        doprocess();
    }
    return operands[top1--];
}

// This is the main function
int main()
{
    int result;
    char str[100];

    printf("Enter the postfix expression : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    result = postfix(str);
    printf("The result of the postfix expression :%d\n", result);

    printf("Enter the prefix expression : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    result = prefix(str);
    printf("The result of the prefix expression :%d\n", result);

    printf("Enter the Infix expression : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    result = infix(str);
    printf("The result of the infix expression :%d\n", result);
    return 0;
}