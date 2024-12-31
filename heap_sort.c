#include<stdio.h>
const int size=10;
int length=5;
int arr[size]={54,53,55,52,56};
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int heapify(int arr[],int i,int size)
{
    int left = (2*i)+1;
    int right = (2*i)+2;
    int largest = i;

    if(left<size && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<size && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        //heapify(arr,largest,size);
    }
}
int heap_sort(int arr[],int size){
    
    for(int i=size/2-1;i>=0;i--){
        heapify(arr,i,size);
    }
    for(int i=size-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,0,i);
    }
}
int getvalue(int arr[],int size){
    
    printf("how many element you want to enter (less than 10) ");
    scanf("%d",&length);
    for(int i=0; i<length; i++){
        printf("Enter the value at index %d ",i);
        scanf("%d",&arr[i]);
    }
}
void traversal(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    //getvalue(arr,size);
    
    heap_sort(arr,length);
    traversal(arr,length);
}