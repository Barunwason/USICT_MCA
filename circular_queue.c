#include<stdio.h>
const int max=50;
int queue[max];
int size;
int b=0;
int choice;
int rear=-1;
int front=-1;
int choice_operation(){
    printf("\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n\n");
    scanf("%d",&choice);
    printf("\n");
    return choice;
}
void enqueue(){
    if(front==(rear+1)%size){
        printf("Queue is full \n");
    }
    else if(front==-1){
        int value;
        printf("Enter the value ");
        scanf("%d",&value);
        printf("\n");
        rear=(rear+1)%size;
        front=(front+1)%size;
        queue[rear]=value;
        printf("front --> %d\n",front);
        printf("rear --> %d\n",rear);
        
    }
    else{
        int value;
        printf("Enter the value ");
        scanf("%d",&value);
        printf("\n");
        rear=(rear+1)%size;
        queue[rear]=value;
        printf("front --> %d\n",front);
        printf("rear --> %d\n",rear);
    }
}
void dequeue(){
    if(front==-1){
         printf("Queue is empty\n");
    }
    else{
        int dequeue_value=queue[front];
        
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%size;
        }
        printf("front --> %d\n",front);
        printf("rear --> %d\n",rear);
        printf("%d is Dequeued\n\n",dequeue_value);
        
        
    }
}
void traverse(){
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