#define MAX 101 /* max number of elements + 1 */
#define TABLE printf("ROW\tCOL\tVAL\n")
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} element;

void printSparseMatrix(element *a) {
    TABLE;
    for (int i = 1; i <= a[0].value; i++)
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
}

element *createSparseMatrix() {
    element *matrix = malloc(MAX * sizeof(element));
    printf("Enter the number of rows and columns of the matrix : ");
    scanf("%d %d", &matrix[0].row, &matrix[0].col);
    printf("Enter the non zero elements of the matrix : ");
    scanf("%d", &matrix[0].value);
    TABLE;
    for (int i = 1; i <= matrix[0].value; i++)
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    matrix = realloc(matrix, (matrix[0].value + 1) * sizeof(element));
    return matrix;
}

element *transposeSparse(element *a) {
    element *c = (element *)malloc(sizeof(element) * (a[0].row * a[0].col + 1));
    c[0].row = a[0].col;
    c[0].col = a[0].row;
    c[0].value = a[0].value;
    for (int i = 1; i <= a[0].value; i++) {
        c[i].row = a[i].col;
        c[i].col = a[i].row;
        c[i].value = a[i].value;
    }
    return c;
}

element *additionSparse(element *a, element *b) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("ERROR : Incompatible matrices for addition\n");
        exit(EXIT_FAILURE);
    }
    element *c = (element *)malloc(sizeof(element) * (a[0].row * b[0].col + 1));
    c[0].row = a[0].row;
    c[0].col = a[0].col;
    c[0].value = 0;
    for (int i = 1; i <= a[0].row; i++) {
        for (int j = 1; j <= a[0].col; j++) {
            int elem = 0;
            for (int k = 1; k <= a[0].value; k++) {
                if ((a[k].row == i && a[k].col == j) ||
                    (b[k].row == i && b[k].col == j)) {
                    elem += (a[k].row == i && a[k].col == j) ? a[k].value : 0;
                    elem += (b[k].row == i && b[k].col == j) ? b[k].value : 0;
                }
            }
            if (elem != 0) {
                c[0].value++;
                c[c[0].value].row = i;
                c[c[0].value].col = j;
                c[c[0].value].value = elem;
            }
        }
    }
    return c;
}

element *mutiplySparse(element *a, element *b) {
    if (a[0].col != b[0].row) {
        printf("Incompatible matrices for multiplication\n");
        exit(EXIT_FAILURE);
    }
    element *c = (element *)malloc(sizeof(element) * (a[0].row * b[0].col + 1));
    c[0].row = a[0].row;
    c[0].col = b[0].col;
    c[0].value = 0;
    for (int i = 1; i <= a[0].row; i++) {
        int row[a[0].col];
        for (int k = 0; k < a[0].col; k++)
            row[k] = 0;
        for (int j = 1; j <= a[0].value; j++) {
            if (a[j].row == i) {
                row[a[j].col - 1] = a[j].value;
            }
        }

        for (int m = 1; m <= b[0].col; m++) {
            int col[b[0].row];
            for (int k = 0; k < b[0].row; k++)
                col[k] = 0;
            for (int j = 1; j <= b[0].value; j++) {
                if (b[j].col == m) {
                    col[b[j].row - 1] = b[j].value;
                }
            }

            int sum = 0;
            for (int l = 0; l < a[0].col; l++)
                sum += row[l] * col[l];
            if (sum != 0) {
                c[0].value++;
                c[c[0].value].row = a[i].row;
                c[c[0].value].col = b[i].col;
                c[c[0].value].value = sum;
            }
        }
    }

    return c;
}

int main(void) {
    element *a, *b, *c;
    a = createSparseMatrix();
    c = transposeSparse(a);

    // print A
    printf("Matrix A is represented as :\n");
    printSparseMatrix(a);

    b = createSparseMatrix();

    // print B
    printf("Matrix B is represented as :\n");
    printSparseMatrix(b);

    // transpose of A
    printf("\nTranspose(A) is represented as :\n");
    printSparseMatrix(c);

    // addition of A and B
    printf("\nAddition of A and B is represented as :\n");
    free(c);
    c = additionSparse(a, b);
    printSparseMatrix(c);

    // multiplication of A and B
    free(c);
    c = mutiplySparse(a, b);
    printf("\nProduct of A and B is represented as :\n");
    printSparseMatrix(c);

    return 0;
}