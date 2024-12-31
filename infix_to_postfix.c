#include<stdio.h>
#include<stdbool.h>
const int max=100;
char stack[max];
int tos=-1;
char infix[max];
char postfix[max];
void enter_infix(){
    printf("enter the infix expression -->"); 
    scanf("%s",infix);
}
void push(char value){
    if(tos==max-1){
        printf("\nStack is full \n\n");

    }
    else{
        tos++;
        stack[tos]=value;
    }
}
char pop(){
    int popped;
    if(tos==-1){
        printf("\nStack is empty\n");
        return '\0';
    }
    else{
        popped=stack[tos];
        tos--;
    }
    return popped;
}
char peak(){
    if(tos==-1){
        printf("\nStack is empty\n");
        return '\0';
    }
    else{
        return stack[tos];
    }
    
}
int isoperand(char ch){
    if ((ch>='0' && ch<='9') || (ch>='A' && ch<='Z') || (ch>='a' && ch<='z')) {
        return 1;
    } 
    return 0; 
}
int precedence(char ch) {
    if (ch=='^') {
        return 3;
    } 
    else if (ch=='*' || ch=='/') {
        return 2;
    } 
    else if (ch=='+' || ch=='-') {
        return 1;
    } 
    else {
        return 0;
    }
}

void infix_to_postfix(char* infix,char* postfix){
    int i=0;
    int j=0;
    char ch;
    push('(');
    while (infix[i] != '\0') {
        i++; 
    }
    infix[i] = ')';
    infix[i + 1] = '\0';
    
    i = 0; 
    while(infix[i]!='\0'){
        ch=infix[i];
        if(isoperand(ch)){
            postfix[j++]=ch;
            
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while (tos != -1 && peak() != '(') {
                postfix[j++] = pop();  
            }
            pop(); 
        }
        else{
            if(precedence(ch)>precedence(peak())){
                push(ch);
            }
            else {
            while(tos!=-1 && precedence(ch)<=precedence(peak())){
                    
                    postfix[j++]=pop();
                    
                }
            }    
        }
        i++;
    }
    while (tos != -1 ){
        
        char top = pop();
        if (top != '(') {
            postfix[j++] = top; 
        }
        
        }
    postfix[j]='\0';   
}

int main(){
    enter_infix();
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
}