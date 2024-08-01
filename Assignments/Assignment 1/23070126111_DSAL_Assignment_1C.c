// C. Problem: Write a C program to find the smallest missing positive integer from a sorted array of
// integers. The array may contain duplicates and negative numbers, but it is guaranteed to be sorted in
// ascending order. Your program should return the smallest missing positive integer not present in the array.

#include <stdio.h>

int findSmallestMissingPositive(int arr[], int size) {
    int smallestMissing = 1; // Initialize the smallest missing positive integer to 1
    
    for (int i = 0; i < size; i++) {
        // Ignore negative numbers and duplicates
        if (arr[i] <= 0 || (i > 0 && arr[i] == arr[i-1])) {
            continue;
        }
        
        // Check if the current element is the smallest missing positive integer
        if (arr[i] != smallestMissing) {
            return smallestMissing;
        }
        
        smallestMissing++;
    }
    
    return smallestMissing;
}

int main() {
    int arr[] = {-4, -2, 0, 1, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int smallestMissing = findSmallestMissingPositive(arr, size);
    
    printf("The smallest missing positive integer is: %d\n", smallestMissing);
    
    return 0;
}


// Algorithm
// 1. Initialize the smallest missing positive integer to 1.
// 2. Iterate through the sorted array.
// 3. Ignore negative numbers and duplicates.
// 4. Check if the current element is the smallest missing positive integer.
// 5. If not, return the smallest missing positive integer.
// 6. If all elements are present, return the next positive integer after the maximum element.

// Complexity Analysis
// The time complexity for this approach is O(n), where n is the size of the array. We iterate through the array once to find the smallest missing positive integer. The space complexity is O(1) as we only use a constant amount of extra space.



// Input : {-4, -2, 0, 1, 2, 4, 5}
// Output : The smallest missing positive integer is: 3