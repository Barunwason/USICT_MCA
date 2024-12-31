#include<stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int pivot;
    pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(pivot>=arr[i] && i<high){
            i++;
        }
        while(pivot<=arr[j] && j>low){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }}
        swap(&arr[low],&arr[j]);
        return j;
        
    }
int quick_sort(int arr[],int low,int high){
    
    int partition_index ;
    if(low<high)
    {
        partition_index=partition(arr,low,high);
        quick_sort(arr,low,partition_index-1);
        quick_sort(arr,partition_index+1,high);
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
    int arr[]={4,6,2,5,7,9,1,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,size-1);
    traversal(arr,size);
}