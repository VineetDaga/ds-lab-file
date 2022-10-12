#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int column;
    int value;
} element;

typedef struct
{
    element **data;
    int rows;
    int columns;
    int terms;
} sparse;

element **generateSparseData(int n, int m, int arr[n][m], sparse *matrix)
{
    element **sparseMatrix = (element **)malloc(sizeof(element *) * n * m);
    int non_zero = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 0)
            {
                element *elem = (element *)malloc(sizeof(element));
                elem->row = i;
                elem->column = j;
                elem->value = arr[i][j];
                sparseMatrix[non_zero] = elem;
                non_zero++;
            }
        }
    }
    sparseMatrix = (element **)realloc(sparseMatrix, sizeof(element *) * non_zero);
    matrix->terms = non_zero;
    return sparseMatrix;
}

sparse *generateSparseMatrix(int rows, int columns, int arr[rows][columns])
{
    sparse *matrix = (sparse *)malloc(sizeof(sparse));
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->data = generateSparseData(rows, columns, arr, matrix);
    return matrix;
}

void printSparseMatrix(sparse *sparseMatrix)
{
    int arr[sparseMatrix->rows][sparseMatrix->columns];
    for (int i = 0; i < sparseMatrix->rows; i++)
    {
        for (int j = 0; j < sparseMatrix->columns; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < sparseMatrix->terms; i++)
    {
        element *elem = (element *)sparseMatrix->data[i];
        if (elem != NULL)
        {
            arr[elem->row][elem->column] = elem->value;
        }
    }
    for (int i = 0; i < sparseMatrix->rows; i++)
    {
        for (int j = 0; j < sparseMatrix->columns; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[5][4] = {{7, 0, 3, 0},
                     {0, 4, 0, 9},
                     {-5, 7, 0, 0},
                     {0, 2, 0, 0},
                     {12, 0, -2, 0}};

    sparse *sparseMatrix = generateSparseMatrix(5, 4, arr);
    printf("Generated Sparse Matrix :\n");
    printSparseMatrix(sparseMatrix);
    return 0;
}