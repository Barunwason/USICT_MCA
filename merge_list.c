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
    printf("Enter the value ");
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
void merge(struct Node* head,struct Node* head1){
    struct Node* temp=head;
    struct Node* temp1=head1;
    
}
int main(){
    head = (struct Node *)malloc(sizeof(struct Node));
    head1 = (struct Node *)malloc(sizeof(struct Node));
    create(head);
    display(head);
    create(head1);
    display(head1);

}