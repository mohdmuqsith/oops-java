#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], unique[n], size = 0;
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        int duplicate = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == unique[j]) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) unique[size++] = arr[i];
    }

    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < size; i++) printf("%d ", unique[i]);
    printf("\n");
    return 0;
}
