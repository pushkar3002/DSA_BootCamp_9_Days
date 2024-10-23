#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, key, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n\n*** Search Menu ***\n");
        printf("1. Linear Search\n2. Binary Search\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                int linearResult = linearSearch(arr, n, key);
                if (linearResult != -1) {
                    printf("Element found at index: %d\n", linearResult);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 2:
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Enter the element to search: ");
                scanf("%d", &key);
                int binaryResult = binarySearch(arr, 0, n - 1, key);
                if (binaryResult != -1) {
                    printf("Element found at index: %d\n", binaryResult);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
