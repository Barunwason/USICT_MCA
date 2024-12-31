#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int zeros = 0;
int size = 0;
void traversal(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            printf("\t%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
bool is_matrix_sparse(int **arr, int rows, int cols)
{   zeros = 0;
    
    if (rows == 1 && cols == 1)
    {
        if (arr[rows - 1][cols - 1] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 0)
            {
                zeros++;
            }
        }
    }
    if (zeros > (rows * cols)*(3.0 / 4.0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void sparse_reprsentation(int **arr, int rows, int cols)
{
    
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] != 0)
                size++;

    int **new_matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        new_matrix[i] = (int *)malloc(3* sizeof(int));
    }

    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] != 0)
            {
                new_matrix[k][0] = i;
                new_matrix[k][1] = j;
                new_matrix[k][2] = arr[i][j];
                k++;
            }

    traversal(new_matrix, size, 3);
}

int main()
{
    int rows;
    int cols;
    printf("Enter the number of rows you want ");
    scanf("%d", &rows);
    printf("Enter the number of cols you want ");
    scanf("%d", &cols);
    if (rows != cols)
    {
        printf("Rows and Columns should be same");
        return 0;
    }
    else{
    printf("rows --> %d\ncols --> %d\n", rows, cols);

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter the element at index %d%d --> ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    traversal(arr, rows, cols);
    if (is_matrix_sparse(arr, rows, cols))
    {
        printf("It is a sparse matrix\n");
        
        printf("\tAnd this is its sparse representation\n\n");
        printf("\tRows\t\tCols\t\tValue\n");
        sparse_reprsentation(arr, rows, cols);
        printf("Zero values --> %d\n",zeros);
        printf("Non Zero values --> %d",size);
    }
    else
    {
        printf("It is not a sparse matrix");
    }
    return 0;
    }
}