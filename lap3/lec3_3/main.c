#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the number of elements in the array: ");

    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    if (n <= 0) {
        printf("The number of elements must be a positive integer.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            return 1;
        }
    }

    printf("The array elements are:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
