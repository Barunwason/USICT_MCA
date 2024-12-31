#include<stdio.h>
#include<stdlib.h>

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
int main(){
     int arr[5]={12,64,22,57,2};
     merge_sort(arr,0,4);
     for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
     }
}