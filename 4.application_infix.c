#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int top1 = -1, top2 = -1;
int operand[100];
int operator[100];

int precedence(char opr)
{
    switch (opr)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void doProcess()
{
    int x = operand[top1--];
    int y = operand[top1--];
    int z;
    char opr = operator[top2--];
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
    operand[++top1] = z;
}

int evalInfixExpression(char *exp)
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
            operand[++top1] = num;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (top2 == -1)
                operator[++top2] = ch;
            else
            {
                while (top2 != -1 && precedence(ch) <= precedence(operator[top2]))
                {
                    doProcess();
                }
                operator[++top2] = ch;
            }
        }

        else if (ch == '(')
        {
            operator[++top2] = '(';
        }
        else if (ch == ')')
        {
            while (operator[top2] != '(')
            {
                doProcess();
            }
            top2--;
        }
    }
    while (top2 != -1)
    {
        doProcess();
    }
    return operand[top1--];
}

int main()
{
    char str[100];
    printf("Enter Infix expression: ");
    gets(str);
    int result = evalInfixExpression(str);
    printf("Result = %d\n", result);
    return 0;
}