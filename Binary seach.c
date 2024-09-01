#include <stdio.h>

int main() {
    int n, i, search, mid, low, high, found = 0;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &search);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == search) {
            printf("Element %d found at position %d.\n", search, mid + 1);
            found = 1;
            break;
        } else if (arr[mid] < search) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", search);
    }

    return 0;
}
