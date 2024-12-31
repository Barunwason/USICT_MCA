#include<stdio.h>
#include <stdlib.h>
int choice;
int b=0;
int choice_operation(){
    printf("\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traversal\n\n");
    printf("Enter your choice ");
    scanf("%d",&choice);
    printf("\n");
    return choice;
}
struct Node
{
    int data;
    struct Node* next;
};
struct Node* front=NULL;
struct Node* rear=NULL;
void enqueue() {
    int value;
    printf("enter the value ->");
    scanf("%d", &value);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (front == NULL) {
        front = rear = temp;  
    }
    else {
        rear->next = temp;
        rear = temp;
    }
    printf("%d is enqueued\n",value);
}
void dequeue(){
    if((front==NULL && rear==NULL)){
        printf("Queue is empty");
    }
    else if(front==rear){
        int dequeued_value;
        struct Node *temp;
        temp=front;
        dequeued_value=temp->data;
        free(temp);
        front=NULL;
        rear=NULL;
        printf("%d is dequeued\n",dequeued_value);
    }
    else{
        int dequeued_value;
        struct Node *temp;
        temp=front;
        dequeued_value=temp->data;
        front=front->next;
        free(temp);
        printf("%d is dequeued\n",dequeued_value);
    }
}
void traverse(){
    if((front==NULL && rear==NULL)){
        printf("Queue is empty");
    }
    else{
        struct Node* temp;
        temp=front;
        while(temp!=NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    printf("\n");
    }
}
int main(){
    choice_operation();
    while(b==0){
        
        if(choice==1){
            enqueue();
            choice_operation();
        }
        else if(choice==2){
            dequeue();
            choice_operation();
        }
        else if(choice==3){
            traverse();
            choice_operation();
        }
        else{
            printf("You have entered the wrong choice\n");
            choice_operation();
        }
    }
}