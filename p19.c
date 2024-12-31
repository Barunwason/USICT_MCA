#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int arr[MAX];
int size, choice;

void choose_operation()
{
    printf("\nMenu:\n");
    printf("1. Heap Sort\n");
    printf("2. Counting Sort\n");
    printf("3. Radix Sort\n");
    printf("4. Bucket Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
}

// Function to swap elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heap Sort functions
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i +1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


void countingSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int k = 0;
    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            arr[k++] = i;
            count[i]--;
        }
    }

    free(count);
}


void countingSortForRadix(int arr[], int n, int exp)
{
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}

void radixSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortForRadix(arr, n, exp);
}


void bucketSort(int arr[], int n)
{
    if (n <= 0)
        return;

    int i;
    float min = arr[0], max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int bucketCount = (int)(max - min) / n + 1;
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));

    for (i = 0; i < bucketCount; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucketSizes[i] = 0;
    }


    for (i = 0; i < n; i++)
    {
        int index = (int)((arr[i] - min) * (bucketCount - 1) / (max - min));
        buckets[index][bucketSizes[index]++] = arr[i];
    }
    int k = 0;
    for (i = 0; i < bucketCount; i++)
    {
        if (bucketSizes[i] > 0)
        {
            int bucketSize = bucketSizes[i];
            for (int j = 0; j < bucketSize - 1; j++)
            {
                for (int l = j + 1; l < bucketSize; l++)
                {
                    if (buckets[i][j] > buckets[i][l])
                    {
                        swap(&buckets[i][j], &buckets[i][l]);
                    }
                }
            }

            for (int j = 0; j < bucketSize; j++)
            {
                arr[k++] = buckets[i][j];
            }
        }
    }

    // Free the memory allocated for buckets
    for (i = 0; i < bucketCount; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Traversal function to print the array
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

// Main function
int main()
{
    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Input the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter element at index %d -> ", i);
        scanf("%d", &arr[i]);
    }

    // Menu-driven approach
    while (1)
    {
        choose_operation();
        if (choice == 1)
        {
            heapSort(arr, size);
            printf("Array after Heap Sort: ");
            traversal(arr, size);
        }
        else if (choice == 2)
        {
            countingSort(arr, size);
            printf("Array after Counting Sort: ");
            traversal(arr, size);
        }
        else if (choice == 3)
        {
            radixSort(arr, size);
            printf("Array after Radix Sort: ");
            traversal(arr, size);
        }
        else if (choice == 4)
        {
            bucketSort(arr, size);
            printf("Array after Bucket Sort: ");
            traversal(arr, size);
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
