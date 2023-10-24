#include <stdio.h>

// 1---> Swap  using pointers
void swapWithPointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// 2--->Swap using +,-
void swapWithAddSub(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

// 3---> Swap  bitwise XOR
void swapWithXOR(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Original values: x = %d, y = %d\n", x, y);

    // 1---> Swap with pointers
    swapWithPointers(&x, &y);
    printf("After swapping with pointers: x = %d, y = %d\n", x, y);



    // 2---> Swap with addition and subtraction
    swapWithAddSub(&x, &y);
    printf("After swapping with addition and subtraction: x = %d, y = %d\n", x, y);


    // 3---> Swap with  XOR
    swapWithXOR(&x, &y);
    printf("After swapping with  XOR: x = %d, y = %d\n", x, y);

    return 0;
}
