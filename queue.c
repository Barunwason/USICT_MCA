#include<stdio.h>
const int max=50;
int queue[max];
int b=0;
int size;
int rear=-1;
int front=-1;
int choice;
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
void enqueue(){
    if(rear==size-1){
        printf("Queue is full \n");
        
    }
    else if(front==-1){
        int value;
        printf("Enter the value ");
        scanf("%d",&value);
        printf("\n");
        rear=rear+1;
        front=front+1;
        queue[rear]=value;
        printf("front --> %d\n",front);
        printf("rear --> %d\n",rear);
        
    }
    else{
        int value;
        
        printf("Enter the value ");
        scanf("%d",&value);
        printf("\n");
        rear=rear+1;
        queue[rear]=value;
        printf("front --> %d\n",front);
        printf("rear --> %d\n",rear);
    }
    
}
void dequeue(){
    if(front==-1 || front>rear){
        printf("Queue is empty\n");
        
    }
    else{
        int dequeue_value=queue[front];
        front++;
        if(front>rear){
            front=rear=-1;
        }
        printf("front --> %d\n",front);
        printf("rear --> %d\n",rear);
        printf("%d is Dequeued\n\n",dequeue_value);
    }
}
void traverse(){
    if(front==-1 || front>rear){
        printf("Queue is empty\n");
        
    }
    else{
        for(int i=front;i<rear+1;i++){
            printf("%d - ",queue[i]);
        }
    }
}
int main(){
    printf("Enter the size of Queue ");
    scanf("%d",&size);
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