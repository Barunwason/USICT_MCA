#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

int choice;
int b = 1;
int choose_operation()
{

    printf("\n");
    printf("1. traversal\n");
    printf("2. insertion_at_begining\n");
    printf("3. insertion_at_loc\n");
    printf("4. insertion_at_the_end\n");
    printf("5. deletion_at_begining\n");
    printf("6. deletion_at_loc\n");
    printf("7. deletion_at_the_end\n");
    printf("8. count the number of nodes\n");
    printf("9. reverse the linked list\n");
    scanf("%d", &choice);

    return choice;
}
void create(struct Node *node)
{
    int value;
    char choice;
    printf("Enter the value");
    scanf("%d", &value);
    node->data = value;
    printf("Do you want to add more element ? (y/n) :- ");
    getchar();
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        node->next = (struct Node *)malloc(sizeof(struct Node));
        create(node->next);
    }
    else
    {
        node->next = NULL;
    }
}
void display(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}
void insertion_at_begining()
{
    int value;
    printf("enter the value");
    scanf("%d", &value);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = head;
    head = temp;
}
void insertion_at_loc(int loc)
{

    int value;
    printf("enter the value ->");
    scanf("%d", &value);
    struct Node *temp;
    temp = head;
    while (temp->data != loc)
    {
        temp = temp->next;
    }
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->next = temp->next;
    temp->next = node;
}
void insertion_at_the_end()
{
    if (head == NULL)
    {
        insertion_at_begining();
        return;
    }
    int value;
    printf("enter the value ->");
    scanf("%d", &value);
    struct Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    temp->next = node;
}
void deletion_at_begining()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp;
    temp = head;
    head = head->next;
    free(temp);
}
void deletion_at_loc(int loc)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if (head->data == loc)
    {
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            deletion_at_begining();
        }
        return;
    }
    struct Node *temp0;
    struct Node *temp;
    temp = head;
    temp0 = head;
    while (temp->data != loc)
    {
        temp0 = temp;
        temp = temp->next;
    }
    temp0->next = temp->next;
    free(temp);
}
void deletion_at_the_end()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp0;
    struct Node *temp;
    temp = head;
    temp0 = head;
    while (temp->next != NULL)
    {
        temp0 = temp;
        temp = temp->next;
    }
    temp0->next = NULL;
    free(temp);
}
void count_the_nodes()
{
    int count = 0;
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes are --> %d", count);
}
void reverse()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
bool is_element_in_list(int value)
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    create(head);
    display(head);
    choose_operation();
    while (b == 1)
    {
        if (choice == 1)
        {
            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
                display(head);
            choose_operation();
        }
        else if (choice == 2)
        {
            insertion_at_begining();
            printf("Here is the updated list -->");
            display(head);
            choose_operation();
        }
        else if (choice == 3)
        {
            int loc;
            printf("Enter the element after which you want to insert a new element  ");
            scanf("%d", &loc);
            if (is_element_in_list(loc))
            {
                if (head == NULL)
                {
                    printf("List is empty\n");
                }
                else
                {
                    insertion_at_loc(loc);
                    printf("Here is the updated list -->");
                    display(head);
                }
            }
            else
            {
                printf("Element is not in the list\n");
            }

            choose_operation();
        }
        else if (choice == 4)
        {
            insertion_at_the_end();
            printf("Here is the updated list -->");
            display(head);
            choose_operation();
        }
        else if (choice == 5)
        {

            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                deletion_at_begining();
                if (head == NULL)
                {
                    printf("List is empty\n");
                }
                else
                {
                    printf("Here is the updated list -->");
                    display(head);
                }
            }
            choose_operation();
        }
        else if (choice == 6)
        {
            int loc;

            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                printf("Enter the element you want to delete  ");
                scanf("%d", &loc);
                if (is_element_in_list(loc))
                {
                    deletion_at_loc(loc);
                    if (head == NULL)
                    {
                        printf("List is empty\n");
                    }
                    else
                    {
                        printf("Here is the updated list -->");
                        display(head);
                    }
                }
                else
                {
                    printf("Element is not in the list\n");
                }
            }
            choose_operation();
        }
        else if (choice == 7)
        {

            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                deletion_at_the_end();
                if (head == NULL)
                {
                    printf("List is empty\n");
                }
                else
                    printf("Here is the updated list -->");
                display(head);
            }
            choose_operation();
        }
        else if (choice == 8)
        {
            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
                count_the_nodes();
            choose_operation();
        }
        else if (choice == 9)
        {
            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                reverse();
                display(head);
            }

            choose_operation();
        }
        else
        {
            printf("You entered the wrong choice");
            choose_operation();
        }
    }
}