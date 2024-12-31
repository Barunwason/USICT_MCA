#include <stdio.h>
#include <stdlib.h>

int stack[10];
int tos=-1;
int size;
int b=0;
int choice;
int choice_operation(){
    printf("\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peep\n\n");
    scanf("%d",&choice);
    printf("\n");
    return choice;
}
void push(){
    if(tos==size-1){
        printf("\nStack is full \n\n");

    }
    else{
        int value;
        printf("Enter the value ");
        scanf("%d",&value);
        printf("\n");
        tos++;
        stack[tos]=value;
        printf("Updated tos --> %d \n",tos);
        printf("Updated! Stack[%d] = %d\n",tos, stack[tos]);
    }
}
void pop(){
    if(tos==-1){
        printf("\nStack is empty\n");
    }
    else{
        printf("%d is popped\n\n",stack[tos]);
        tos--;
    }
}
 
void peak(){
    if(tos==-1){
        printf("\nStack is empty\n");
    }
    else{
        printf("\n Last element pushed --> %d \n",stack[tos]);
    }
    
}
int main(){
    printf("Enter the size of Stack ");
    scanf("%d",&size);
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
            peak();
            choice_operation();
        }
        else{
            printf("You have entered the wrong choice");
            choice_operation();
        }
    }
}