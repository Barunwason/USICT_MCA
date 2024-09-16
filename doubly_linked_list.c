#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head;
void create(struct Node *node){
    int value;
    char choice;
    printf("ENter the value");
    scanf("%d",&value);
    node->data = value;
    printf("Do you want to add more element ? (y/n) :- ");
    getchar();
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y'){
        
    }
}
int main(){

}
