#include <iostream>
using namespace std;

int b = 1;
int choice;

int choose_operation()
{
    cout << endl;
    cout << "1. traversal" << endl;
    cout << "2. insertion" << endl;
    cout << "3. deletion" << endl;
    cout << "4. sorting" << endl;
    cout << "5. searching" << endl;
    cin >> choice;
    return choice;
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
        cout << endl
             << "Array is empty" << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int insertion(int arr[], int size, int length)
{
    int index, element;
    if (size < length)
    {
        cout << "Enter the index where you want to insert the element: ";
        cin >> index;
        cout << "Enter the element: ";
        cin >> element;

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
            cout << "Invalid index!" << endl;
        }
    }
    else
    {
        cout << "Array is full, cannot insert." << endl;
    }
    return size;
}

int deletion(int arr[], int size)
{
    int index;
    if (size > 0)
    {
        cout << "Enter the index you want to delete element from: ";
        cin >> index;

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
            cout << "Invalid index!" << endl;
        }
    }
    else
    {
        cout << "Array is empty. Cannot delete." << endl;
    }
    return size;
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
}

void binarySearch(int arr[], int low, int high, int number)
{
    if (!isarraysorted(arr, high))
    {
        cout << "Array is not sorted." << endl;
        return;
    }

    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == number)
        {
            cout << "Element found at index -->" << mid << endl;
            return;
        }
        else if (number > arr[mid])
        {
            binarySearch(arr, mid + 1, high, number);
        }
        else
        {
            binarySearch(arr, low, mid - 1, number);
        }
    }
    else
    {
        cout << "Element not found." << endl;
    }
}

int main()
{
    int arr[10];
    int length = 10;
    int size;

    cout << "How many elements do you want to enter (up to 10)? ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at index " << i << "-> ";
        cin >> arr[i];
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
            size = insertion(arr, size, length);
            choose_operation();
        }
        else if (choice == 3)
        {
            // Deletion
            size = deletion(arr, size);
            choose_operation();
        }
        else if (choice == 4)
        {
            // Insertion Sort
            insertion_sort(arr, size);
            choose_operation();
        }
        else if (choice == 5)
        {
            // Binary Search
            int num;
            cout << "Enter the number you want to search: ";
            cin >> num;
            binarySearch(arr, 0, size - 1, num);
            choose_operation();
        }
        else
        {
            cout << "Invalid choice!" << endl;
            choose_operation();
        }
    }
}
