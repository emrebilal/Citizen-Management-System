
//***Citizen Management System***

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
 
int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();
 
int count = 0;
 
int main()
{
    int id, ch, e;
    
    printf("\n***Citizen Management System***\n");
    printf("1 - Add a person id");
    printf("\n2 - Remove a person id");
    printf("\n3 - Display people id in the system");
    printf("\n4 - The person at the top of the system");
    printf("\n5 - Number of people in the system");
    printf("\n6 - Is system empty ?");
    printf("\n7 - System destroy");
    printf("\n8 - Exit");
 
    create();
 
    while (1)
    {
        printf("\nEnter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter id : ");
            scanf("%d", &id);
            push(id);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            if (top == NULL)
                printf("No people in system");
            else
            {
                e = topelement();
                printf("\nTop person id : %d", e);
            }
            break;
        case 5:
            stack_count();
            break;
        case 6:
            empty();
            break;
        case 7:
            destroy();
            break;
        case 8:
            exit(0);
        default :
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 
/* Create empty stack */
void create()
{
    top = NULL;
}
 
/* Count stack elements */
void stack_count()
{
    printf("\nNumber of people in the system : %d", count);
}
 
/* Push data into stack */
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
 
/* Display stack elements */
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("System is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d\n", top1->info);
        top1 = top1->ptr;
    }
 }
 
/* Pop Operation on stack */
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nError : Trying to pop from empty system");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\nPopped person id : %d", top->info);
    free(top);
    top = top1;
    count--;
}
 
/* Return top element */
int topelement()
{
    return(top->info);
}
 
/* Check if stack is empty or not */
void empty()
{
    if (top == NULL)
        printf("\nSystem is empty");
    else
        printf("\nSystem is not empty with %d people", count);
}
 
/* Destroy entire stack */
void destroy()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("\nAll system persons destroyed");
    count = 0;
}
