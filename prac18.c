#include<stdio.h>
int b=0;
char choice;
char choice_operation(){
    printf("Do you want to enter other strings ? (y/n) ");
    getchar();
    scanf("%c",&choice);
    printf("\n");
    return choice;
}
const int size =100;
char s1[size];
char s2[size];

int max(int a,int b){
    if(a<b){
        return b;
    }
    else 
    return a;
}
int solve(char *s1,char *s2 ,int i, int j){
    if(s1[i]=='\0' || s2[j]=='\0'){
        return 0;
    }
    int ans=0;
    if(s1[i]==s2[j]){
        ans=1+solve(s1,s2,i+1,j+1);
    }
    else{
        ans=max(solve(s1,s2,i,j+1),solve(s1,s2,i+1,j));
    }
    return ans;
}
void enter_s1(){
    printf("enter the first string --> ");
    scanf("%s",s1);
}
void enter_s2(){
    printf("enter the second string --> ");
    scanf("%s",s2);
}
int main(){
    enter_s1();
    enter_s2();
    printf("The longest subsquence is of size %d \n",solve(s1,s2,0,0));
    choice_operation();
    while(b==0){
        if (choice == 'y' || choice == 'Y'){
            enter_s1();
            enter_s2();
            printf("The longest subsquence is of size %d \n",solve(s1,s2,0,0));
            choice_operation();
        }
    }
}
