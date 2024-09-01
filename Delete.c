#include <stdio.h>

int main() {
    int n, i, pos;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the position of element to delete: ");
    scanf("%d", &pos);
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("Array after deletion:\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
