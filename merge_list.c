#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
struct Node* head1;

void create(struct Node *node)
{
    int value;
    char choice;
    printf("Enter the value: ");
    scanf("%d", &value);
    node->data = value;
    printf("Do you want to add more elements? (y/n): ");
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
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void merge(struct Node* head, struct Node* head1)
{
    while (head != NULL || head1 != NULL)
    {
        if (head != NULL && head1 != NULL)
        {
            if (head->data < head1->data)
            {
                printf("%d ", head->data);
                head = head->next;
            }
            else if (head->data > head1->data)
            {
                printf("%d ", head1->data);
                head1 = head1->next;
            }
            else
            {
                printf("%d %d ", head->data, head1->data);
                head = head->next;
                head1 = head1->next;
            }
        }
        else if (head1 == NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        else if (head == NULL)
        {
            printf("%d ", head1->data);
            head1 = head1->next;
        }
    }
}

int main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head1 = (struct Node *)malloc(sizeof(struct Node));

    printf("Insert the values for the first list:\n");
    create(head);
    printf("First linked list: ");
    display(head);

    printf("\nInsert the values for the second list:\n");
    create(head1);
    printf("Second linked list: ");
    display(head1);

    printf("\nMerged list: ");
    merge(head, head1);

    return 0;
}
