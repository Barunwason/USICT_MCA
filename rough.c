#include<stdio.h>
struct queue{
    struct Node* node;
    struct queue* next;
};
struct queue* front=NULL;
struct queue* rear=NULL;

void enqueue(struct Node* node){
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    temp->node = node;
    temp->next = NULL;

    if (front == NULL) {
        front = rear = temp;  
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

struct Node* dequeue(){
    if((front==NULL && rear==NULL)){
        return NULL;
    }
    else if(front==rear){
        struct Node* dequeued_node;
        struct queue *temp;
        temp=front;
        dequeued_node=temp->node;
        free(temp);
        front=NULL;
        rear=NULL;
        return dequeued_node;
    }
    else{
        int dequeued_node;
        struct queue *temp;
        temp=front;
        dequeued_node=temp->node;
        front=front->next;
        free(temp);
        return dequeued_node;
    }
}
void levelordertraversal(struct Node* node){
    if(node==NULL){
        return;
    }
    struct Node* ptr=node;
        enqueue(node);
        enqueue(NULL);
    while(front!=NULL){
        ptr=dequeue();
        printf("%d ", ptr->data);
        if(ptr->left!=NULL){
            enqueue(ptr->left);
        }
        if(ptr->right!=NULL){
            enqueue(ptr->right);
        }
    }

        
}
int main(){
 int a=__INT_MAX__;
 int b=12;
 int c = (b%a);
 printf("%d",c);
}