#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void insertion_sort(int arr[],int size){
    int temp;
for(int i=1;i<size;i++){
    for(int j=i;j>=0;j--){
        if(arr[i]<arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
}

}
void traversal(int arr[], int size){
    if (size == 0)
    {
        printf("Array is empty");
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={2,1,4,3,5,8,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,size);
    traversal(arr,size);
}