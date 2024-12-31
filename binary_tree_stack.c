#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int b=0;
int choice;
const int size=50;
struct Node* stack[size];
int tos=-1;
void push(struct Node* value){
    if(tos==size-1){
        return;

    }
    else{
        tos++;
        stack[tos]=value;
    }
}
struct Node* pop(){
    if(tos==-1){
        printf("\nStack is empty\n");
        return NULL;
    }
    else{
        struct Node* pop_value = stack[tos];
        tos--;
        return pop_value;
    }
}


int choice_operation(){
    printf("\n");
    printf("1. Preorder Traversal \n");
    printf("2. Inorder Traversal \n");
    printf("3. Postorder Traversal \n");
    printf("4. Insertion \n");
    printf("5. Search \n");
    printf("6. Deletion \n");
    printf("Enter your choice ");
    scanf("%d",&choice);
    printf("\n");
    return choice;
}
struct Node{
    struct Node*left;
    int data;
    struct Node* right;
};
struct Node *root=NULL;

struct Node* give_value(struct Node* node , int value){
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}
struct Node* insert(struct Node* node, int value) {
    if (node == NULL) 
    {
        return give_value(node,value);
    }
    if (value < node->data) 
    {
        node->left = insert(node->left, value);
    } 
    else if (value > node->data) 
    {
        node->right = insert(node->right, value);
    }
    return node;
}

void create(){
    int value;
    char choice;
    printf("Enter the value ");
    scanf("%d",&value);
    root = insert(root, value);
    printf("Do you want to add more element ? (y/n) :- ");
    getchar();
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        create();
    }
    else
    {
        return;
    }
}
void preorder(struct Node* node){

    if (node == NULL) {
        return;
    }
    struct Node* ptr=node;
    while(ptr!=NULL || tos!=-1){
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            if(ptr->right!=NULL){
                push(ptr->right);
            }
            ptr=ptr->left;
        }
        if(tos!=-1){
        ptr=pop();
        }
    }
     
}
void inorder(struct Node* node){
    if(node==NULL){
        return;
    }
    struct Node* ptr=node;
    struct Node* temp;
    while(ptr!=NULL || tos!=-1){
        while(ptr!=NULL){
            push(ptr);
            ptr=ptr->left;
        }
            temp=pop();
            printf("%d ",temp->data);
            if(temp->right!=NULL){
                ptr=temp->right;
            }
        
    }
}
void postorder(struct Node* node){
    if (node == NULL) {
        return;
    }
    struct Node* ptr=node;
    struct Node* temp;
    struct Node* lastvisited=NULL;
    while(ptr!=NULL || tos!=-1){
        while(ptr!=NULL){
            push(ptr);
            ptr=ptr->left;
        }
        temp=pop();
        if(temp->right==NULL || temp->right==lastvisited){
            printf("%d ",temp->data);
            lastvisited=temp;
        }
        else{
            ptr=temp->right;
            push(temp);
        }
       
        
    }
}
bool search(struct Node* node , int value){
    if(node!=NULL){
        if(node->data==value){
            return true;
        }
        else if(value < node->data){
            return search(node->left,value);
        }
        else{
            return search(node->right,value);
        }   
    }
    else{
        return false;
    }
}
struct Node* minimum(struct Node* node){
    while(node!=NULL && node->left!=NULL){
        node=node->left;
    }
    return node;
}
struct Node* deletion(struct Node* node,int value){
    
        
        if(value<node->data){
            node->left=deletion(node->left,value);
        }
        else if(value>node->data){
            node->right=deletion(node->right,value);
        }
        else{
            struct Node* temp;
            if(node->left==NULL&&node->right==NULL){//jab koi subtree na ho
                free(node);
                return NULL;
            } 
            if(node->left==NULL){ //jab sirf right subtree ho
                temp=node->right;
                free(node);
                return temp;
            }
            else if(node->right==NULL){ //jab sirf left subtree ho
                temp=node->left;
                free(node);
                return temp;
            }
            else{ //jab dono subtree ho 
                temp = minimum(node->right);
                node->data=temp->data;
                node->right = deletion(node->right,temp->data);
            }
        }
    
    return node;
}
int main(){
   create();
   choice_operation();
   while(b==0){
    if(choice==1){
            printf("preorder --> ");
            preorder(root);
            printf("\n");
            choice_operation();
        }
        else if(choice==2){
            printf("inorder --> ");
            inorder(root);
            printf("\n");
            choice_operation();
        }
        else if(choice==3){
            printf("postorder --> ");
            postorder(root);
            printf("\n");
            choice_operation();
        }
        else if(choice==4){
            int value;
            printf("Enter the value ");
            scanf("%d",&value);
            insert(root,value);
            printf("\n");
            choice_operation();
        }
        else if(choice==5){
            int value;
            printf("Enter the value ");
            scanf("%d",&value);
            if (search(root,value)){
                printf("%d is in the tree \n", value);
            }
            else{
                printf("Element is not in the tree \n");
            }
            choice_operation();
        }
        else if(choice==6){
            int value;
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            if(!search(root,value)){
                printf("Element is not in the tree\n");
            }
            else{
                root = deletion(root, value); 
                printf("%d is deleted from the tree.\n", value);
            }
            
            choice_operation();
        }
        else{
            printf("You have entered the wrong choice\n");
            choice_operation();
        }
   }
   
}