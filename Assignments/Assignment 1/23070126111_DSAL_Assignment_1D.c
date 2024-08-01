// 1D. Problem: Write a C program to find the index of a target word in a sorted array of words. 
// The array is sorted in lexicographic (dictionary) order. Your program should perform a binary 
// search to find the index of the target word in the array, if it exists. If the target word is 
// not present in the array, your program should return -1.

#include <stdio.h>
#include <string.h>

int binarySearch(char arr[][100], int low, int high, char* target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(arr[mid], target);
        
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    char words[][100] = {"apple", "banana", "cherry", "grape", "orange"};
    int size = sizeof(words) / sizeof(words[0]);
    char target[100];
    
    printf("Enter the target word: ");
    scanf("%s", target);
    
    int index = binarySearch(words, 0, size - 1, target);
    
    if (index == -1) {
        printf("Target word not found.\n");
    } else {
        printf("Target word found at index %d.\n", index);
    }
    
    return 0;
}

// Algorithm

// 1. Implement a binary search function that takes the array of words, the low and high indices, and the target word as parameters.
// 2. Compare the target word with the middle element of the array.
// 3. If the target word matches the middle element, return the index.
// 4. If the target word is lexicographically greater than the middle element, search in the right half of the array.
// 5. If the target word is lexicographically smaller than the middle element, search in the left half of the array.
// 6. Repeat the process until the target word is found or the low index is greater than the high index.
// 7. If the target word is not found, return -1.

// Complexity Analysis

// The time complexity for this approach is O(log n), where n is the size of the array. We perform a binary search to find the target word in the sorted array. The space complexity is O(1) as we only use a constant amount of extra space.