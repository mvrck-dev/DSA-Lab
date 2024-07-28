// Write a C program to find the smallest missing positive integer from a sorted array of integers. 
// The array may contain duplicates and negative numbers, but it is guaranteed to be sorted in ascending order. 
// Your program should return the smallest missing positive integer not present in the array.

// Write a funtion int find smallest missing posotive(int arr[], int size) that takes the followign paramerters:alignas

// arr: a sorted array of inteegers
// size: the number of elements in an array

// Objective: This function should return the smalllest missing positive integer.


#include <stdio.h>

int find_smallest_missing_positive(int arr[], int size) {
    int smallest_missing = 1; // Initialize the smallest missing positive integer as 1
    
    for (int i = 0; i < size; i++) {
        // Ignore negative numbers and duplicates
        if (arr[i] <= 0 || (i > 0 && arr[i] == arr[i-1])) {
            continue;
        }
        
        // Check if the current element is the smallest missing positive integer
        if (arr[i] != smallest_missing) {
            return smallest_missing;
        }
        
        smallest_missing++; // Increment the smallest missing positive integer
    }
    
    return smallest_missing; // If all positive integers are present, return the next positive integer
}

int main() {
    // int arr[] = {-4, -2, 0, 1, 2, 4, 5};

    int arr[] = {4, 5, 5, 2, -4, 0, 1, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int smallest_missing = find_smallest_missing_positive(arr, size);
    printf("The smallest missing positive integer is: %d\n", smallest_missing);
    
    return 0;
}


// Algorithm

// 1. Initialize the smallest missing positive integer as 1.
// 2. Iterate through the array.
// 3. Ignore negative numbers and duplicates.
// 4. Check if the current element is the smallest missing positive integer.
// 5. If the current element is not equal to the smallest missing positive integer, return the smallest missing positive integer.
// 6. Increment the smallest missing positive integer.
// 7. If all positive integers are present, return the next positive integer.
// 8. The time complexity of this algorithm is O(n), where n is the number of elements in the array.
// 9. The space complexity of this algorithm is O(1) as it uses a constant amount of extra space.
// 10. The algorithm works by iterating through the array and checking if the current element is the smallest missing positive integer. If the current element is not equal to the smallest missing positive integer, it returns the smallest missing positive integer. If all positive integers are present, it returns the next positive integer.
// 11. The algorithm handles negative numbers and duplicates by ignoring them during the iteration.


