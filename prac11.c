#include<stdio.h>
#include<stdlib.h>

const int max = 50;
int queue[max];
int size;
int b = 0;
int choice, queue_type_choice;
int rear = -1;
int front = -1;


struct Node {
    int data;
    struct Node* next;
};
struct Node* front_ll = NULL;
struct Node* rear_ll = NULL;


int select_queue_type() {
    printf("\nSelect the type of Circular Queue you want to create:\n");
    printf("1. Circular Queue using Array\n");
    printf("2. Circular Queue using Linked List\n");
    printf("Enter your choice: ");
    scanf("%d", &queue_type_choice);
    printf("\n");
    return queue_type_choice;
}


int choice_operation() {
    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n");
    printf("4. Want to change queue type\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}


void enqueue_array() {
    if (front == (rear + 1) % size) {
        printf("Queue is full \n");
    } 
    else if (front == -1) {
        int value;
        printf("Enter the value: ");
        scanf("%d", &value);
        printf("\n");
        rear = (rear + 1) % size;
        front = (front + 1) % size;
        queue[rear] = value;
        printf("%d is enqueued (Array)\n", value);
    } 
    else {
        int value;
        printf("Enter the value: ");
        scanf("%d", &value);
        printf("\n");
        rear = (rear + 1) % size;
        queue[rear] = value;
        printf("%d is enqueued (Array)\n", value);
    }
}

void dequeue_array() {
    if (front == -1) {
        printf("Queue is empty\n");
    } 
    else {
        int dequeue_value = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } 
        else {
            front = (front + 1) % size;
        }
        printf("%d is dequeued (Array)\n\n", dequeue_value);
    }
}

void traverse_array(){
    if(front==-1){
         printf("Queue is empty\n");
    }
    else{
        int i=front;
        while(i!=rear){
            printf("%d \n", queue[i]);
            i=(i+1)%size;
        }
        printf("%d \n", queue[i]);
    }
}


void enqueue_ll() {
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (front_ll == NULL) {
        front_ll = rear_ll = temp;
        rear_ll->next = front_ll;
    } 
    else {
        rear_ll->next = temp;
        rear_ll = temp;
        rear_ll->next = front_ll;
    }
    printf("%d is enqueued (Linked List)\n", value);
}

void dequeue_ll() {
    if (front_ll == NULL && rear_ll == NULL) {
        printf("Queue is empty\n");
    } 
    else if (front_ll == rear_ll) {
        int dequeued_value;
        struct Node *temp;
        temp = front_ll;
        dequeued_value = temp->data;
        free(temp);
        front_ll = rear_ll = NULL;
        printf("%d is dequeued (Linked List)\n", dequeued_value);
    } 
    else {
        int dequeued_value;
        struct Node *temp;
        temp = front_ll;
        dequeued_value = temp->data;
        front_ll = front_ll->next;
        rear_ll->next = front_ll;
        free(temp);
        printf("%d is dequeued (Linked List)\n", dequeued_value);
    }
}

void traverse_ll() {
    if (front_ll == NULL && rear_ll == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = front_ll;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } 
        while (temp != front_ll);
        printf("\n");
    }
}


int main() {
    select_queue_type();

    if (queue_type_choice == 1) {
        printf("Enter the size of Queue (Array): ");
        scanf("%d", &size);
    }

    choice_operation();
    while (b == 0) {
        if (choice == 1) {
            if (queue_type_choice == 1) {
                enqueue_array();
            } else {
                enqueue_ll();
            }
        } 
        else if (choice == 2) {
            if (queue_type_choice == 1) {
                dequeue_array();
            } else {
                dequeue_ll();
            }
        } 
        else if (choice == 3) {
            if (queue_type_choice == 1) {
                traverse_array();
            } else {
                traverse_ll();
            }
        } 
        else if(choice == 4){
            select_queue_type();
        }
        else {
            printf("You have entered the wrong choice\n");
        }
        choice_operation();
    }

    return 0;
}
