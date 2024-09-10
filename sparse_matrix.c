#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int traversal(int **arr, int rows, int cols)
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
{
    int zeros = 0;
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
    if (zeros <= (rows * cols) / 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void sparse_reprsentation(int **arr, int rows, int cols)
{
    int size = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] != 0)
                size++;

    int **new_matrix = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        new_matrix[i] = (int *)malloc(size * sizeof(int));
    }

    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] != 0)
            {
                new_matrix[0][k] = i;
                new_matrix[1][k] = j;
                new_matrix[2][k] = arr[i][j];
                k++;
            }

    traversal(new_matrix, 3, size);
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
        printf("\tAnd this is its sparse representation\n");
        sparse_reprsentation(arr, rows, cols);
    }
    else
    {
        printf("It is not a sparse matrix");
    }
    return 0;
    }
}