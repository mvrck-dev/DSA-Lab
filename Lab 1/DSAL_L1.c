#include <stdio.h>

int firstMissingNumber(int A[], int n)
{
    int present[n + 1];
    for (int i = 0; i <= n; i++)
        present[i] = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n)
            present[A[i]] = 1;
    }

    for (int i = 1; i <= n; i++)
        if (!present[i])
            return i;

    return n + 1;
}

int main()
{
    int arr[] = { -1, 1, 3, 4, 6 , 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d", firstMissingNumber(arr, size));
}
