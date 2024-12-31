#include<stdio.h>
#include<stdbool.h>
int arr[10];
int length;
int size;
int b = 1;
int choice;
int insert_choice;
int delete_choice;
int search_choice;
void choose_operation()
{

    printf("\n");
    printf("1. Traversal\n");
    printf("2. Insertion\n");
    printf("3. Deletion\n");
    printf("4. Searching\n");
    printf("5. Sorting\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

}
void insertion_choice(){
    printf("\n");
    printf("What insertion operation you want to perform\n");
    printf("1. Insertion_at_begining\n");
    printf("2. Insertion_at_loc\n");
    printf("3. Insertion_at_the_end\n");
    printf("Enter your choice: ");
    scanf("%d", &insert_choice);
}

void deletion_choice(){
    printf("\n");
    printf("What deletion operation you want to perform\n");
    printf("1. Deletion_at_begining\n");
    printf("2. Deletion_at_loc\n");
    printf("3. Deletion_at_the_end\n");
    printf("Enter your choice: ");
    scanf("%d", &delete_choice);
}

void searching_choice(){
    printf("\n");
    printf("What searching algorithm you want to perform\n");
    printf("1. Linear search\n");
    printf("2. Binary search\n");
    printf("Enter your choice: ");
    scanf("%d", &search_choice);
    printf("\n");

}

bool isarraysorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void traversal(int arr[], int size)
{
    if (size == 0)
    {
        printf("\nArray is empty\n");
    }
    else
    {
        printf("Array elements: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int insertion_at_beg(int arr[], int size, int length){
    int element;
    if (size < length)
    {
        
        printf("Enter the element: ");
        scanf("%d", &element);
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
        size++;
    }
    else
    {
        printf("Array is full, cannot insert.\n");
    }
    return size;
}
int insertion_at_loc(int arr[], int size, int length)
{
    int index, element;
    if (size < length)
    {
        printf("Enter the index where you want to insert the element: ");
        scanf("%d", &index);
        printf("Enter the element: ");
        scanf("%d", &element);

        if (index >= 0 && index <= size)
        {
            for (int i = size; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
            size++;
        }
        else
        {
            printf("Invalid index!\n");
        }
    }
    else
    {
        printf("Array is full, cannot insert.\n");
    }
    return size;
}
int insertion_at_the_end(int arr[], int size, int length){
    int element;
    if (size < length)
    {
        
        printf("Enter the element: ");
        scanf("%d", &element);
        arr[size]=element;
        size++;
    }
    else
    {
        printf("Array is full, cannot insert.\n");
    }
    return size;
}
int deletion_at_beg(int arr[], int size){
    if(size > 0){
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    else{
        printf("Array is empty. Cannot delete.\n");
    }
    return size;
}
int deletion_at_loc(int arr[], int size)
{
    int index;
    if (size > 0)
    {
        printf("Enter the index you want to delete element from: ");
        scanf("%d", &index);

        if (index >= 0 && index < size)
        {
            for (int i = index; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
        }
        else
        {
            printf("Invalid index!\n");
        }
    }
    else
    {
        printf("Array is empty. Cannot delete.\n");
    }
    return size;
}
int deletion_at_the_end(int arr[], int size){
     if(size > 0){
        size--;
    }
    else{
        printf("Array is empty. Cannot delete.\n");
    }
    return size;
}
void linear_search(int arr[],int size,int number){
    for(int i=0; i<size; i++){
        if(number==arr[i]){
            printf("Element found at index --> %d\n", i);
        }
    }
    printf("Element not found.\n");
}
void binary_search(int arr[],int low,int high,int number){
    
    if (!isarraysorted(arr, high)){
        printf("Array is not sorted");
    }
    while (low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==number){
        printf("Element found at index --> %d\n", mid);
        return;
    }
    else if(arr[mid]<number){
        binary_search(arr,low,mid-1,number);

    }
    else{
        binary_search(arr,mid+1,high,number);
    }
    }
    
        printf("Element not found.\n");
    
}
void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Array sorted using insertion sort.\n");
}
int main()
{
    

    printf("How many elements do you want to enter (up to 10)? ");
    scanf("%d", &size);
    length=size;
    for (int i = 0; i < size; i++)
    {
        printf("Enter element at index %d -> ", i);
        scanf("%d", &arr[i]);
    }

    choose_operation();
    while (b == 1)
    {
        
        if (choice == 1)
        {
            // Traversal
            traversal(arr, size);
            choose_operation();
        }
        else if (choice == 2)
        {
            // Insertion
            insertion_choice();
            if(insert_choice==1){
                size=insertion_at_beg(arr,size,length);
            }
            else if(insert_choice==2){
                size = insertion_at_loc(arr, size, length);
            }
            else if(insert_choice==3){
                size = insertion_at_the_end(arr,size,length);
            }
            else{
                printf("Invalid choice!\n");
                insertion_choice();
            }
            traversal(arr, size);
            choose_operation();
        }
        else if (choice == 3)
        {
            // Deletion
            deletion_choice();
            if(delete_choice==1){
                size=deletion_at_beg(arr,size);
            }
            else if(delete_choice==2){
                size = deletion_at_loc(arr, size);
            }
            else if(delete_choice==3){
                size = deletion_at_the_end(arr,size);
            }
            else{
                printf("Invalid choice!\n");
                deletion_choice();
            }
            traversal(arr, size);
            choose_operation();
        }
        else if (choice == 4)
        {
            searching_choice();
            if(search_choice==1){
                int element;
                printf("Enter the element: ");
                scanf("%d", &element);
                linear_search(arr,size,element);
            }
            else if(search_choice==2){
                int element;
                printf("Enter the element: ");
                scanf("%d", &element);
                binary_search(arr,0,size-1,element);
            }
            else{
                printf("Invalid choice!\n");
                searching_choice();
            }
            traversal(arr, size);
            choose_operation();
        }
        else if (choice == 5)
        {
            int num;
            insertion_sort(arr,size);
            traversal(arr, size);
            choose_operation();
        }
        else
        {
            printf("Invalid choice!\n");
            choose_operation();
        }
    }
    
}