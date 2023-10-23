#include <stdio.h>
#include <stdlib.h>


//- Calculate average of each column in a 2D Array.


int main() {
    int rows, cols;

  // row - col
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    // elements
    printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // average of each column
    printf("Average of each column:\n");
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += arr[i][j];
        }
        double average = (double)sum / rows;
        printf("Column %d: %.2f\n", j + 1, average);
    }

    return 0;
}



