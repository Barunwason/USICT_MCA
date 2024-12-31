#include<stdio.h>
#include<stdlib.h>

int b = 0;
int choice;
int stack_or_queue;
struct Node{
    int data;
    struct Node* next;
};

struct Node* tos = NULL; 
struct Node* front = NULL; 
struct Node* rear = NULL;  

int select_data_type(){
    printf("\nSelect the type of data structure you want\n");
    printf("1. Stack using Linked List\n");
    printf("2. Queue using Linked List\n");
    printf("Enter your choice: ");
    scanf("%d", &stack_or_queue);
    printf("\n");
    
    return stack_or_queue;
}


int choice_operation(){
    printf("\n");
    if(stack_or_queue == 1){
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Peek (Stack)\n");
        printf("4. Want to change data structure\n");
    } else {
        printf("1. Enqueue (Queue)\n");
        printf("2. Dequeue (Queue)\n");
        printf("3. Traverse (Queue)\n");
        printf("4. Want to change data structure\n");
    }
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}


void push(){
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = tos;
    tos = temp;
    printf("%d is pushed to the stack\n", value);
}

void pop(){
    if(tos == NULL){
        printf("Stack is empty\n");
    } 
    else {
        int popped_value;
        popped_value = tos->data;
        struct Node* temp = tos;
        tos = tos->next;
        free(temp);
        printf("%d is popped from the stack\n", popped_value);
    }
}

void peek(){
    if(tos == NULL){
        printf("Stack is empty\n");
    } 
    else {
        printf("Last element pushed  --> %d\n", tos->data);
    }
}


void enqueue(){
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if(front == NULL){
        front = rear = temp;
    } 
    else {
        rear->next = temp;
        rear = temp;
    }
    printf("%d is enqueued to the queue\n", value);
}

void dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue is empty\n");
    } 
    else if(front == rear){
        int dequeued_value;
        struct Node* temp = front;
        dequeued_value = temp->data;
        free(temp);
        front = rear = NULL;
        printf("%d is dequeued from the queue\n", dequeued_value);
    } 
    else {
        int dequeued_value;
        struct Node* temp = front;
        dequeued_value = temp->data;
        front = front->next;
        free(temp);
        printf("%d is dequeued from the queue\n", dequeued_value);
    }
}

void traverse(){
    if(front == NULL && rear == NULL){
        printf("Queue is empty\n");
    } 
    else {
        struct Node* temp = front;
        printf("Elements in the queue: ");
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main(){
    select_data_type();
    choice_operation();
    
    while(b == 0){
        if(stack_or_queue == 1){ 
            if(choice == 1){
                push();
                choice_operation();
            } 
            else if(choice == 2){
                pop();
                choice_operation();
            } 
            else if(choice == 3){
                peek();
                choice_operation();
            }
            else if(choice == 4){
                select_data_type();
                choice_operation();
            } 
            else {
                printf("You have entered the wrong choice\n");
                choice_operation();
            }
        } 
        else if(stack_or_queue == 2){ 
            if(choice == 1){
                enqueue();
                choice_operation();
            } 
            else if(choice == 2){
                dequeue();
                choice_operation();
            } 
            else if(choice == 3){
                traverse();
                choice_operation();
            } 
            else if(choice == 4){
                select_data_type();
                choice_operation();
            }
            else {
                printf("You have entered the wrong choice\n");
                choice_operation();
            }
        }
    }
    
}
