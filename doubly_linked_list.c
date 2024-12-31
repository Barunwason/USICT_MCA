#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int b = 0;
int choice;
int choice_operation()
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
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head;

void create(struct Node *node)
{
    int value;
    char choice;
    printf("Enter the value ");
    scanf("%d", &value);
    node->data = value;
    printf("Do you want to add more element ? (y/n) :- ");
    getchar();
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        node->next = (struct Node *)malloc(sizeof(struct Node));
        node->next->prev = node;
        create(node->next);
    }
    else
    {
        node->next = NULL;
    }
}
void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reverse_display()
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp->prev != NULL)
    {
        printf("%d", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
    printf("\n");
}
void insertion_at_begining()
{
    int value;
    printf("Enter the number ");
    scanf("%d", &value);
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        temp->data = value;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        temp->data = value;
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;
    }
}
void insertion_at_loc(int loc)
{
    int value;
    printf("Enter the number ");
    scanf("%d", &value);
    struct Node *temp;
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    temp = head;
    while (temp->data != loc)
    {
        temp = temp->next;
    }
    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next->prev = ptr;
    temp->next = ptr;
}
void insertion_at_the_end()
{
    int value;
    printf("Enter the number ");
    scanf("%d", &value);
    struct Node *temp;
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->prev = temp;
    ptr->next = NULL;
}
void deletion_at_begining()
{
    struct Node *temp;
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void deletion_at_the_end()
{
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}
void deletion_at_loc(int loc)
{
    struct Node *temp;
    temp = head;
    if (head->data == loc)
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
    else
    {
        while (temp->data != loc)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            deletion_at_the_end();
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
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
    prev = NULL;
    while (current != NULL)
    {
        prev = current->prev;
        current->prev = next;
        next = current;
        current = prev;
    }
}
bool is_element_in_list(int value)
{
    struct Node *temp = head;
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
int main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->prev = NULL;
    create(head);
    display();
    choice_operation();
    while (b == 0)
    {
        if (choice == 1)
        {
            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                display();
            }
            choice_operation();
        }
        else if (choice == 2)
        {
            insertion_at_begining();
            printf("Here is the updated list -->");
            display();
            choice_operation();
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
                    display();
                }
            }
            else
            {
                printf("Element is not in the list\n");
            }
            display();
            choice_operation();
        }
        else if (choice == 4)
        {
            if (head == NULL)
            {
                insertion_at_begining();
                printf("Here is the updated list -->");
                display();
            }
            else
            {
                insertion_at_the_end();
                printf("Here is the updated list -->");
                display();
            }
            choice_operation();
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
                    display();
                }
            }
            choice_operation();
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
                        display();
                    }
                }
                else
                {
                    printf("Element is not in the list\n");
                }
            }
            choice_operation();
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
                display();
            }
            choice_operation();
        }
        else if (choice == 8)
        {
            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
                count_the_nodes();
            choice_operation();
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
                display();
            }

            choice_operation();
        }
        else
        {
            printf("You entered the wrong choice");
            choice_operation();
        }
    }
}
