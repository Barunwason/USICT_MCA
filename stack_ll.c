#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* tos=NULL;
int b=0;
int choice;
int choice_operation(){
    printf("\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peep\n\n");
    printf("Enter your choice ");
    scanf("%d",&choice);
    printf("\n");
    return choice;
}
void push(){
    int value;
    printf("enter the value");
    scanf("%d", &value);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next=tos;
    tos=temp;
    printf("%d is pushed to the stack\n", value);
}
void pop(){
    if(tos==NULL){
        printf("Stack is empty\n");
    }
    else{
        int popped_value;
        popped_value=tos->data;
        struct Node *temp;
        temp=tos;
        tos=tos->next;
        free(temp);
        printf("%d is popped from the stack\n\n",popped_value);
    }
}
void peek(){
    if(tos==NULL){
        printf("\nStack is empty\n");
    }
    else{
        printf("\n Last element pushed --> %d \n",tos->data);
    }
}
int main(){
    choice_operation();
    while(b==0){
        
        if(choice==1){
            push();
            choice_operation();
        }
        else if(choice==2){
            pop();
            choice_operation();
        }
        else if(choice==3){
            peek();
            choice_operation();
        }
        else{
            printf("You have entered the wrong choice");
            choice_operation();
        }
    }
}