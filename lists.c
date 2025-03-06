// we are going to use the operation in the static list
#include <stdio.h>
#include <stdlib.h>
// #sefine is used to set the maximum value or we can say that it is constant 
#define max_size 100
// insertion of element in a list 
void insert(int *list, int *size)
{
    int pos,value;
    printf("enter the position : ");
    scanf("%d", &pos);
    printf("enter the value : ");
    scanf("%d", &value);
    pos--;
    if (pos < 0 || pos > *size)
    {
        printf("Invalid position\n");
    }
    else if (pos == *size)                 // this is also a push operation 
    {
        list[pos] = value;                 // as these is are in position but for index acess we have to do [pos-1];
        printf("element enter successfully\n");
        *size = *size + 1;                 // we can write in (*size)++ ;
    }
    else
    {
        for (int i = *size; i >= pos; i--) // right shifting is done here
        {
            list[i] = list[i - 1];
        }
        list[pos] = value;                 // the value that is given to insert at that position .
        printf("element enter successfully\n");
        *size = *size + 1; 
    }
}
// transversing of a list 
void displaylist(int *list, int size)    
{
    printf("element of the list are : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",list[i]);
    }
}
//deletion of element in a list
void deletion (int *list , int *size)
{
    int pos ;
    printf("enter the position : ");
    scanf("%d",&pos);
    pos--;   // pos-- is used for the index
    if (pos<0 || pos>=*size)
    {
        printf("Invalid operation !!\n"); 
    }
    else if (pos==*size)
    {
        (*size)--;
        printf("Element deleted !!\n");
    }
    else
    {
        for (int i=pos ; i<*size-1 ; i++)
        {
         if (pos<=i)
         {
            list[i]=list[i+1];         // left shifting
         }
        }
       *size = *size - 1;
        printf("Element deleted !!");
    }
}
// serach an element in a list
void searching(int *list , int size)
{
    int target , flag=0 , i;
    printf("enter the target : ");
    scanf("%d",&target);
    for ( i=0 ; i<size ; i++)
    {
       if(list[i]==target)
       {
        flag=1;
        break;
       }
    }
    if (flag==1)
    {
        printf("element found at index %d\n",i);
    }
    else
    {
        printf("element does not found !!\n");
    }
}

int main()
{
    int list[max_size],size,i;            // max size is used to define the max element in the list
    printf("enter the size of array : "); // size is used to define the how much element we want to add in the list
    scanf("%d", &size);
    printf("enter the array element : ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &list[i]);
    }
    while (1)                           // while is used to run the loof infinte time untill we press exit option
    {
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Searching\n");
        printf("4.Traversing\n");
        printf("5.Exit\n");
        int choice;
        printf("enter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(list, &size);    // basically address is given because if there is a change in the size of array
            break;
        case 2:
            deletion(list,&size);
            break;
        case 3:
            searching(list ,size);   // basically address is not given because if there is not a chnage in the size of array
            break;
        case 4:
            displaylist(list,size);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid operation\n");
        }
        system("pause");
     } // this function is used to hold the screen for sometime
    return 0;
    }
