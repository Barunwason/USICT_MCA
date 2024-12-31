#include<stdio.h>
#include<stdlib.h> 
int arr[10];
int length;
int size;
int b = 0;
int choice;
void choose_operation()
{

    printf("\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Want to enter new array \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

}
void merge(int arr[],int low, int high){
    int mid = (low+high)/2;
    int len1=mid-low+1;
    int len2=high-mid;

    int first[len1];
    int second[len2];

    for(int i=0;i<len1;i++){
        first[i]=arr[low+i];
    }
    for(int j=0;j<len2;j++){
        second[j]=arr[mid+1+j];
    }

    int i=0;
    int j=0;
    int k=low;
    while(i<len1 && j<len2){
        if(first[i]<=second[j]){
            arr[k]=first[i];
            i++;
            k++;
        }
        else if(first[i]>second[j]){
            arr[k]=second[j];
            j++;
            k++;
        }
        
    }
    while(i<len1){
        arr[k]=first[i];
        i++;
        k++;
    }
    while(j<len2){
        arr[k]=second[j];
        j++;
        k++;
    }

}
void merge_sort(int arr[],int low, int high){
    int mid = (low+high)/2;
    if(low>=high){
        return;
    }
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);

    merge(arr,low,high);
}
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
void quick_sort(int arr[],int low,int high){
    
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
void get_values(int arr[]){
    printf("How many elements do you want to enter (up to 10)? ");
    scanf("%d", &size);
    length=size;
    for (int i = 0; i < size; i++)
    {
        printf("Enter element at index %d -> ", i);
        scanf("%d", &arr[i]);
    }
}
int main(){
   
    
    get_values(arr);
    traversal(arr,size);
    choose_operation();
    while(b==0){
        if(choice==1){
            merge_sort(arr,0,size-1);
            traversal(arr,size);
            choose_operation();
        }
        else if(choice==2){
            quick_sort(arr,0,size-1);
            traversal(arr,size);
            choose_operation();
        }
        else if(choice==3){
            get_values(arr);
            traversal(arr,size);
            choose_operation();
        }
        else
        {
            printf("Invalid choice!\n");
            choose_operation();
        }
    }
}