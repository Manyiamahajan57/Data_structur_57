// A single stack is not sufficient to store the large amount of data so we can create a multiple stacks
#include <stdio.h>
#define max 100
int stack[max], top1 = -1, top2 = max;
int isStack1Empty()
{
    return (top1 == -1) ? 1 : 0; // This condition to check that the stack 1 is empty or not
    printf("Stack 1 is Empty !!\n");
}
int isStack2Empty()
{
    return (top2 == max) ? 1 : 0; // This condition to check that the stack 2 is empty or not
    printf("Stack 2 is Empty !!\n");
}
int isStack1Full()
{
    return (top1 == top2 - 1) ? 1 : 0; // This Condition to check that the stack 1 is full or not
    printf("Stack 1 is Full !!\n");
}
int isStack2Full()
{
    return (top2 == top1 + 1) ? 1 : 0; // This condtion is used to check the stack 2 is full or not (It is basically in reverse order)
    printf("Stack 1 is Full !!\n");
}
void push_stack1(int data)
{
    if (isStack1Full())
    {
        printf("Stack 1 Overflow !!\n");
    }
    else
    {
        stack[++top1] = data; // As we know that the in push first we increase the index of the stack then we add the value in the stack
        printf("Element Added !!\n");
    }
}

void push_stack2(int data)
{
    if (isStack2Full())
    {
        printf("Stack 2 Overflow !!\n");
    }
    else
    {
        stack[--top2] = data; // As stack 2 is filled from the last side of the stack so that we can  we do --top2 .
        printf("Element Added !!\n");
    }
}

void pop_stack1()
{
    if (isStack1Empty())
    {
        printf("Stack 1 is Empty !!\n");
    }
    else
    {
        int val = stack[top1--]; // Here we did top1-- because we acess the top of the stack 1 and then remove it .
        printf("%d pop from the stack 1 !!\n", val);
        printf("Element deleted !!\n");
    }
}

void pop_stack2()
{
    if (isStack2Empty())
    {
        printf("Stack 2 is Empty !!\n");
    }
    else
    {
        int val = stack[top2++]; // Here we did top2++ because we acess the top of the stack 2 and then remove it .
        printf("%d pop from the stack 2 !!\n", val);
        printf("Element deleted !!\n");
    }
}

void peek_stack1()
{
    if(isStack1Empty())
    {
        printf("Stack 1 is Empty !!\n");
    }
    else
    {
        stack[top1];
        printf("%d element at the top of the stack 1 !!\n",stack[top2]);
        printf("Element displayed !!\n");
    }
}

void peek_stack2()
{
    if(isStack2Empty())
    {
        printf("Stack 2 is Empty !!\n");
    }
    else
    {
        stack[top2];
        printf("%d element at the top of the stack 2 !!\n",stack[top2]);
        printf("Element displayed !!\n");
    }
}

void display_stack1()
{
    if(isStack1Empty())
    {
        printf("Stack 1 is Empty !!\n");
    }
    else
    {
       int i;
       printf("Stack 1 : ");
       for (int i=top1 ; i>=0 ; i--)
       {
        printf("%d\n",stack[i]);
       }
    }
}

void display_stack2()
{
    if(isStack2Empty())
    {
        printf("Stack 2 is Empty !!\n");
    }
    else
    {
       int i;
       printf("Stack 2 : ");
       for (int i=top2 ; i<max; i++)
       {
        printf("%d\n",stack[i]);
       }
    }
}

int main ()
{
    printf("1.Push Stack 1\n");
    printf("2.Pop Stack 1\n");
    printf("3.Display Stack 1\n");
    printf("4.Push Stack 2\n");
    printf("5.Pop Stack 2\n");
    printf("6.Display Stack 2\n");
    printf("7.Exit\n");
    int choice ;
    printf("enter the choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    }
    return 0;
}