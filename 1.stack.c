// Stacks is a linear data structure which work on the principle of LIFO and FILO. There are many operation which is going to used in stacks.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // that contain all the range of the basic data type
#include <math.h>
#define max 100
// global function
int stack[max], top = -1; // top is used to store the index of the first topmost element of the stack

// this function is used to check that the stack is full or empty
int isEmpty()
{
    return (top == -1) ? 1 : 0; // if top == -1 that means the stack is empty because there is no -ve index in an array
}
int isFull()
{
    return (top == max - 1) ? 1 : 0; // if top == max-1 (-1 because we know array index 1-99) means that the stack is full
}
void push()
{
    if (isFull()) // to check that the stack is full or not
    {
        printf("stack overflow\n");
    }
    else
    {
        int value;
        printf("enter Element : ");
        scanf("%d", &value);
        top++;              // top = top + 1 is used to increase the index ;
        stack[top] = value; // assigning the value of that index
        printf("Element Added Sucessfully! \n");
    }
}
void show()
{
    if (isEmpty()) // to check that the stack is empty or not
    {
        printf("stack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);  // return the output of the stack .
        }
    }
}
int pop()
{
    if (isEmpty())
    {
        printf("Stack is empty !!\n"); // this is used to check the stack is empty or not
        return INT_MIN;
    }
    else
    {
        int value = stack[top]; // this value variable is used to store the stack top most element
        top--;                  // decreament in the stack because remove the value
        printf("element pop sucessfully !!\n");
        return value;
    }
}
int peek()  // peak function is used to return the top most element of the stack
{
    if (isEmpty())
    {
        printf("stack is Empty\n"); 
        return INT_MIN; // this is used to return the min value of the integer .
    }
    else
    {
        return stack[top];   // return the top most element of the stack 
    }
}
int main()
{
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Seek\n");
        printf("4.Show\n");
        printf("5.Exit\n");
        int choice, val;
        printf("enter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            val = pop();
            if (val != INT_MIN)
            {
                printf("%d from the stack\n", val);
            }
            break;
        case 3:
            val=peek();
            if(val!=INT_MIN)
            {
                printf("%d top most element of the stack\n",val);
            }
            break;
        case 4:
            show();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid operations!!");
        }
        printf("\n\n");
        system("Pause");
    }
    return 0;
}